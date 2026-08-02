// Copyright (c) 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DevModules/ARDBLinkedDevModule.h"
#include "ExtraInfo_CPP_DemoLinkedDevModule.generated.h"

// Demonstrates: Linked Dev Module pattern.
UCLASS()
class RDB_EXAMPLEPROJECT_API AExtraInfo_CPP_DemoLinkedDevModule : public ARDBLinkedDevModule
{
	GENERATED_BODY()

public:
	// Demonstrates: Float variable on a Linked Dev Module
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Linked Extra Info",
		RDB_Description = "A float variable on the linked dev module",
		RDB_Tags = "Linked,ExtraInfo",
		RDB_AllowWatch = "true",
		RDB_AllowGraphWatch = "false"
	))
	float LinkedFloat = 0.0f;

	// Demonstrates: RDB_Bind event on a Linked Dev Module
	UFUNCTION(meta=(RDB_Bind, RDB_Description = "Prints linked actor name and location"))
	void PrintLinkedActorInfo();

	virtual void Initialize_Implementation(AActor* LinkedActor) override;
};
