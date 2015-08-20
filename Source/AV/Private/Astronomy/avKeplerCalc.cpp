// Fill out your copyright notice in the Description page of Project Settings.

#include "AV.h"
#include "avKeplerCalc.h"

#define PI (3.1415926535897932f)
#define G (6.67384f*pow(10.0, -11.0))

DEFINE_LOG_CATEGORY(OrbitLog);

FVector UavKeplerCalc::avFgetCartesian(FavKepDat cbKepDat, float BodyMass, float ParentMass, float adjScale, float elapsedJD){
	//MOST OF CALCULATION IS IN KEP2CART
	//GET POSITION MERELY NEEDS TO FIND THE MEAN ANOMOLY AT A GIVEN DATE, THEN GUESS THE ECCENTRIC ANOMOLY AND TRUE ANOMOLY
	//THIS THEN GETS FED INTO Kep2Cart

	//GET GAME TIME
	//float julianDate = GameState->julianDate;
	

	//GAME STARTING EPOCH
	double startingEpoch = 2460676.5; // For Jan 1 2025
	double coordEpoch = 2451696.5; //For Jan 1 2000 - "Epoch 2000"

	float julianDate = startingEpoch + elapsedJD/100.000f; //GAMESPEED LATER SHOULD MODIFY elapsedJD

	
	//LOAD BASIC PARAMS
	float Am = cbKepDat.A * 149597870691.0134; //Convert into M
	float Ec = cbKepDat.E;

	// CALCULATE n VALUE FROM MASS
	float MassConvert = (1.0f * 5.972 * pow(10.0f, 24)); //Mass from Earth Masses into KG
	float n = sqrt((G * (ParentMass * MassConvert + BodyMass * MassConvert)) / pow(Am*1.0f, 3.0f)); //n Value based on Mass

	//FINDING THE MEAN ANOMOLY AT CURRENT TIME - NEED dT in SECONDS
	float M0rad = cbKepDat.U * PI / 180.f; //Mean Anomoly at Epoch
	float MA = (M0rad+ n * (julianDate - coordEpoch) * 86164.0905);// Number of Seconds in a Sidereal Day
	

	// ## FINDING ECCENTRIC AN TRUE ANOMOLY FROM MEAN ANOMOLY
	// Estimate eccentric and true anom using iterative approximation

	// Use the Mean Anomoly as Starting Guess for Eccentric Anomoly
	double E0 = MA;
	double lastDiff;
	do {
		//double E1 = M + Ec * sinf(E0);
		//double E1 = E0 - ((E0 - Ec*sin(E0) - M) / (1 - Ec*cos(E0)));
		double E1 = MA + Ec * sinf(E0);
		lastDiff = abs(E0 - E1);
		E0 = E1;

	} while (lastDiff > 0.001f);

	float EA = E0;

	//TRUE ANOMOLY - sometimes equations refer to this as v or nu - I'm just using TA to be clear
	float TA = -2.0f * atan(sqrt((1.0f + Ec ) / (1.0f - Ec)) * tan(EA / 2.0f));

	//float MAdeg = fmodf(MA, 360.0f);
	//float EAdeg = fmodf(EA, 360.0f);
	/*
	UE_LOG(OrbitLog, Warning, TEXT("Orbit ParentMass %f"), ParentMass);// , elapsedJD, M, EA, TA);
	UE_LOG(OrbitLog, Warning, TEXT("Orbit Body Mass %f"), BodyMass);
	UE_LOG(OrbitLog, Warning, TEXT("Orbit ElapsedJD %f"), elapsedJD/100.0f);
	UE_LOG(OrbitLog, Warning, TEXT("Orbit Mean Motion - n %f"), n);
	UE_LOG(OrbitLog, Warning, TEXT("Orbit Mean Anomoly - MA %f"), MA);
	UE_LOG(OrbitLog, Warning, TEXT("Orbit Eccentric Anomoly - EA %f"), EA);
	UE_LOG(OrbitLog, Warning, TEXT("Orbit True Anomoly - TA %f"), TA);
	*/

	FVector PosAtTime = Kep2Cart(cbKepDat, adjScale, TA);

	return PosAtTime;

}

TArray<FVector> UavKeplerCalc::avFgetArray(FavKepDat cbKepDat, float adjScale, int32 ArrayDefinition){
	//Placeholder Array for running loop
	TArray<FVector> GeneratedArray;

	//GET THE TICK AMOUNT FOR ONE ANGLE SEGMENT
	float M = (1.0f / ArrayDefinition) * PI / 180.f;

	for (int i = 0; i < ArrayDefinition - 1; i++)
	{
		//GeneratedArray.Add(FVector(a, a, a));
		float TAm = M * i;
		FVector PosAtM = Kep2Cart(cbKepDat, adjScale, TAm);
		GeneratedArray.Add(PosAtM);
	}

	return GeneratedArray;
}

FVector UavKeplerCalc::avFgetOrbitPoint(FavKepDat cbKepDat, float adjScale, float TAstatic)
{
	FVector PosAtTA = Kep2Cart(cbKepDat, adjScale, TAstatic);
	return PosAtTA;
}

FVector UavKeplerCalc::Kep2Cart(FavKepDat cbKepDat, float adjScale, float TA){

	//float GameScale = GameState->gameScale;

	//CONVERT SEMI-MAJOR AXIS INTO M
	float Am = cbKepDat.A * 149597870691.0134; //Convert into M

	//LOAD OTHER VARS
	float Ec = cbKepDat.E;

	// CONVERTING ANGLES TO RADIANS
	float Irad = cbKepDat.I * PI / 180.f; //Inclination
	float Orad = cbKepDat.O * PI / 180.f; //Omega - long of Ascending Node
	float Wrad = cbKepDat.W * PI / 180.f; //Argument of Perihelion
	float W_BAR = Wrad + Orad; //Longitude of Perihelion

	//SHOULD U BE SOMETHING ELSE?
	float M0rad = cbKepDat.U * PI / 180.f; //Mean Anomoly

	// Radius vector, in AU
	double R = Am * adjScale * (1.0f - Ec * Ec) / (1.0f + Ec * cos(TA)) / 149597870691.0134; // M back to AU

	// CARTESIAN COORDINATES - GENERIC HELIOCENTRIC STATIONARY REFERENCE FRAME
	float X = R * (cos(Orad) * cos(TA + Wrad) - sin(Orad) * sin(TA + Wrad) * cos(Irad));
	float Y = R * (sin(Orad) * cos(TA + Wrad) + cos(Orad) * sin(TA + Wrad) * cos(Irad));
	float Z = R * sin(TA + Wrad) * sin(Irad);

	return FVector(X, Y, Z);
}