// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "avPlayerController.generated.h"


USTRUCT(BlueprintType)
struct FgameSpeedVars
{
	GENERATED_USTRUCT_BODY()

		//Define all Keplerian Orbit Elements
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Speeds")
		float Speed1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Speeds")
		float Speed2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Speeds")
		float Speed3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Speeds")
		float Speed4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Speeds")
		float Speed5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Speeds")
		float Speed6;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Speeds")
		float Speed7;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Speeds")
		float Speed8;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Speeds")
		float AveragedSpeed;
};
/**
 * 
 */
UCLASS()
class AV_API AavPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Speed")
	FgameSpeedVars GameSpeedEnums;
	
	
};
