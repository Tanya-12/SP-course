// SPLab5_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Сomputation.h"
#define TH_COUNT 3

int main()
{
	HANDLE hThread[TH_COUNT];
	DWORD ThreadId;
	clock_t start, finish;
	double duration;

	GenerateArray();

	printf("Critical section mode\n");
	start = clock();
	hThread[0] = CreateThread(NULL, 0, SumArr, (LPVOID)0, 0, &ThreadId);
	hThread[1] = CreateThread(NULL, 0, AvgArr, (LPVOID)0, 0, &ThreadId);
	hThread[2] = CreateThread(NULL, 0, MaxArr, (LPVOID)0, 0, &ThreadId);
	WaitForMultipleObjects(TH_COUNT, hThread, TRUE, INFINITE);
	finish = clock();
	duration = finish - start;
	printf("Run time: %f\n", duration);

	DeleteCriticalSection();
	for (int i = 0; i < TH_COUNT; i++)
	{
		CloseHandle(hThread[i]);
	}

	printf("\nNot critical section mode\n");
	start = clock();
	hThread[0] = CreateThread(NULL, 0, SumArr, (LPVOID)1, 0, &ThreadId);
	hThread[1] = CreateThread(NULL, 0, AvgArr, (LPVOID)1, 0, &ThreadId);
	hThread[2] = CreateThread(NULL, 0, MaxArr, (LPVOID)1, 0, &ThreadId);
	WaitForMultipleObjects(TH_COUNT, hThread, TRUE, INFINITE);
	finish = clock();
	duration = finish - start;
	printf("Run time: %f\n", duration);

	DeleteCriticalSection();
	for (int i = 0; i < TH_COUNT; i++)
	{
		CloseHandle(hThread[i]);
	}
    return 0;
}

