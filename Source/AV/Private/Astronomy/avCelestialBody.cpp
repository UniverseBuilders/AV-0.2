// Fill out your copyright notice in the Description page of Project Settings.

#include "AV.h"
#include "avCelestialBody.h"

#define PI (3.1415926535897932f)
#define G (6.67384f*pow(10.0, -11.0))
#define scalevar (149597870691.0134)

// Sets default values
AavCelestialBody::AavCelestialBody()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AavCelestialBody::BeginPlay()
{
	Super::BeginPlay();
	//CreateArray();
	
}

// Called every frame
void AavCelestialBody::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

/*
FVector AavCelestialBody::GetPosition()
{
	
	//MOST OF CALCULATION IS IN KEP2CART
	//GET POSITION MERELY NEEDS TO FIND THE MEAN ANOMOLY AT A GIVEN DATE, THEN GUESS THE ECCENTRIC ANOMOLY AND TRUE ANOMOLY
	//THIS THEN GETS FED INTO Kep2Cart
	
	//GET GAME TIME
	float julianDate = GameState->julianDate;


	//GAME STARTING EPOCH
	double startingEpoch = 2460676.5; // For Jan 1 2025
	double coordEpoch = 2451696.5; //For Jan 1 2000 - "Epoch 2000"
	
	
	// GET INFO ABOUT GRAVITY
	float MASSbody = this->cbBodyInfo.Mass;
	bool IsTop = ParentBody->cbBodyInfo.IsSun;


	//LOAD BASIC PARAMS
	float Am = this->cbKepDat.A * scalevar;
	float Ec = this->cbKepDat.E;

	//SET THE PARENT MASS TO ZERO IF BODY IS THE SUN
	float MASSparent = 0;
	if (IsTop == true)
	{
		MASSparent = 0;
		Am = 0;
	}
	else
	{
		MASSparent = ParentBody->cbBodyInfo.Mass;
	}


	// CALCULATE n VALUE FROM MASS
	float MassConvert = (1.0f * 5.972 * pow(10.0f, 24)); //Mass from Earth Masses into KG
	float n = sqrt((G * (MASSparent * MassConvert + MASSbody * MassConvert)) / pow(Am*1.0f, 3.0f)); //n Value based on Mass

	//FINDING THE MEAN ANOMOLY AT CURRENT TIME - NEED dT in SECONDS
	float M0rad = this->cbKepDat.U * PI / 180.f; //Argument of Perihelion
	float M = M0rad + n * (julianDate + coordEpoch) * 86164.0905; //What is the 86164 in there for?


	// ## FINDING ECCENTRIC AN TRUE ANOMOLY FROM MEAN ANOMOLY
	// Estimate eccentric and true anom using iterative approximation

	// Use the Mean Anomoly as Starting Guess for Eccentric Anomoly
	double E0 = M;
	double lastDiff;
	do {
		double E1 = M + Ec * sinf(E0);
		lastDiff = abs(E1 - E0);
		E0 = E1;
	} while (lastDiff > 0.001f);

	double EA = E0;

	//TRUE ANOMOLY - sometimes equations refer to this as v or nu - I'm just using TA to be clear
	double TA = -1.0 * 2.0f * atan(sqrt((1.0f + Ec) / (1.0f - Ec)) * tan(EA / 2.0f));

	FVector PosAtTime = Kep2Cart(TA);

	return PosAtTime;
}
*/