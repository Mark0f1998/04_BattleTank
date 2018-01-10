// Copyright Games by Mark0f.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"


// Forward Declaration
class UTankTrack;


// Driving Tank Tracks
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendTurnRight(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

private:
	// Called from the pathfinding logic by the AI controllers
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	UTankTrack* LeftTrack = nullptr;

	UTankTrack* RightTrack = nullptr;
};
