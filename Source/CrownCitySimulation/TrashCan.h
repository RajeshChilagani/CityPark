// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrashCan.generated.h"

UCLASS()
class CROWNCITYSIMULATION_API ATrashCan : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrashCan();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TrashCount = 0;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxTrashCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bTrashCanFull = false;

};
