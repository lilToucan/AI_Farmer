#include "AI_Farmer/Public/ActorGameplayTags.h"

AActorGameplayTags::AActorGameplayTags()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AActorGameplayTags::BeginPlay()
{
	Super::BeginPlay();
}


void AActorGameplayTags::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer = GameplayTags;
}

