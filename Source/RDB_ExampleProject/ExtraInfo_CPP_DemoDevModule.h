// Copyright (c) 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DevModules/ARDBDevModule.h"
#include "Components/BoxComponent.h"
#include "ExtraInfo_CPP_DemoDevModule.generated.h"

// Demonstrates: Level-scoped Dev Module with debug drawing.
UCLASS()
class RDB_EXAMPLEPROJECT_API AExtraInfo_CPP_DemoDevModule : public ARDBDevModule
{
	GENERATED_BODY()

public:
	AExtraInfo_CPP_DemoDevModule();

	// Demonstrates: Bool toggle controlling debug visualization
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Debug Shape|Visibility",
		RDB_Description = "Toggle debug shape drawing",
		RDB_Tags = "Demonstration,DebugShape",
		RDB_AllowWatch = "true",
		RDB_AllowGraphWatch = "false"
	))
	bool bDrawShape = false;

	// Demonstrates: RDB_SliderEnabled with float range
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Debug Shape|Transform",
		RDB_Description = "Scale multiplier for the debug shape",
		RDB_Tags = "Demonstration,DebugShape",
		RDB_AllowWatch = "true",
		RDB_AllowGraphWatch = "false",
		RDB_SliderEnabled = "true",
		RDB_MinSlider = "0.1",
		RDB_MaxSlider = "5"
	))
	float ShapeScale = 1.0f;

	// Demonstrates: FLinearColor on a Dev Module
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Debug Shape|Appearance",
		RDB_Description = "Color of the debug shape",
		RDB_Tags = "Demonstration,DebugShape",
		RDB_AllowWatch = "true",
		RDB_AllowGraphWatch = "false"
	))
	FLinearColor ShapeColor = FLinearColor::Green;

	// Demonstrates: FRotator on a Dev Module
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Debug Shape|Transform",
		RDB_Description = "Rotation of the debug shape",
		RDB_Tags = "Demonstration,DebugShape",
		RDB_AllowWatch = "true",
		RDB_AllowGraphWatch = "false"
	))
	FRotator ShapeRotation = FRotator::ZeroRotator;

	// Demonstrates: FString label on a Dev Module
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Debug Shape|Appearance",
		RDB_Description = "Text label above the debug shape",
		RDB_Tags = "Demonstration,DebugShape",
		RDB_AllowWatch = "true",
		RDB_AllowGraphWatch = "false"
	))
	FString ShapeLabel = TEXT("Debug Box");

	// Demonstrates: RDB_Bind event on a Dev Module
	UFUNCTION(meta=(RDB_Bind, RDB_Description = "Prints all shape variable values to screen"))
	void PrintShapeState();

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxComp;

	virtual void Tick(float DeltaTime) override;
};
