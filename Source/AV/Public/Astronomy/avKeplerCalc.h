// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "avDataStructs.h"
#include "avGameState.h"
#include "avKeplerCalc.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(OrbitLog, Log, All);
/**
 * 
 */
UCLASS()
class AV_API UavKeplerCalc : public UObject
{
	GENERATED_BODY()

private:
	AavGameState* GameState;
	static FVector Kep2Cart(FavKepDat cbKepDat, float adjScale, float TA);

public:

	//Create BP callable function to control the planet/moon orbit
	UFUNCTION(BlueprintCallable, Blueprintpure, Category = "Astrodynamics")
		static FVector avFgetCartesian(FavKepDat cbKepDat, float BodyMass, float ParentMass, float adjScale, float elapsedJD);

	//Finds Position Regardless of Time
	UFUNCTION(BlueprintCallable, Blueprintpure, Category = "Astrodynamics")
		static FVector avFgetOrbitPoint(FavKepDat cbKepDat, float adjScale, float TAstatic);
	
	//Generates a Vector Array (doesn't seem to be working)?
	UFUNCTION(BlueprintCallable, Blueprintpure, Category = "Astrodynamics")
		static TArray<FVector> avFgetArray(FavKepDat cbKepDat, float adjScale, int32 ArrayDefinition);

};
