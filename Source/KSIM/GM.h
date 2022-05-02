// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GM.generated.h"

/**
 * 
 */
UCLASS()
class KSIM_API AGM : public AGameMode
{
	GENERATED_BODY()

public:
	virtual void StartPlay() override;
};
