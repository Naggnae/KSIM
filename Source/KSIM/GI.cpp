// Fill out your copyright notice in the Description page of Project Settings.


#include "GI.h"

void UGI::InitVariable()
{
	for (auto Component : WallMeshComponents)
	{
		Component->DestroyComponent();
	}
	for (auto Component : CurtainWallMeshComponents)
	{
		Component->DestroyComponent();
	}
	for (auto Component : ColumnMeshComponents)
	{
		Component->DestroyComponent();
	}
	for (auto Component : FloorMeshComponents)
	{
		Component->DestroyComponent();
	}
	for (auto Component : ObjectMeshComponents)
	{
		Component->DestroyComponent();
	}
	for (auto Door : DoorObjects)
	{
		Door->Destroy();
	}
	for (auto Window : WindowObjects)
	{
		Window->Destroy();
	}
	for (auto Node : NodeObjects)
	{
		Node->Destroy();
	}
	for (auto Spline : TopologyLines)
	{
		Spline->DestroyComponent();
	}
	for (auto SplineMesh : TopologyLineMeshes)
	{
		SplineMesh->DestroyComponent();
	}

	WallMeshComponents.Empty();
	CurtainWallMeshComponents.Empty();
	ColumnMeshComponents.Empty();
	FloorMeshComponents.Empty();
	ObjectMeshComponents.Empty();
	DoorObjects.Empty();
	WindowObjects.Empty();
	NodeObjects.Empty();
	TopologyLines.Empty();
	TopologyLineMeshes.Empty();
	NodeLocations.Empty();
}
