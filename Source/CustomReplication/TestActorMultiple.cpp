// Fill out your copyright notice in the Description page of Project Settings.

#include "TestActorMultiple.h"

#include "Net/UnrealNetwork.h"

void ATestActorMultiple::GenerateData(int32 Size)
{
	ReplicatedValue.GenerateData(DataSize);
	ReplicatedValue1.GenerateData(DataSize);
	ReplicatedValue2.GenerateData(DataSize);
	ReplicatedValue3.GenerateData(DataSize);
	ReplicatedValue4.GenerateData(DataSize);
}

int32 ATestActorMultiple::GetValue() const
{
	return ReplicatedValue.GetValue() +
		ReplicatedValue1.GetValue() +
		ReplicatedValue2.GetValue() +
		ReplicatedValue3.GetValue() +
		ReplicatedValue4.GetValue();
}

void ATestActorMultiple::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ATestActorMultiple, ReplicatedValue);
	DOREPLIFETIME(ATestActorMultiple, ReplicatedValue1);
	DOREPLIFETIME(ATestActorMultiple, ReplicatedValue2);
	DOREPLIFETIME(ATestActorMultiple, ReplicatedValue3);
	DOREPLIFETIME(ATestActorMultiple, ReplicatedValue4);
}
