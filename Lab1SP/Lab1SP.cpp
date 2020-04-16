// Lab1SP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <strsafe.h>

#define DIV 1024
#define WIDTH 7

int main(int argc, char *argv[])
{
	LPTSTR pszBuf = NULL;
	DWORD dw;
	if (argc > 0)
	{
		if (strcmp(argv[1], "e"))
		{
			pszBuf = (LPTSTR)LocalAlloc(
				LPTR,
				INT_MAX);

			LPVOID lpMsgBuf;
			LPVOID lpDisplayBuf;
			dw = GetLastError();

			FormatMessage(
				FORMAT_MESSAGE_ALLOCATE_BUFFER |
				FORMAT_MESSAGE_FROM_SYSTEM |
				FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL,
				dw,
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
				(LPTSTR)&lpMsgBuf,
				0, NULL);


			// Display the error message and exit the process

			lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
				(lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)pszBuf) + 40) * sizeof(TCHAR));

			StringCchPrintf((LPTSTR)lpDisplayBuf,
				LocalSize(lpDisplayBuf) / sizeof(TCHAR),
				TEXT("%s failed with error %d: %s"),
				pszBuf, dw, lpMsgBuf);

			_tprintf((LPCTSTR)lpDisplayBuf, TEXT("Error"));

			LocalFree(lpMsgBuf);
			LocalFree(lpDisplayBuf);
			ExitProcess(dw);
		}
		else if (strcmp(argv[1], "s"))
		{
			MEMORYSTATUSEX statex;

			statex.dwLength = sizeof(statex);

			GlobalMemoryStatusEx(&statex);
			_tprintf(TEXT("There is  %*ld percent of memory in use.\n"),
				WIDTH, statex.dwMemoryLoad);
			_tprintf(TEXT("There are %*I64d total KB of physical memory.\n"),
				WIDTH, statex.ullTotalPhys / DIV);
			_tprintf(TEXT("There are %*I64d free  KB of physical memory.\n"),
				WIDTH, statex.ullAvailPhys / DIV);
			_tprintf(TEXT("There are %*I64d total KB of paging file.\n"),
				WIDTH, statex.ullTotalPageFile / DIV);
			_tprintf(TEXT("There are %*I64d free  KB of paging file.\n"),
				WIDTH, statex.ullAvailPageFile / DIV);
			_tprintf(TEXT("There are %*I64d total KB of virtual memory.\n"),
				WIDTH, statex.ullTotalVirtual / DIV);
			_tprintf(TEXT("There are %*I64d free  KB of virtual memory.\n"),
				WIDTH, statex.ullAvailVirtual / DIV);
		}
		
	}
	
	return 0;
}

