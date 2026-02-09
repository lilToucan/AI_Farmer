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
	
}



