#pragma once

#include "CoreMinimal.h"
#include "TestStruct.generated.h"

USTRUCT(BlueprintType)
struct FTestStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Version = 0;
	
	int32 DataSize = 0;
	uint8* Data = nullptr;

	int32 GetValue() const;
	void GenerateData(int32 Size);
	
	bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess);
};

template<>
struct TStructOpsTypeTraits<FTestStruct> : TStructOpsTypeTraitsBase2<FTestStruct>
{
	enum
	{
		WithNetSerializer = true,
	};
};

