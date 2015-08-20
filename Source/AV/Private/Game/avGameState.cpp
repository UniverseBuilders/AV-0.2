// Fill out your copyright notice in the Description page of Project Settings.

#include "AV.h"
#include "UnrealNetwork.h"
#include "avGameState.h"


AavGameState::AavGameState(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer) {
	this->bReplicates = true;
	
	this->daysPerSecond = 3.f;

	// Enable ticking every frame
	PrimaryActorTick.bCanEverTick = true;
	this->SetActorTickEnabled(true);
}

void AavGameState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AavGameState, julianDate);
	DOREPLIFETIME(AavGameState, daysPerSecond);
}

void AavGameState::Tick(float DeltaTime) {
	if (!HasAuthority()) {
		// Interpolate JD to remove network jitter
		this->julianDate += daysPerSecond * DeltaTime;
	}
}