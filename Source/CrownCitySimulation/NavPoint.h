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
	UPROPERTY(EditAnywhere)
	ANavPoint* From;
	UPROPERTY(EditAnywhere)
	ANavPoint* To;
	//Cost
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

	UPROPERTY(EditAnywhere)
	TArray<FConnection> Connections;
};
