#pragma once

#include "CoreMinimal.h"

#include "TestStruct.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

UCLASS(Blueprintable)
class CUSTOMREPLICATION_API ATestActor : public AActor
{
	GENERATED_BODY()

	float TimeSinceDataGenerated;
	
public:	
	ATestActor();
	virtual void Tick(float DeltaSeconds) override;

	virtual void GenerateData(int32 Size);
	virtual int32 GetValue() const;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DataSize = 100;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UTextRenderComponent* Text;
};

