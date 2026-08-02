// Copyright (c) 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Global/RDBGlobalBindingActor.h"
#include "Demo_CPP_GlobalBindingActor.generated.h"

// Demonstrates: Global Binding Actor with Graph Watch and ReadOnly.
UCLASS()
class RDB_EXAMPLEPROJECT_API ADemo_CPP_GlobalBindingActor : public ARDBGlobalBindingActor
{
	GENERATED_BODY()

public:
	ADemo_CPP_GlobalBindingActor();

	virtual void Tick(float DeltaTime) override;

	// Demonstrates: RDB_ReadOnly + RDB_AllowGraphWatch with axis range
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Trigonometry",
		RDB_Description = "Sine of game time (5s period)",
		RDB_Tags = "Global,Trigonometry",
		RDB_AllowGraphWatch = "true",
		RDB_ReadOnly = "true",
		RDB_MinGraphAxis = "-1",
		RDB_MaxGraphAxis = "1",
		RDB_GraphGroup = "Trigonometry"
	))
	float SineValue = 0.0f;

	// Demonstrates: RDB_ReadOnly + RDB_AllowGraphWatch with axis range
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Trigonometry",
		RDB_Description = "Cosine of game time (5s period)",
		RDB_Tags = "Global,Trigonometry",
		RDB_AllowGraphWatch = "true",
		RDB_ReadOnly = "true",
		RDB_MinGraphAxis = "-1",
		RDB_MaxGraphAxis = "1",
		RDB_GraphGroup = "Trigonometry"
	))
	float CosineValue = 0.0f;
};
