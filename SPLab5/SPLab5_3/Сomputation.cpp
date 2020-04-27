#include "stdafx.h"
#include "Сomputation.h"
#define CRITICAL_MODE 0
#define NONCRITICAL_MODE 1
#define ARR_SIZE 10000000


int arr[ARR_SIZE];
CRITICAL_SECTION CriticalSection;


DWORD WINAPI SumArr(LPVOID mode)
{
	if (!InitializeCriticalSectionAndSpinCount(&CriticalSection, 0x00000400))
	{
		return 0;
	}
	switch ((int)mode)
	{
	case CRITICAL_MODE:
		EnterCriticalSection(&CriticalSection);
		Sum();
		LeaveCriticalSection(&CriticalSection);
		break;
	case NONCRITICAL_MODE:
		Sum();
		break;
	default:
		puts("Error!");
		break;
	}
	return 0;
}

DWORD WINAPI AvgArr(LPVOID mode)
{
	if (!InitializeCriticalSectionAndSpinCount(&CriticalSection, 0x00000400))
	{
		return 0;
	}
	switch ((int)mode)
	{
	case CRITICAL_MODE:
		EnterCriticalSection(&CriticalSection);
		Avg();
		LeaveCriticalSection(&CriticalSection);
		break;
	case NONCRITICAL_MODE:
		Avg();
		break;
	default:
		puts("Error!");
		break;
	}
	return 0;
}

DWORD WINAPI MaxArr(LPVOID mode)
{
	if (!InitializeCriticalSectionAndSpinCount(&CriticalSection, 0x00000400))
	{
		return 0;
	}
	switch ((int)mode)
	{
	case CRITICAL_MODE:
		EnterCriticalSection(&CriticalSection);
		Max();
		LeaveCriticalSection(&CriticalSection);
		break;
	case NONCRITICAL_MODE:
		Max();
		break;
	default:
		puts("Error!");
		break;
	}
	return 0;
}

void Sum()
{
	int sum = 0;
	for (int i = 0; i < ARR_SIZE; i++)
	{
		sum += arr[i];
	}
	printf("Sum: %d\n", sum);
}

void Avg()
{
	double avg = 0;
	for (int i = 0; i < ARR_SIZE; i++)
	{
		avg += arr[i];
	}
	printf("Avarage value: %f\n", avg / ARR_SIZE);
}

void Max()
{
	int max = 0;
	for (int i = 0; i < ARR_SIZE; i++)
	{
		if (max<arr[i])
			max = arr[i];
	}
	printf("Max value: %d\n", max);
}

void GenerateArray()
{
	for (int i = 0; i < ARR_SIZE; i++)
	{
		arr[i] = rand() % 100;
	}
}

void DeleteCriticalSection()
{
	DeleteCriticalSection(&CriticalSection);
}