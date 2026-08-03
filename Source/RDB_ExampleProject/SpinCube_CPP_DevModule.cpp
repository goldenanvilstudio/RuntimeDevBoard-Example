// Copyright (c) 2025. All rights reserved.

#include "SpinCube_CPP_DevModule.h"
#include "DrawDebugHelpers.h"

ASpinCube_CPP_DevModule::ASpinCube_CPP_DevModule()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	PrimaryActorTick.bCanEverTick = true;
}

void ASpinCube_CPP_DevModule::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Accumulate spin
	AccumulatedYaw += Speed * DeltaTime;
	if (AccumulatedYaw > 360.0f)
	{
		AccumulatedYaw -= 360.0f;
	}

	// Build a tilted rotation: 30 pitch + 45 roll so no face is parallel to the floor,
	// then spin around the yaw axis at the configured speed.
	const FRotator TiltedRotation(30.0f, AccumulatedYaw, 45.0f);

	const FVector Extent = FVector(50.0f) * Scale;

	DrawDebugBox(
		GetWorld(),
		GetActorLocation(),
		Extent,
		TiltedRotation.Quaternion(),
		CubeColor.ToFColor(true),
		false,
		0.0f
	);
}
