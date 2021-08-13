// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "TestActor.h"
#include "TestActorMultiple.generated.h"

UCLASS(Blueprintable)
class CUSTOMREPLICATION_API ATestActorMultiple : public ATestActor
{
	GENERATED_BODY()

public:
	virtual void GenerateData(int32 Size) override;
	virtual int32 GetValue() const override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	FTestStruct ReplicatedValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	FTestStruct ReplicatedValue1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	FTestStruct ReplicatedValue2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	FTestStruct ReplicatedValue3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	FTestStruct ReplicatedValue4;
};
