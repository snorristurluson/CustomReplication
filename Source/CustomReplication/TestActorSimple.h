// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "TestActor.h"
#include "TestActorSimple.generated.h"

UCLASS(Blueprintable)
class CUSTOMREPLICATION_API ATestActorSimple : public ATestActor
{
	GENERATED_BODY()

public:
	virtual void GenerateData(int32 Size) override;
	virtual int32 GetValue() const override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	FTestStruct ReplicatedValue;
};
