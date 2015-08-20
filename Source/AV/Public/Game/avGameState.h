// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameState.h"
#include "UnrealNetwork.h"
#include "avGameState.generated.h"

/**
 * 
 */
UCLASS()
class AV_API AavGameState : public AGameState
{
	GENERATED_BODY()

public:
	AavGameState(const FObjectInitializer &ObjectInitializer);
	
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Game Properties")
		float daysPerSecond;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Game Properties")
		float julianDate;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Game Properties")
		float gameScale;

	void Tick(float DeltaTime) override;
	
};
