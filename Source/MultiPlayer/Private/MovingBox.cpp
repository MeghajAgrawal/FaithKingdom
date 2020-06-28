// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/SceneComponent.h"
#include "GameFramework/Actor.h"
#include "MovingBox.h"

AMovingBox::AMovingBox()
{
PrimaryActorTick.bCanEverTick = true;
SetMobility(EComponentMobility::Movable);
}

void AMovingBox::BeginPlay()
{
    Super::BeginPlay();

    if (HasAuthority())
    {
    SetReplicates(true);
    SetReplicateMovement(true);
    }
	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ActiveTriggers > 0)
	{
		if (HasAuthority())
		{
			FVector Location = GetActorLocation();
			float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
			float JourneyTravelled = (Location - GlobalStartLocation).Size();

			if (JourneyTravelled >= JourneyLength)
			{
				FVector Swap = GlobalStartLocation;
				GlobalStartLocation = GlobalTargetLocation;
				GlobalTargetLocation = Swap;
			}

			FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
			Location += Speed * DeltaTime * Direction;
			SetActorLocation(Location);
		}
	}
}
void AMovingBox::AddActiveTrigger()
{
	ActiveTriggers++;
}
void AMovingBox::RemoveActiveTrigger()
{
	if (ActiveTriggers > 0)
	{
		ActiveTriggers--;
	}
}
