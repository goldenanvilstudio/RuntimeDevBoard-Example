// Copyright (c) 2025. All rights reserved.

#include "ExtraInfo_CPP_DemoDevModule.h"
#include "DrawDebugHelpers.h"

AExtraInfo_CPP_DemoDevModule::AExtraInfo_CPP_DemoDevModule()
{
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	RootComponent = BoxComp;
	BoxComp->SetHiddenInGame(false);
	BoxComp->SetVisibility(true);

	PrimaryActorTick.bCanEverTick = true;
}

void AExtraInfo_CPP_DemoDevModule::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bDrawShape)
	{
		FVector Extent = FVector(50.0f) * ShapeScale;
		DrawDebugBox(GetWorld(), GetActorLocation(), Extent,
			ShapeRotation.Quaternion(), ShapeColor.ToFColor(true), false, 0.0f);
		DrawDebugString(GetWorld(), GetActorLocation() + FVector(0, 0, 100),
			ShapeLabel, nullptr, ShapeColor.ToFColor(true), 0.0f);
	}
}

void AExtraInfo_CPP_DemoDevModule::PrintShapeState()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Cyan,
			FString::Printf(TEXT("bDrawShape: %s"), bDrawShape ? TEXT("true") : TEXT("false")));
		GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Cyan,
			FString::Printf(TEXT("ShapeScale: %.2f"), ShapeScale));
		GEngine->AddOnScreenDebugMessage(2, 5.0f, FColor::Cyan,
			FString::Printf(TEXT("ShapeColor: R=%.2f G=%.2f B=%.2f A=%.2f"),
				ShapeColor.R, ShapeColor.G, ShapeColor.B, ShapeColor.A));
		GEngine->AddOnScreenDebugMessage(3, 5.0f, FColor::Cyan,
			FString::Printf(TEXT("ShapeRotation: P=%.1f Y=%.1f R=%.1f"),
				ShapeRotation.Pitch, ShapeRotation.Yaw, ShapeRotation.Roll));
		GEngine->AddOnScreenDebugMessage(4, 5.0f, FColor::Cyan,
			FString::Printf(TEXT("ShapeLabel: %s"), *ShapeLabel));
	}
}
