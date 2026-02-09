#pragma once

#include "Interfaces/Poolable.h"
#include "FObjectPool.generated.h"

USTRUCT(BlueprintType)
struct FObjectPool
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "object to Pool")
	TArray<TScriptInterface<IPoolable>> ActivePoolingObjects;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "object to Pool")
	TArray<TScriptInterface<IPoolable>> InactivePoolingObjects;
};