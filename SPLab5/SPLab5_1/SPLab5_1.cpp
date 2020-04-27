// SPLab5_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	HANDLE hMutex = CreateMutex(0,0,TEXT("Mutex"));
	DWORD result = WaitForSingleObject(hMutex,0);
	if (result != WAIT_OBJECT_0)
	{
		printf("Application is already inuse");
		//MessageBox(0, L"Application is already inuse", 0, MB_OK);
		return 0;
	}
	else
	{
		printf("Is running");
		while (1){}
		
	}

    return 0;
}

