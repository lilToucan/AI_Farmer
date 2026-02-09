#include "ObjectPoolingSubsystem.h"

#include "Interfaces/Poolable.h"

void UObjectPoolingSubsystem::AddPool(TSubclassOf<AActor> ActorClass, int32 InitialSize)
{
	if (!GetWorld() || !ActorClass->ImplementsInterface(UPoolable::StaticClass()))
		return;

	FObjectPool NewPool = FObjectPool();
	FActorSpawnParameters SpawnParameters;

	for (int i = 0; i < InitialSize; i++)
	{
		// spawn and add it to the pool
		AActor* newActor = GetWorld()->SpawnActor<AActor>(ActorClass, SpawnParameters); 
		IPoolable::Execute_Deactivate(newActor);
		NewPool.InactivePoolingObjects.AddUnique(TScriptInterface<IPoolable>(newActor));
	}

	if (ObjectPoolMap.Contains(ActorClass))
	{
		ObjectPoolMap[ActorClass].InactivePoolingObjects.Append(NewPool.InactivePoolingObjects);
		return;
	}

	ObjectPoolMap.Add(ActorClass, NewPool);
}

TScriptInterface<IPoolable> UObjectPoolingSubsystem::GetActor(TSubclassOf<AActor> ActorClass)
{
	if (!GetWorld() || !ActorClass->ImplementsInterface(UPoolable::StaticClass()))
		return nullptr;

	if (!ObjectPoolMap.Contains(ActorClass))
	{
		AddPool(ActorClass);
	}
	FObjectPool* PoolObject = ObjectPoolMap.Find(ActorClass);

	if (PoolObject->InactivePoolingObjects.IsEmpty())
		AddPool(ActorClass, 10);

	
	TScriptInterface<IPoolable> Result = PoolObject->InactivePoolingObjects[0];
	PoolObject->InactivePoolingObjects.Remove(Result);
	
	PoolObject->ActivePoolingObjects.AddUnique(Result);
	
	return Result;
}

void UObjectPoolingSubsystem::ReturnActorToPool(TSubclassOf<AActor> ActorClass, TScriptInterface<IPoolable> ActorToReturn)
{
	if (!ObjectPoolMap.Contains(ActorClass) || !GetWorld() || !ActorClass->ImplementsInterface(UPoolable::StaticClass()))
		return;

	FObjectPool* PoolObject = ObjectPoolMap.Find(ActorClass);

	if (!PoolObject->ActivePoolingObjects.Contains(ActorToReturn))
		return;

	PoolObject->ActivePoolingObjects.Remove(ActorToReturn);
	PoolObject->InactivePoolingObjects.AddUnique(ActorToReturn);
}
