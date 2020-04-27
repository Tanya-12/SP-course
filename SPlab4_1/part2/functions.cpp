#include "stdafx.h"
#include "functions.h"

DWORD WINAPI getMaxDivider(LPVOID lpParam)
{
	int *maxDividers = (int*)lpParam;

	TlsSetValue(arrId, maxDividers);

	printf("SUM:%d\nID: %d\n", getSum(), GetCurrentThreadId());
	return 0;
}
int getSum()
{
	int* arr = (int *)TlsGetValue(arrId);
	int sum = 0;
	for (int i = 0; i < ARR_SIZE; i++)
	{
		sum += arr[i];
	}
	return sum;
}
int* getArray(int size)
{
	
	int *arr = (int*)malloc(size * sizeof(*arr));
	for (int i = 0; i < size; i++)
	{
		arr[i] = 1 + rand() % 5;
		//printf("%d ", arr[i]);
	}
	//printf("\n");
	return arr;
}