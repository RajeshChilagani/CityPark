// Fill out your copyright notice in the Description page of Project Settings.


#include "Destination.h"
#include <Components/SceneComponent.h>
#include <Components/StaticMeshComponent.h>

// Sets default values
ADestination::ADestination()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADestination::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADestination::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

