// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

#include "Net/UnrealNetwork.h"

void FMyStruct::GenerateData()
{
	if (Data)
	{
		delete [] Data;
		Data = nullptr;
	}

	DataSize = FMath::RandRange(10000, 60000);
	int32 Value = FMath::RandRange(0, 5);

	Data = new uint8[DataSize];
	for (int Index = 0; Index < DataSize; ++Index)
	{
		Data[Index] = Value;
	}

	IntValue = Value;
}

bool FMyStruct::NetSerialize(FArchive& Ar, UPackageMap* Map, bool& bOutSuccess)
{
	if (Ar.IsLoading() && Data)
	{
		delete [] Data;
		Data = nullptr;
	}
	
	Ar << DataSize;
	if (DataSize)
	{
		if (Ar.IsLoading())
		{
			Data = new uint8[DataSize];
		}
		Ar.Serialize(Data, DataSize);

		if (Ar.IsLoading())
		{
			IntValue = Data[0];
			for (int Index = 0; Index < DataSize; ++Index)
			{
				check(Data[Index] == IntValue);
			}
		}
	}

	bOutSuccess = true;
	return true;
}

// Sets default values
ATestActor::ATestActor()
{
	ReplicatedValues.Add(FMyStruct());
	ReplicatedValues.Add(FMyStruct());
	ReplicatedValues.Add(FMyStruct());
	ReplicatedValues.Add(FMyStruct());
	ReplicatedValues.Add(FMyStruct());
}

void ATestActor::GenerateData()
{
	for (FMyStruct& RV : ReplicatedValues)
	{
		RV.GenerateData();
	}
}

void ATestActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ATestActor, ReplicatedValues);
}
