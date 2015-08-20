// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Astronomy/avCelestialBody.h"
#include "avOrbitLineActor.generated.h"

/**
 * 
 */
UCLASS()
class AV_API AavOrbitLineActor : public AavCelestialBody
{
	GENERATED_BODY()


public:
	AavOrbitLineActor();
	//uint16 PointResolution;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category = "OrbitData")
		TArray<FVector> OrbitLineDrawArray;

	//UFUNCTION(BlueprintCallable, Blueprintpure, Category = "Orbit")
		//TArray<FVector> OrbitPointArray(AavCelestialBody* OrbitingBody, bool IsSun);

	//UFUNCTION(BlueprintCallable, Blueprintpure, Category = "Orbit")
	//void SetOrbitArray(TArray<FVector> InputVarray);
	
	//void SetOrbitArray(AavCelestialBody* CelestialBody);
	
};
