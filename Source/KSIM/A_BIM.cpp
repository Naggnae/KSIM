// Fill out your copyright notice in the Description page of Project Settings.


#include "A_BIM.h"

// Sets default values
AA_BIM::AA_BIM()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AA_BIM::BeginPlay()
{
	Super::BeginPlay();
	GI = Cast<UGI>(GetGameInstance());
}

// Called every frame
void AA_BIM::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AA_BIM::InitVariable()
{
	for (auto Component: GI->WallMeshComponents)
	{
		Component->DestroyComponent();
	}
	for (auto Component: GI->CurtainWallMeshComponents)
	{
		Component->DestroyComponent();
	}
	for (auto Component: GI->ColumnMeshComponents)
	{
		Component->DestroyComponent();
	}
	for (auto Component: GI->FloorMeshComponents)
	{
		Component->DestroyComponent();
	}
	for (auto Component: GI->ObjectMeshComponents)
	{
		Component->DestroyComponent();
	}
	for (auto Door : GI->DoorObjects)
	{
		Door->Destroy();
	}
	for (auto Window : GI->WindowObjects)
	{
		Window->Destroy();
	}
	for (auto Node : GI->NodeObjects)
	{
		Node->Destroy();
	}
	for (auto Spline : GI->TopologyLines) 
	{
		Spline->DestroyComponent();
	}
	for (auto SplineMesh : GI->TopologyLineMeshes)
	{
		SplineMesh->DestroyComponent();
	}

	GI->WallMeshComponents.Empty();
	GI->CurtainWallMeshComponents.Empty();
	GI->ColumnMeshComponents.Empty();
	GI->FloorMeshComponents.Empty();
	GI->ObjectMeshComponents.Empty();
	GI->DoorObjects.Empty();
	GI->WindowObjects.Empty();
	GI->NodeObjects.Empty();
	GI->TopologyLines.Empty();
	GI->TopologyLineMeshes.Empty();
	GI->NodeLocations.Empty();
}



