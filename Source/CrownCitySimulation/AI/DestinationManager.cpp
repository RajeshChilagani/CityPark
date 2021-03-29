// Fill out your copyright notice in the Description page of Project Settings.


#include "DestinationManager.h"

// Sets default values
ADestinationManager::ADestinationManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADestinationManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADestinationManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ADestination* ADestinationManager::GetRandomDestination()
{
	if (Destinations.Num() > 0)
	{
		int RandomIndex = FMath::RandRange(0, Destinations.Num() - 1);
		return Destinations[RandomIndex];
	}

	UE_LOG(LogTemp, Warning, TEXT("NoDestinations"));
	return nullptr;
}

