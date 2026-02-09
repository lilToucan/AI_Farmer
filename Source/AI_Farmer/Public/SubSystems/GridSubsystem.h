#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "GridSubsystem.generated.h"


class APlantGrid;

UCLASS()
class AI_FARMER_API UGridSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
 
protected:
	UPROPERTY(blueprintreadwrite)
	bool bHasGrid = false;
	UPROPERTY(blueprintreadwrite)
	APlantGrid* GridActor;

public:
	UFUNCTION(BlueprintCallable)
	APlantGrid* GetGrid() const { return GridActor; }
	UFUNCTION(BlueprintCallable)
	void SetGrid(APlantGrid* Grid);

};
