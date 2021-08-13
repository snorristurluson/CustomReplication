// Fill out your copyright notice in the Description page of Project Settings.

#include "TestActorSimple.h"

#include "Net/UnrealNetwork.h"

void ATestActorSimple::GenerateData(int32 Size)
{
	ReplicatedValue.GenerateData(DataSize);
}

int32 ATestActorSimple::GetValue() const
{
	return ReplicatedValue.GetValue();
}

void ATestActorSimple::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ATestActorSimple, ReplicatedValue);
}
