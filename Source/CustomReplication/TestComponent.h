// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "TestStruct.h"
#include "Components/ActorComponent.h"
#include "TestComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CUSTOMREPLICATION_API UTestComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UTestComponent();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	FTestStruct ReplicatedValue;
};
