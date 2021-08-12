// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

USTRUCT(BlueprintType)
struct FMyStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 IntValue;

	int32 DataSize = 0;
	uint8* Data = nullptr;

	void GenerateData();
	
	bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess);

};

template<>
struct TStructOpsTypeTraits<FMyStruct> : public TStructOpsTypeTraitsBase2<FMyStruct>
{
	enum
	{
		WithNetSerializer = true
	};
};

UCLASS(Blueprintable)
class CUSTOMREPLICATION_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATestActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	TArray<FMyStruct> ReplicatedValues;

	UFUNCTION(BlueprintCallable)
	void GenerateData();
};

