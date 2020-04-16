// Part2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc > 1)
	{
		HANDLE hFile;
		HANDLE hAppend;
		DWORD  dwBytesRead, dwBytesWritten, dwPos;
		BYTE   buff[4096];
		BYTE   buffWrite[4096];


		// Open the existing file.
		hFile = CreateFile(argv[1], // open One.txt
			GENERIC_READ,             // open for reading
			0,                        // do not share
			NULL,                     // no security
			OPEN_EXISTING,            // existing file only
			FILE_ATTRIBUTE_NORMAL,    // normal file
			NULL);                    // no attr. template

		if (hFile == INVALID_HANDLE_VALUE)
		{
			printf("Could not open text.txt.");
			return 1;
		}

		
		hAppend = CreateFile(argv[3], // open Two.txt
			GENERIC_WRITE,         // open for writing
			FILE_SHARE_READ,          // allow multiple readers
			NULL,                     // no security
			CREATE_ALWAYS,              // open or create
			FILE_ATTRIBUTE_NORMAL,    // normal file
			NULL);                    // no attr. template

		if (hAppend == INVALID_HANDLE_VALUE)
		{
			printf("Could not open Two.txt.");
			return 1;
		}

		// Append the first file to the end of the second file.
		// Lock the second file to prevent another process from
		// accessing it while writing to it. Unlock the
		// file when writing is complete.
		if (wcscmp(argv[2], L"a") == 0)
		{
			while (ReadFile(hFile, buff, sizeof(buff), &dwBytesRead, NULL)
				&& dwBytesRead > 0)
			{
				dwPos = SetFilePointer(hAppend, 0, NULL, FILE_END);
				int out = WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, (LPCWCH)buff, dwBytesRead/sizeof(wchar_t),
					(LPSTR)buffWrite, 4096, NULL, NULL);
				WriteFile(hAppend, buff, dwBytesRead, &dwBytesWritten, NULL);
			}
		}
		else if (wcscmp(argv[2], L"u")== 0)
		{
			while (ReadFile(hFile, buff, sizeof(buff), &dwBytesRead, NULL)
				&& dwBytesRead > 0)
			{
				dwPos = SetFilePointer(hAppend, 0, NULL, FILE_END);
				int out = MultiByteToWideChar(CP_ACP, WC_COMPOSITECHECK, (LPSTR)buff, dwBytesRead / sizeof(wchar_t),
					(LPWSTR)buffWrite, 4096);
				WriteFile(hAppend, buff, dwBytesRead, &dwBytesWritten, NULL);
			}
		}
		
		// Close both files.

		CloseHandle(hFile);
		CloseHandle(hAppend);

	}
    return 0;
}

