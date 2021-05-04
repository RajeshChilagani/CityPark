// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavGraph.generated.h"

UENUM(BlueprintType)
enum class EPathFinder : uint8
{
	BFS UMETA(DisplayeName = "BreadthFirstSearch"),
	AStar UMETA(DisplayName = "AStar"),
};

class ANavPoint;
UCLASS(Blueprintable, BlueprintType)
class CROWNCITYSIMULATION_API ANavGraph : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANavGraph();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class UBillboardComponent* Sprite;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	TArray<ANavPoint*> GeneratePath(ANavPoint* Source, ANavPoint* Destination);

	UFUNCTION(BlueprintCallable)
	TArray<FVector> GeneratePathInPositions(ANavPoint* Source, ANavPoint* Destination);
	
	/*UFUNCTION(BlueprintCallable)
	ANavPoint* FindClosestNavPoint() const ;*/
	ANavPoint* FindSmallestCostElement(TArray<ANavPoint*> List);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bShowDebug = false;

	UPROPERTY(EditAnywhere)
	EPathFinder PathFinder = EPathFinder::BFS;

private:
	UFUNCTION()
	TArray<ANavPoint*> GenerateBFSPath(ANavPoint* Source, ANavPoint* Destination);

	UFUNCTION()
	TArray<ANavPoint*> GenerateAStarPath(ANavPoint* Source, ANavPoint* Destination);
};
