#include "SubSystems/GridSubsystem.h"

void UGridSubsystem::SetGrid(APlantGrid* Grid)
{
	GridActor = Grid;
	bHasGrid = true;
}
