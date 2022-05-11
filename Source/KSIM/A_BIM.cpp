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
