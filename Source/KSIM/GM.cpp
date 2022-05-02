// Fill out your copyright notice in the Description page of Project Settings.


#include "GM.h"

void AGM::StartPlay()
{
	Super::StartPlay();

	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Start"));
}
