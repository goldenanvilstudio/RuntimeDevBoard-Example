// Copyright (c) 2025. All rights reserved.

#include "EntityTypes_CPP_DemoActor.h"
#include "ExtraInfo_CPP_DemoLinkedDevModule.h"

AEntityTypes_CPP_DemoActor::AEntityTypes_CPP_DemoActor()
{
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
	RootComponent = CapsuleComp;
	CapsuleComp->SetHiddenInGame(false);
	CapsuleComp->SetVisibility(true);

	LinkerComp = CreateDefaultSubobject<URDBDevModuleLinkerComponent>(TEXT("LinkerComp"));
	LinkerComp->DevModuleClass = AExtraInfo_CPP_DemoLinkedDevModule::StaticClass();

	DemoComp = CreateDefaultSubobject<UDemo_CPP_ActorComponent>(TEXT("DemoComp"));
}

void AEntityTypes_CPP_DemoActor::PrintAllVariables()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Cyan, FString::Printf(TEXT("bExampleBool: %s"), bExampleBool ? TEXT("true") : TEXT("false")));
		GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Cyan, FString::Printf(TEXT("ExampleFloat: %.2f"), ExampleFloat));
		GEngine->AddOnScreenDebugMessage(2, 5.0f, FColor::Cyan, FString::Printf(TEXT("ExampleInt: %d"), ExampleInt));
		GEngine->AddOnScreenDebugMessage(3, 5.0f, FColor::Cyan, FString::Printf(TEXT("ExampleString: %s"), *ExampleString));
		GEngine->AddOnScreenDebugMessage(4, 5.0f, FColor::Cyan, FString::Printf(TEXT("ExampleVector: %s"), *ExampleVector.ToString()));
		GEngine->AddOnScreenDebugMessage(5, 5.0f, FColor::Cyan, FString::Printf(TEXT("ExampleRotator: %s"), *ExampleRotator.ToString()));
		GEngine->AddOnScreenDebugMessage(6, 5.0f, FColor::Cyan, FString::Printf(TEXT("ExampleColor: %s"), *ExampleColor.ToString()));
		GEngine->AddOnScreenDebugMessage(7, 5.0f, FColor::Cyan, FString::Printf(TEXT("ExampleEnum: %s"), *StaticEnum<ERDBExampleEnum>()->GetDisplayNameTextByValue(static_cast<int64>(ExampleEnum)).ToString()));
	}
}

void AEntityTypes_CPP_DemoActor::OnIntChanged(int32 OldValue, int32 NewValue)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("ExampleInt changed: %d -> %d"), OldValue, NewValue));
	}
}
