// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInst.h"
#include "MultiPlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UAnimInst::UAnimInst()
{
    Speed = 0.0;
    IsInAir = false;
}

void UAnimInst::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);
	AActor* Owner = GetOwningActor();
    if (Owner != nullptr) {
		Speed = Owner->GetVelocity().Size();
        AMultiPlayerCharacter* OwningCharacter = Cast<AMultiPlayerCharacter>(Owner);
		if (OwningCharacter != nullptr) {
		IsInAir = OwningCharacter->GetCharacterMovement()->IsFalling();
		}
	}
}
