// Fill out your copyright notice in the Description page of Project Settings.


#include "NavPoint.h"
#include <Components/SphereComponent.h>
#include <Components/BillboardComponent.h>

// Sets default values
ANavPoint::ANavPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sprite = CreateDefaultSubobject<UBillboardComponent>(TEXT("Sprite"));
	RootComponent = Sprite;
	Point = CreateDefaultSubobject<USphereComponent>(TEXT("NavPoint"));
	Point->SetupAttachment(RootComponent);

	if (F_Connections.Num() != 0) {

		for(int i = 0;i < F_Connections.Num();i++)
		{
			F_Connections[i].Cost = FVector::Dist(GetActorLocation(), F_Connections[i].To->GetActorLocation());
		}
	}
}

// Called when the game starts or when spawned
void ANavPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANavPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

