// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "Engine/GameInstance.h"
#include "GI.generated.h"

/**
 * Define Data structs
 */
USTRUCT(Atomic, BlueprintType)
struct FWallMeshData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="K-SIM/BIM")
	FString Type;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="K-SIM/BIM")
	TArray<FVector> VertexList;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="K-SIM/BIM")
	TArray<int32> TriangleIndexList;		
};
USTRUCT(Atomic, BlueprintType)
struct FColumnMeshData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="K-SIM/BIM")
	FString Shape;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="K-SIM/BIM")
	TArray<FVector> VertexList;	
};
USTRUCT(Atomic, BlueprintType)
struct FFloorMeshData
{
	GENERATED_BODY()	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="K-SIM/BIM")
	FString SpaceName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="K-SIM/BIM")
	TArray<FVector> VertexList;		
};
USTRUCT(Atomic, BlueprintType)
struct F3DObjectData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	FVector Scale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	FVector Location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	FRotator Rotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	TArray<FVector>	VertexList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	TArray<int32> TriangleIndexList;
};
USTRUCT(Atomic, BlueprintType)
struct FNodeData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	FString ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	int32 Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	FString OwnerType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	FString OwnerID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	bool isPassable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	bool isExit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	float DoorWidth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	FVector Location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	TArray<FString> TargetIDs;
};
USTRUCT(Atomic, BlueprintType)
struct FWindowData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	FVector Location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	FRotator Direction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	float Width;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	float Height;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	float Elevation;
};
USTRUCT(Atomic, BlueprintType)
struct FDoordata
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	FVector Location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	FRotator Direction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	float Width;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	float Height;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	float Elevation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	int32 DoorType;
};
USTRUCT(Atomic, BlueprintType)
struct FStairData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	TArray<FVector> Vector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	TArray<int32> Triangle;
};
USTRUCT(Atomic, BlueprintType)
struct FPOIData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	FRotator Angle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	FVector Location;
};
UCLASS()
class KSIM_API UGI : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="K-SIM/BIM")
	TArray<UProceduralMeshComponent*> WallMeshComponents;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="K-SIM/BIM")
	TArray<UProceduralMeshComponent*> CurtainWallMeshComponents;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="K-SIM/BIM")
	TArray<UProceduralMeshComponent*> ColumnMeshComponents;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="K-SIM/BIM")
	TArray<UProceduralMeshComponent*> FloorMeshComponents;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="K-SIM/BIM")
	TArray<UProceduralMeshComponent*> ObjectMeshComponents;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	TArray<FWallMeshData> WallMeshDataList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	TArray<FColumnMeshData> ColumnMeshDataList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	TArray<FFloorMeshData> FloorMeshDataList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	TArray<F3DObjectData> ObjectMeshDataList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	TArray<FNodeData> NodeDataList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	TArray<FString> LevelList;
	//TArray<FST_Stair>& StairMesh)

};
