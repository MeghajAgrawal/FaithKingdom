// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Archer.generated.h"

<<<<<<< Updated upstream
=======
class ABow;

>>>>>>> Stashed changes
UCLASS()
class MULTIPLAYER_API AArcher : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AArcher();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

<<<<<<< Updated upstream
};
=======
private:
	void MoveForward(float AxisValue);
	//void LookUp(float AxisValue);
	void MoveRight(float AxisValue);
	//void LookRight(float AxisValue);
	void Jump(float AxisValue);

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABow> BowClass;

	UPROPERTY()
	ABow* Bow;
};





>>>>>>> Stashed changes
