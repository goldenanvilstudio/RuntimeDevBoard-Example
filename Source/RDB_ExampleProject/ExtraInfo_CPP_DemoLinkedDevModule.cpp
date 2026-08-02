// Copyright (c) 2025. All rights reserved.

#include "ExtraInfo_CPP_DemoLinkedDevModule.h"

void AExtraInfo_CPP_DemoLinkedDevModule::Initialize_Implementation(AActor* LinkedActor)
{
	Super::Initialize_Implementation(LinkedActor);
}

void AExtraInfo_CPP_DemoLinkedDevModule::PrintLinkedActorInfo()
{
	AActor* Linked = GetLinkedActor();

	if (Linked)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White,
				FString::Printf(TEXT("Linked Actor: %s at %s"),
					*Linked->GetName(),
					*Linked->GetActorLocation().ToString()));
		}
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow,
				TEXT("No linked actor"));
		}
	}
}
