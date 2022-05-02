// Fill out your copyright notice in the Description page of Project Settings.


#include "ViewPawn.h"

// Sets default values
AViewPawn::AViewPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AViewPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AViewPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AViewPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

