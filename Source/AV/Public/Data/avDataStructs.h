// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "avDataStructs.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FavKepDat
{
	GENERATED_USTRUCT_BODY()

		//Define all Keplerian Orbit Elements
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kepler Struct")
		float A;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kepler Struct")
		float E;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kepler Struct")
		float I;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kepler Struct")
		float O;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kepler Struct")
		float W;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kepler Struct")
		float U; //=M0
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kepler Struct")
		float T;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kepler Struct")
		float Z;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kepler Struct")
		float Epoch;
};


//DEFINE STRUCT FOR PLANETARY CHARACTERISTICS
USTRUCT(BlueprintType)
struct FavBodyInfo
{
	GENERATED_USTRUCT_BODY()

		//Define Mass, Size, Atmosphere, Composition, Etc
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Body Properties")
		float Mass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Body Properties")
		float Radius; //In KM
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Body Properties")
		float RotationPeriod; //Object "Day" Length - In Earth Days
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Body Properties")
		float SurfaceGravity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Body Properties")
		float SurfacePressure;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kepler Struct")
		bool UseGravity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kepler Struct")
		bool IsSun;

	//TO-DO: ADD COMPISITION TYPE, Possibly a Composition Struct, Planet Type Stuct
};

UCLASS()
class AV_API UavDataStructs : public UObject
{
	GENERATED_BODY()
	
	
	
	
};
