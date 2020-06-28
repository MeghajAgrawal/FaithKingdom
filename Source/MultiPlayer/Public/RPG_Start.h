// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "RPG_Start.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API URPG_Start : public UGameInstance
{
	GENERATED_BODY()
public:
	URPG_Start(const FObjectInitializer & ObjectInitializer);

	virtual void Init();
	
	UFUNCTION(BlueprintCallable)
	void LoadMenu();

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& Address);
private:
	TSubclassOf<class UUserWidget> MenuClass;
};
