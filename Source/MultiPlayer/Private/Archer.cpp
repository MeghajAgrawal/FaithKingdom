// Fill out your copyright notice in the Description page of Project Settings.


#include "Archer.h"
<<<<<<< Updated upstream
=======
#include "Bow.h"
>>>>>>> Stashed changes

// Sets default values
AArcher::AArcher()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AArcher::BeginPlay()
{
	Super::BeginPlay();
<<<<<<< Updated upstream
	
=======
	Bow = GetWorld()->SpawnActor<ABow>(BowClass);
	Bow->AttachToComponent(GetMesh(),FAttachmentTransformRules::KeepRelativeTransform,TEXT("LeftHandSocket"));
	Bow->SetOwner(this);
>>>>>>> Stashed changes
}

// Called every frame
void AArcher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AArcher::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

<<<<<<< Updated upstream
}
=======
	PlayerInputComponent->BindAxis(TEXT("MoveForward"),this,&AArcher::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"),this,&APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"),this,&AArcher::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"),this,&APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"),EInputEvent::IE_Pressed, this ,&ACharacter::Jump);

}

void AArcher::MoveForward(float AxisValue) 
{
	AddMovementInput(GetActorForwardVector()*AxisValue);
}
void AArcher::MoveRight(float AxisValue) 
{
	AddMovementInput(GetActorRightVector()*AxisValue);
}
/*void AArcher::LookUp(float AxisValue) 
{
	AddControllerPitchInput(AxisValue);
}*/
void AArcher::Jump(float AxisValue) 
{
	
}




>>>>>>> Stashed changes

