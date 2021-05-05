// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "DestinationManager.generated.h"

class ADestination;

UCLASS(BlueprintType, Blueprintable)
class CROWNCITYSIMULATION_API ADestinationManager : public AInfo
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADestinationManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ADestination*> Destinations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ADestination*> SchoolDestinations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<ADestination*> OfficeDestinations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<ADestination*> HospitalDestinations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<ADestination*> StadiumDestinations;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	ADestination* GetRandomDestination();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		ADestination* GetRandomSchoolDestination();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		ADestination* GetRandomOfficeDestination();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		ADestination* GetRandomHospitalDestination();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		ADestination* GetRandomStadiumDestination();
};
