// Copyright (c) 2025. All rights reserved.

#include "Demo_CPP_GlobalBindingActor.h"

ADemo_CPP_GlobalBindingActor::ADemo_CPP_GlobalBindingActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADemo_CPP_GlobalBindingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float T = GetWorld()->GetTimeSeconds();
	float Period = 5.0f;
	float Omega = (2.0f * PI) / Period;
	SineValue = FMath::Sin(Omega * T);
	CosineValue = FMath::Cos(Omega * T);
}
