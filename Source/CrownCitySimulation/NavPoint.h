// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavPoint.generated.h"

class ANavPoint;

USTRUCT(BlueprintType)
struct FConnection
{
	GENERATED_BODY()
	//UPROPERTY(EditAnywhere)
	//ANavPoint* From;
	UPROPERTY(EditAnywhere)
	ANavPoint* To;
	//Cost
	UPROPERTY(EditAnywhere)
	float Cost = 0;
};


UCLASS(Blueprintable, BlueprintType)
class CROWNCITYSIMULATION_API ANavPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANavPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* Point;

	UPROPERTY(VisibleAnywhere)
	class UBillboardComponent* Sprite;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

//Debug
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bShowDebug = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ANavPoint*> Connections;

//AStar
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FConnection> F_Connections;

	UPROPERTY(EditAnywhere)
	float CostSoFar = 0;

	UPROPERTY(EditAnywhere)
	float EstimatedTotalCost = 0;
	
};
