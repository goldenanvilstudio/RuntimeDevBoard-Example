// Copyright (c) 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Demo_CPP_ActorComponent.generated.h"

// Demonstrates: Component-level RDB binding.
UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class RDB_EXAMPLEPROJECT_API UDemo_CPP_ActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UDemo_CPP_ActorComponent();

	// Demonstrates: Bool variable type on a component
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Component Demo",
		RDB_Description = "A bool variable on an actor component",
		RDB_Tags = "Demonstration,Component",
		RDB_AllowWatch = "true",
		RDB_AllowGraphWatch = "false"
	))
	bool bComponentVariable = false;
};
