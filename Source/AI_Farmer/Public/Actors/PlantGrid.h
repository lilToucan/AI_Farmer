#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlantGrid.generated.h"

USTRUCT()
struct FGridLocation
{
	GENERATED_BODY()
	bool bHasSeed = false;
	bool bPlantHasGrown = false;
};

UCLASS()
class AI_FARMER_API APlantGrid : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlantGrid")
	FIntVector2 GridSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlantGrid")
	float GridSpacing;

protected:
	TMap<FVector,FGridLocation> GridLocations;

public:
	APlantGrid();

protected:
	virtual void BeginPlay() override;
};
