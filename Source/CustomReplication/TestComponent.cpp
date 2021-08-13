// Fill out your copyright notice in the Description page of Project Settings.


#include "TestComponent.h"

#include "Net/UnrealNetwork.h"

UTestComponent::UTestComponent()
{
	SetIsReplicated(true);
}

void UTestComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UTestComponent, ReplicatedValue);
}
