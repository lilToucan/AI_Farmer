// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Poolable.generated.h"

UINTERFACE()
class UPoolable : public UInterface
{
	GENERATED_BODY()
};

class AI_FARMER_API IPoolable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Activate();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Deactivate();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetTransform(FVector Position, FRotator Rotation = FRotator(0.0F, 0.0F, 0.0F), FVector Scale = FVector(1,1,1));
	
};
