// Copyright (c) 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DevModules/ARDBDevModule.h"
#include "Components/SceneComponent.h"
#include "SpinCube_CPP_DevModule.generated.h"

// Demonstrates: A DevModule that draws a spinning tilted debug cube.
UCLASS()
class RDB_EXAMPLEPROJECT_API ASpinCube_CPP_DevModule : public ARDBDevModule
{
	GENERATED_BODY()

public:
	ASpinCube_CPP_DevModule();

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;

	// Spin speed in degrees per second
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Spin Cube",
		RDB_Description = "Rotation speed in degrees per second",
		RDB_SliderEnabled = "true",
		RDB_MinSlider = "0",
		RDB_MaxSlider = "360"
	))
	float Speed = 90.0f;

	// Cube extent scale multiplier
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Spin Cube",
		RDB_Description = "Scale multiplier for the cube size",
		RDB_SliderEnabled = "true",
		RDB_MinSlider = "0.1",
		RDB_MaxSlider = "5"
	))
	float Scale = 1.0f;

	// Cube wireframe color
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Spin Cube",
		RDB_Description = "Color of the debug cube"
	))
	FLinearColor CubeColor = FLinearColor::Blue;

	virtual void Tick(float DeltaTime) override;

private:
	// Accumulated yaw for spinning
	float AccumulatedYaw = 0.0f;
};
