// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KSIMStruct.generated.h"
/**
 *
 */
USTRUCT(Atomic, BlueprintType)
struct FWallMeshData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
		FString Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
		TArray<FVector> VertexList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
		TArray<int32> TriangleIndexList;
};
USTRUCT(Atomic, BlueprintType)
struct FColumnMeshData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
		FString Shape;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
		TArray<FVector> VertexList;
};
USTRUCT(Atomic, BlueprintType)
struct FFloorMeshData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
		FString SpaceName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
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
		FString Name;
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
struct FDoorData
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
		int32 Type;
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
class KSIM_API KSIMStruct
{
public:
	KSIMStruct();
	~KSIMStruct();
};
