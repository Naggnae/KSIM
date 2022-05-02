// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "tinyxml2.h"
#include "GI.h"
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "XMLParserSS.generated.h"

/**
 * 
 */
UCLASS()
class KSIM_API UXMLParserSS : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

public:
	tinyxml2::XMLDocument XMLFile;
	TArray<tinyxml2::XMLElement*> LevelNodeList;

public:
	UFUNCTION(BlueprintCallable,Category="K-SIM")
	void InitXMLData(FString XMLFileName, TArray<FString> &LevelNameList);
	UFUNCTION(BlueprintCallable,Category="K-SIM")
	void SetMeshDataList(FString LevelName);
	TArray<FWallMeshData> SetWallMeshData(tinyxml2::XMLElement* LevelNode);
	TArray<FColumnMeshData> SetColumnMeshData(tinyxml2::XMLElement* LevelNode);
	TArray<FFloorMeshData> SetFloorMeshData(tinyxml2::XMLElement* LevelNode);
	TArray<F3DObjectData> SetObjectMeshData(tinyxml2::XMLElement* LevelNode);
	//TArray<FWindowData> SetWindowData(tinyxml2::XMLElement* LevelNode);
	//TArray<FDoordata> SetDoorData(tinyxml2::XMLElement* LevelNode);
	TArray<FNodeData> SetNodeData(tinyxml2::XMLElement* LevelNode);
	//TArray<FStairData> SetStairData(tinyxml2::XMLElement* LevelNode);
	TArray<FVector> SetCircleColumnVector(FVector StartPoint, FVector EndPoint, float Radius, int32 Segments);
};
