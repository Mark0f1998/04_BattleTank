// Copyright Games by Mark0f.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AIController.h"
#include "TankAIController.generated.h"


UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	// How close can the AI tank get
	float AcceptanceRadius = 3000;
};
