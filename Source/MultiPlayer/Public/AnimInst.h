// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimInst.generated.h"

/**
 * 
 */
UCLASS(transient, Blueprintable, hideCategories=AnimInstance, BlueprintType)
class UAnimInst : public UAnimInstance
{
	GENERATED_BODY()
public:
	UAnimInst();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic")
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic")
	bool IsInAir;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
