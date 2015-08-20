// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "avParts.generated.h"

UCLASS()
class AV_API AavParts : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AavParts();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartData")
		float PartMass; //In KG

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartData")
		int32 EnvType; //0 = Universal, 1=Space, 2=Asteroidal, 3=Surface, 4=Floating, 5=Earth

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartData")
		bool hasThrust; //Specific Impulse in N*s/kg

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartData")
		float ISP; //Specific Impulse in N*s/kg

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PartData")
		float TSFC; //Thrust Specific Fuel Consumption in grams/(kN*S)

	
};
