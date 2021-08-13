// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "TestActor.h"
#include "TestComponent.h"
#include "GameFramework/Actor.h"
#include "TestActorMultipleComponents.generated.h"

UCLASS()
class CUSTOMREPLICATION_API ATestActorMultipleComponents : public ATestActor
{
	GENERATED_BODY()

public:
	ATestActorMultipleComponents();

	virtual void GenerateData(int32 Size) override;
	virtual int32 GetValue() const override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UTestComponent* Component1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UTestComponent* Component2;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UTestComponent* Component3;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UTestComponent* Component4;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UTestComponent* Component5;
};
