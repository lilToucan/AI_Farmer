#include "Actors/PlantGrid.h"

#include "SubSystems/GridSubsystem.h"

APlantGrid::APlantGrid()
{
	PrimaryActorTick.bCanEverTick = false;
}

void APlantGrid::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetSubsystem<UGridSubsystem>()->SetGrid(this);

	FVector StartPos = GetActorLocation() - GetActorRightVector() * ((GridSpacing/2)*GridSize.X);
	
	for (int x = 0; x < GridSize.X; x++)
	{
		for (int y = 0; y < GridSize.Y; y++)
		{
			FVector Pos = StartPos + FVector(x*GridSpacing, y*GridSpacing, 0);
			GridLocations.Add(Pos);
		}
	}
	
}



