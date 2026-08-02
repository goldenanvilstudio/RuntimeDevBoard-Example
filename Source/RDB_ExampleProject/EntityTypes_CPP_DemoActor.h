// Copyright (c) 2025. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "DevModules/URDBDevModuleLinkerComponent.h"
#include "Demo_CPP_ActorComponent.h"
#include "EntityTypes_CPP_DemoActor.generated.h"

UENUM(BlueprintType)
enum class ERDBExampleEnum : uint8
{
	Idle    UMETA(DisplayName = "Idle"),
	Active  UMETA(DisplayName = "Active"),
	Paused  UMETA(DisplayName = "Paused")
};

// Demonstrates: All RDB variable types and metadata options.
UCLASS()
class RDB_EXAMPLEPROJECT_API AEntityTypes_CPP_DemoActor : public AActor
{
	GENERATED_BODY()

public:
	AEntityTypes_CPP_DemoActor();

	// Demonstrates: RDB_DisplayName for custom display
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Entity Types|Bool",
		RDB_Description = "A bool toggle",
		RDB_Tags = "Demonstration,Group A",
		RDB_AllowWatch = "true",
		RDB_AllowGraphWatch = "false",
		RDB_DisplayName = "Toggle Me"
	))
	bool bExampleBool = false;

	// Demonstrates: RDB_SliderEnabled with min/max range
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Entity Types|Float",
		RDB_Description = "A float with slider",
		RDB_Tags = "Demonstration,Group A",
		RDB_AllowWatch = "true",
		RDB_AllowGraphWatch = "false",
		RDB_SliderEnabled = "true",
		RDB_MinSlider = "0",
		RDB_MaxSlider = "100"
	))
	float ExampleFloat = 50.0f;

	// Demonstrates: RDB_OnChange callback
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Entity Types|Int",
		RDB_Description = "An integer with change callback",
		RDB_Tags = "Demonstration,Group B",
		RDB_AllowWatch = "true",
		RDB_AllowGraphWatch = "false",
		RDB_OnChange = "OnIntChanged"
	))
	int32 ExampleInt = 0;

	// Demonstrates: RDB_RequiresConfirm dialog
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Entity Types|String",
		RDB_Description = "A string with confirmation",
		RDB_Tags = "Demonstration,Group B",
		RDB_AllowWatch = "true",
		RDB_AllowGraphWatch = "false",
		RDB_RequiresConfirm = "true"
	))
	FString ExampleString = TEXT("Hello RDB");

	// Demonstrates: FVector variable type
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Entity Types|Vector",
		RDB_Description = "A vector value",
		RDB_Tags = "Demonstration,Group C",
		RDB_AllowWatch = "true",
		RDB_AllowGraphWatch = "false"
	))
	FVector ExampleVector = FVector::ZeroVector;

	// Demonstrates: FRotator variable type
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Entity Types|Rotator",
		RDB_Description = "A rotator value",
		RDB_Tags = "Demonstration,Group C",
		RDB_AllowWatch = "true",
		RDB_AllowGraphWatch = "false"
	))
	FRotator ExampleRotator = FRotator::ZeroRotator;

	// Demonstrates: FLinearColor variable type
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Entity Types|Color",
		RDB_Description = "A color value",
		RDB_Tags = "Demonstration,Group C",
		RDB_AllowWatch = "true",
		RDB_AllowGraphWatch = "false"
	))
	FLinearColor ExampleColor = FLinearColor::White;

	// Demonstrates: Enum variable type
	UPROPERTY(EditAnywhere, meta=(
		RDB_Bind,
		RDB_Category = "Entity Types|Enum",
		RDB_Description = "An enum value",
		RDB_Tags = "Demonstration,Group A",
		RDB_AllowWatch = "true",
		RDB_AllowGraphWatch = "false"
	))
	ERDBExampleEnum ExampleEnum = ERDBExampleEnum::Idle;

	// Demonstrates: RDB_Bind on a function (event trigger)
	UFUNCTION(meta=(RDB_Bind, RDB_Description = "Prints all variable values to screen"))
	void PrintAllVariables();

	UFUNCTION()
	void OnIntChanged(int32 OldValue, int32 NewValue);

	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere)
	URDBDevModuleLinkerComponent* LinkerComp;

	UPROPERTY(VisibleAnywhere)
	UDemo_CPP_ActorComponent* DemoComp;
};
