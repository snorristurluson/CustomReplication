#include "TestStruct.h"

int32 FTestStruct::GetValue() const
{
	if (Data)
	{
		return Data[0];
	}
	
	return -1;
}

void FTestStruct::GenerateData(int32 Size)
{
	if (Data)
	{
		delete [] Data;
		Data = nullptr;
	}

	DataSize = Size;
	int32 Value = FMath::RandRange(0, 5);

	Data = new uint8[DataSize];
	for (int Index = 0; Index < DataSize; ++Index)
	{
		Data[Index] = Value;
	}

	++Version;
}

bool FTestStruct::NetSerialize(FArchive& Ar, UPackageMap* Map, bool& bOutSuccess)
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
			const int32 IntValue = Data[0];
			for (int Index = 0; Index < DataSize; ++Index)
			{
				check(Data[Index] == IntValue);
			}
		}
	}

	bOutSuccess = true;
	return true;
}

