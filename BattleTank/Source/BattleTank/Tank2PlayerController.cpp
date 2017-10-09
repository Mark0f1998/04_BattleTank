// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank2PlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"

#define OUT

void ATank2PlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATank2PlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* Owner = GetControlledTank();
	if (!Owner) { return; }
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Owner is %s"), *Owner->GetName());
	}
}

ATank* ATank2PlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATank2PlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	OUT FVector HitLocation; // out param
	if (GetSightRayHitLocation(OUT HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation is %s"), *HitLocation.ToString());

		// GetWorldLocation Through the linetrace
		// TODO turn barrel to it
	}
}

// GetWorldLocation Through the linetrace, true if hits linetrace
bool ATank2PlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
}

