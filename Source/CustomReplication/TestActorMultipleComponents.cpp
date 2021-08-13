// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActorMultipleComponents.h"


// Sets default values
ATestActorMultipleComponents::ATestActorMultipleComponents()
{
	Component1 = CreateDefaultSubobject<UTestComponent>(TEXT("Component1"));
	Component2 = CreateDefaultSubobject<UTestComponent>(TEXT("Component2"));
	Component3 = CreateDefaultSubobject<UTestComponent>(TEXT("Component3"));
	Component4 = CreateDefaultSubobject<UTestComponent>(TEXT("Component4"));
	Component5 = CreateDefaultSubobject<UTestComponent>(TEXT("Component5"));
}

void ATestActorMultipleComponents::GenerateData(int32 Size)
{
	Component1->ReplicatedValue.GenerateData(DataSize);
	Component2->ReplicatedValue.GenerateData(DataSize);
	Component3->ReplicatedValue.GenerateData(DataSize);
	Component4->ReplicatedValue.GenerateData(DataSize);
	Component5->ReplicatedValue.GenerateData(DataSize);
}

int32 ATestActorMultipleComponents::GetValue() const
{
	return Component1->ReplicatedValue.GetValue() +
		Component2->ReplicatedValue.GetValue() +
		Component3->ReplicatedValue.GetValue() +
		Component4->ReplicatedValue.GetValue() +
		Component5->ReplicatedValue.GetValue();
}
