#include "stdafx.h"
#include "Options.h"

void archive(LPCTSTR lpPathName, LPCTSTR lpOutArchivePath)
{
	int iMaxLen = lstrlen(lpPathName) + lstrlen(lpOutArchivePath) + lstrlen(ZIP_PATH) + 20;
	wchar_t* buf = new wchar_t[iMaxLen];
	swprintf(buf, iMaxLen, L"\"%s\" a \"%sarc.7z\" \"%s\"", ZIP_PATH, lpOutArchivePath, lpPathName);

	zipWork(buf);

}
void extract(LPCTSTR lpArchivePath, LPCTSTR lpOutPathName)
{
	int iMaxLen = lstrlen(lpArchivePath) + lstrlen(lpOutPathName) + lstrlen(ZIP_PATH) + 20;
	wchar_t* buf = new wchar_t[iMaxLen];
	swprintf(buf, iMaxLen, L"\"%s\" x \"%s\" -o\"%s\" *.* -r", ZIP_PATH, lpArchivePath, lpOutPathName);

	zipWork(buf);
}

void zipWork(wchar_t* strCom)
{
	bool result = true;
	HANDLE hInRead;
	HANDLE hInWrite;

	HANDLE hOutRead;
	HANDLE hOutWrite;

	SECURITY_ATTRIBUTES sa;

	sa.bInheritHandle = TRUE;
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;

	CreatePipe(&hInRead, &hInWrite, &sa, 0);
	CreatePipe(&hOutRead, &hOutWrite, &sa, 0);

	if (hInRead == INVALID_HANDLE_VALUE ||
		hInWrite == INVALID_HANDLE_VALUE ||
		hOutRead == INVALID_HANDLE_VALUE ||
		hOutWrite == INVALID_HANDLE_VALUE)
	{
		printf("Invalid handles\n\n");
		result = false;
	}

	STARTUPINFO si;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	si.hStdOutput = hOutWrite;
	si.hStdError = hOutWrite;
	si.hStdInput = hInRead;
	si.dwFlags |= STARTF_USESTDHANDLES;

	_tprintf(TEXT("%s"), strCom);

	PROCESS_INFORMATION pi;

	ZeroMemory(&pi, sizeof(pi));

	if (CreateProcess(NULL, strCom, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi))
	{
		WaitForSingleObject(pi.hProcess, INFINITE);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		ReadFile()

	}
	
}