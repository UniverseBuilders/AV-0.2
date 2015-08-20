// Fill out your copyright notice in the Description page of Project Settings.

#include "AV.h"
#include "avSolSysPawn.h"


// Sets default values
AavSolSysPawn::AavSolSysPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AavSolSysPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AavSolSysPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AavSolSysPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

