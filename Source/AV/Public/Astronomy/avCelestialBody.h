// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "avDataStructs.h"
#include "avGameState.h"
#include "avCelestialBody.generated.h"

UCLASS()
class AV_API AavCelestialBody : public AActor
{
	GENERATED_BODY()

private:
	//bool initialized;
	//float Epoch;

	AavGameState* GameState;


public:	
	// Sets default values for this actor's properties
	AavCelestialBody();

	//uint16 PointResolution;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OrbitData")
		bool IsSun;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OrbitData")
		FavKepDat cbKepDat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OrbitData")
		FavBodyInfo cbBodyInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OrbitData")
		TSubclassOf<AavCelestialBody> ParentBody;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OrbitData")
		int32 OrbitArrayPrecision;

	//UPROPERTY(EditAnywhere, Category = "OrbitData")
	//		TArray<FVector> OrbitLineArray;

	//void init(cbKepData* avKepDat, cbBodyInfo* avBodyInfo, AavCelestialBody* parentBody, bool TopBodyCheck);

	//UFUNCTION(BlueprintCallable, Category = "Astrodynamics")
		//FVector GetPosition();


};
