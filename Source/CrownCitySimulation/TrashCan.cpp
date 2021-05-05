// Fill out your copyright notice in the Description page of Project Settings.


#include "TrashCan.h"

// Sets default values
ATrashCan::ATrashCan()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATrashCan::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrashCan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

