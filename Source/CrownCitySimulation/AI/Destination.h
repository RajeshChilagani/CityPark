// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Destination.generated.h"

UENUM(BlueprintType)

enum class EDestinationType : uint8
{
	School	UMETA(DisplayName = "School"),
	Office  UMETA (DisplayName = "Office"),
	Hospital  UMETA(DisplayName = "Hospital"),
	Stadium   UMETA(DisplayName = "Stadium"),
};

UCLASS()
class CROWNCITYSIMULATION_API ADestination : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADestination();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	class USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* Mesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector DestinationLocaton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DestinationType)
		EDestinationType destinationType = EDestinationType::Office;

};
