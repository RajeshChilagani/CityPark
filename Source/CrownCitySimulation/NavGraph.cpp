// Fill out your copyright notice in the Description page of Project Settings.


#include "NavGraph.h"
#include <Components/BillboardComponent.h>
#include <Algo/Reverse.h>
#include "Kismet/KismetSystemLibrary.h"

#include "NavPoint.h"



// Sets default values
ANavGraph::ANavGraph()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Sprite = CreateDefaultSubobject<UBillboardComponent>(TEXT("Sprite"));
	RootComponent = Sprite;
}

// Called when the game starts or when spawned
void ANavGraph::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANavGraph::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

PRAGMA_DISABLE_OPTIMIZATION

TArray<ANavPoint*> ANavGraph::GeneratePath(ANavPoint* Source, ANavPoint* Destination)
{
	switch (PathFinder)
	{
	case EPathFinder::BFS:
		return GenerateBFSPath(Source, Destination);
	case EPathFinder::AStar:
		return GenerateAStarPath(Source, Destination);
	default:
		break;
	}
	return TArray<ANavPoint*>();
}

TArray<FVector> ANavGraph::GeneratePathInPositions(ANavPoint* Source, ANavPoint* Destination)
{
	TArray<ANavPoint*> PathInNavPoints = GeneratePath(Source,Destination);
	TArray<FVector> PathInPositions;
	for (ANavPoint* NP : PathInNavPoints)
	{
		if (NP)
		{
			PathInPositions.Add(NP->GetActorLocation());
		}
	}

	return PathInPositions;
}

TArray<ANavPoint*> ANavGraph::GenerateBFSPath(ANavPoint* Source, ANavPoint* Destination)
{
	TArray<ANavPoint*> Path;
	TMap<ANavPoint*, ANavPoint*> ParentMap;
	TSet<ANavPoint*> Explored;
	if (Source && Destination)
	{
		TQueue<ANavPoint*> NavQueue;
		NavQueue.Enqueue(Source);
		ANavPoint* IsGoal = Source;
		while (!NavQueue.IsEmpty())
		{
			NavQueue.Dequeue(IsGoal);
			if (!IsGoal)
				continue;
			if (IsGoal == Destination)
				break;
			if (!Explored.Contains(IsGoal))
			{
				for (int i = 0; i < IsGoal->Connections.Num(); ++i)
				{
					NavQueue.Enqueue(IsGoal->Connections[i]); 
					ParentMap.FindOrAdd(IsGoal->Connections[i], IsGoal);
				}
				Explored.Add(IsGoal);
			}
		}
		if (IsGoal != Destination)
		{
			return Path;
		}

		while (IsGoal != Source)
		{
			Path.Add(IsGoal);
			IsGoal = ParentMap[IsGoal];
		}
		Path.Add(IsGoal);
		Algo::Reverse(Path);
	}
	return Path;
}

PRAGMA_ENABLE_OPTIMIZATION

TArray<ANavPoint*> ANavGraph::GenerateAStarPath(ANavPoint* Source, ANavPoint* Destination) {
	TArray<ANavPoint*> OpenList;
	TArray<ANavPoint*> Path;
	TMap<ANavPoint*, ANavPoint*> ParentMap;
	TSet<ANavPoint*> ClosedList;
	ANavPoint* CurrentNode = nullptr;

	//TArray<FConnection> CurrentConnections;

	if (Source && Destination) {

		Source->EstimatedTotalCost = FVector::Dist(Source->GetActorLocation(), Destination->GetActorLocation());
		OpenList.Push(Source);

		while (OpenList.Num() > 0) {

			//Find smallest node
			CurrentNode = FindSmallestCostElement(OpenList);

			if (CurrentNode == Destination)
				break;

			ANavPoint* EndNode;
			float EndNodeCost = 0.0f;
			float EndNodeHeuristic = 0.0f;
			for (int i = 0; i < CurrentNode->Connections.Num(); i++) {

				EndNode = CurrentNode->F_Connections[i].To;
				EndNodeCost = CurrentNode->CostSoFar + CurrentNode->F_Connections[i].Cost;

				if (ClosedList.Contains(EndNode)) {

					if (EndNode->CostSoFar <= EndNodeCost)
						continue;

					ClosedList.Remove(EndNode);


					EndNodeHeuristic = EndNode->EstimatedTotalCost - EndNode->CostSoFar;

				}else if(OpenList.Contains(EndNode))
				{

					if (EndNode->CostSoFar <= EndNodeCost)
						continue;

					EndNodeHeuristic = EndNode->EstimatedTotalCost - EndNode->CostSoFar;
				}
				else {
					EndNodeHeuristic = FVector::Dist(EndNode->GetActorLocation(), Destination->GetActorLocation());
				}

				EndNode->CostSoFar = EndNodeCost;
				EndNode->EstimatedTotalCost = EndNodeCost + EndNodeHeuristic;
				ParentMap.Add(EndNode, CurrentNode);
			}
			OpenList.Remove(CurrentNode);
			ClosedList.Add(CurrentNode);

			
		}

		if (CurrentNode != Destination)
			return TArray<ANavPoint*>();

	}
	while (CurrentNode != Source) {
		Path.Add(CurrentNode);
		CurrentNode = ParentMap[CurrentNode];
	}
	Path.Add(CurrentNode);

	Algo::Reverse(Path);
	return Path;
}


ANavPoint* ANavGraph::FindSmallestCostElement(TArray<ANavPoint*> List) {
	float MinCost = 99999999999.0f;
	ANavPoint* MinPoint = nullptr;
	for (int i = 0; i < List.Num(); i++) {
		if (List[i]->EstimatedTotalCost < MinCost) {
			MinCost = List[i]->EstimatedTotalCost;
			MinPoint = List[i];
		}
	}
	return MinPoint;
}


