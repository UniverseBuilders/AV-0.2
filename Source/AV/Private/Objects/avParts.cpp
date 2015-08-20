// Fill out your copyright notice in the Description page of Project Settings.

#include "AV.h"
#include "avParts.h"


// Sets default values
AavParts::AavParts()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AavParts::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AavParts::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

