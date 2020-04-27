// SPLab5_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#define THREAD_COUNT 5

HANDLE semaphore;

DWORD WINAPI WriteRunTime(LPVOID lpParam)
{
	DWORD waitResult;
	DWORD numberOfBytesWritten;
	HANDLE hFile;
	clock_t start, finish;
	double duration;
	char *strToWrite = new char[10];
	bool run = TRUE;

	waitResult = WaitForSingleObject(semaphore, 3);
	while (run == true)
	{
		if (waitResult == WAIT_OBJECT_0)
		{
			start = clock();
			printf("%d in critical section\n", GetCurrentThreadId());
			hFile = CreateFile(L"run time.txt", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			finish = clock();

			duration = (double)(finish - start) / CLOCKS_PER_SEC;

			SetFilePointer(hFile, 0, NULL, FILE_END);
			sprintf(strToWrite, "%2.3f seconds", duration);
			WriteFile(hFile, strToWrite, sizeof(strToWrite), &numberOfBytesWritten, NULL);

			if (hFile == INVALID_HANDLE_VALUE)
			{
				printf("Error!");
			}
			run = FALSE;
			Sleep(5*1000);
			printf("%d leave critical section\n", GetCurrentThreadId());
			if (!ReleaseSemaphore(semaphore, 1, NULL))
			{
				printf("Release Semaphore error: %d\n", GetLastError());
			}
		}
	}
	
	return TRUE;
}

int main()
{
	HANDLE hThread[THREAD_COUNT];
	DWORD threadId;

	semaphore = CreateSemaphore(NULL, 2, 2, NULL);
	if (semaphore == NULL)
	{
		printf("Create Semaphore error: %d\n", GetLastError());
		return 1;
	}

	for (int i = 0; i < THREAD_COUNT; i++)
	{
		hThread[i] = CreateThread(NULL, 0, WriteRunTime, NULL, 0, &threadId);

		if (hThread[i] == NULL)
		{
			printf("CreateThread error: %d\n", GetLastError());
			return 1;
		}
	}
	WaitForMultipleObjects(THREAD_COUNT, hThread, TRUE, INFINITE);

	for (int i = 0; i < THREAD_COUNT; i++)
		CloseHandle(hThread[i]);

	CloseHandle(semaphore);

	return 0;
}

