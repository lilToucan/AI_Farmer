#pragma once

#include "CoreMinimal.h"
#include "Structs/FObjectPool.h"
#include "Subsystems/WorldSubsystem.h"
#include "ObjectPoolingSubsystem.generated.h"


class IPoolable;

UCLASS()
class AI_FARMER_API UObjectPoolingSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Object Pool Subsystem")
	TMap<TSubclassOf<AActor>, FObjectPool> ObjectPoolMap;

	UFUNCTION(BlueprintCallable, Category = "Object Pool Subsystem")
	void AddPool(TSubclassOf<AActor> ActorClass, int32 InitialSize = 50);

	UFUNCTION(BlueprintCallable, Category = "Object Pool Subsystem")
	TScriptInterface<IPoolable> GetActor(TSubclassOf<AActor> ActorClass);

	UFUNCTION(BlueprintCallable, Category = "Object Pool Subsystem")
	void ReturnActorToPool(TSubclassOf<AActor> ActorClass, TScriptInterface<IPoolable> ActorToReturn);
	
};
