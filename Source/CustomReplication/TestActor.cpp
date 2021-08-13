// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

ATestActor::ATestActor() : TimeSinceDataGenerated(5.0f)
{
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	Text = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text"));
	Text->SetTextRenderColor(FColor::Cyan);
	Text->SetXScale(5.0f);
	Text->SetYScale(5.0f);
	Text->SetupAttachment(RootComponent);
}

void ATestActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (HasAuthority())
	{
		TimeSinceDataGenerated += DeltaSeconds;
		if (TimeSinceDataGenerated > 5.0f)
		{
			GenerateData(DataSize);
			TimeSinceDataGenerated = 0.0f;
			UE_LOG(LogTemp, Display, TEXT("Data generated: %d"), GetValue());
		}
	}
	Text->SetText(FText::AsNumber(GetValue()));
}

void ATestActor::GenerateData(int32 Size)
{
}

int32 ATestActor::GetValue() const
{
	return -1;
}

