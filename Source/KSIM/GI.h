// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "KSIMStruct.h"
#include "Engine/GameInstance.h"
#include "GI.generated.h"

/**
 * Define Data structs
 */

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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	TArray<FWindowData> WindowDataList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "K-SIM/BIM")
	TArray<FDoorData> DoorDataList;
	//TArray<FST_Stair>& StairMesh)

};
