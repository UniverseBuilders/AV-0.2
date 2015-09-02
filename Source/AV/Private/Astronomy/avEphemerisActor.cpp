// Fill out your copyright notice in the Description page of Project Settings.

#include "AV.h"
#include "avEphemerisActor.h"


// Sets default values
AavEphemerisActor::AavEphemerisActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AavEphemerisActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AavEphemerisActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

