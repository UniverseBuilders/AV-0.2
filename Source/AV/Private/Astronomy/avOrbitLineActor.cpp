// Fill out your copyright notice in the Description page of Project Settings.

#include "AV.h"
#include "avOrbitLineActor.h"

// Sets default values

AavOrbitLineActor::AavOrbitLineActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
void AavOrbitLineActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AavOrbitLineActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void AavOrbitLineActor::SetOrbitArray(AavCelestialBody* CelestialBody)
/*
void AavOrbitLineActor::SetOrbitArray(TArray<FVector> InputVarray)
{
	//AavCelestialBody* CB = CelestialBody;
	//OrbitLineDrawArray = CelestialBody->GetDefaultObject<OrbitLineArray>();
	OrbitLineDrawArray = InputVarray;
	}*/