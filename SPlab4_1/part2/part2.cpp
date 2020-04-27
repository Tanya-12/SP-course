// part2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "functions.h"

DWORD arrId;

int main(int argc, char *argv[])
{
	int* arr;
	DWORD threadId;
	arrId = TlsAlloc();

	//int count = (int)argv[1];
	int count = 5;
	for (int i = 0; i < count; i++)
	{
		arr = getArray(ARR_SIZE);
		CreateThread(NULL, 0, getMaxDivider, arr, 0, &threadId);
	}


	TlsFree(arrId);
    return 0;
}

