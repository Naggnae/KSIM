// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "KSIMStruct.h"
#include "Engine/GameInstance.h"
#include <Runtime/Engine/Classes/Components/SplineComponent.h>
#include <Runtime/Engine/Classes/Components/SplineMeshComponent.h>
#include "GI.generated.h"
/**
 * Define Data structs
 */

UCLASS()
class KSIM_API UGI : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="K-SIM|BIM")
	TArray<UProceduralMeshComponent*> WallMeshComponents;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="K-SIM|BIM")
	TArray<UProceduralMeshComponent*> CurtainWallMeshComponents;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="K-SIM|BIM")
	TArray<UProceduralMeshComponent*> ColumnMeshComponents;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="K-SIM|BIM")
	TArray<UProceduralMeshComponent*> FloorMeshComponents;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="K-SIM|BIM")
	TArray<UProceduralMeshComponent*> ObjectMeshComponents;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM|Object")
	TArray<AActor*> DoorObjects;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM|Object")
	TArray<AActor*> WindowObjects;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM|Topology")
	TArray<AActor*> NodeObjects;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM|Topology")
	TArray<USplineComponent*> TopologyLines;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM|Topology")
	TArray<USplineMeshComponent*> TopologyLineMeshes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM|Topology")
	TMap<FString, FVector> NodeLocations;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM|Struct|BIM")
	TArray<FWallMeshData> WallMeshDataList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM|Struct|BIM")
	TArray<FColumnMeshData> ColumnMeshDataList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM|Struct|BIM")
	TArray<FFloorMeshData> FloorMeshDataList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM|Struct|BIM")
	TArray<F3DObjectData> ObjectMeshDataList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM|Struct|Topology")
	TArray<FNodeData> NodeDataList;							
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM|BIM")
	TArray<FString> LevelList;								
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM|Struct|Object")
	TArray<FWindowData> WindowDataList;						
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM|Struct|Object")
	TArray<FDoorData> DoorDataList;
	//TArray<FST_Stair>& StairMesh)

public:
	UFUNCTION(BlueprintCallable, Category = "K-SIM/BIM")
	void InitVariable();
};
