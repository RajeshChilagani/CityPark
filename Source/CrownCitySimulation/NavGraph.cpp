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

TArray<ANavPoint*> ANavGraph::GeneratePath(ANavPoint* Source, ANavPoint* Destination)
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
					NavQueue.Enqueue(IsGoal->Connections[i].To); 
					ParentMap.FindOrAdd(IsGoal->Connections[i].To, IsGoal);
				}
				Explored.Add(IsGoal);
			}
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


