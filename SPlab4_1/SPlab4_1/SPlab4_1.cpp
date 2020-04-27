// SPlab4_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "options.h"


int main()
{
	char user_answer[3];
	wchar_t pathfrom[200];
	wchar_t pathto[200];
	printf("options:\n1-archive file\n2-extract files\n");
	gets_s(user_answer);
	switch (user_answer[0])
	{
	case '1': 
		printf("enter file path to archive\n");
		_getws_s(pathfrom);
		printf("enter file out directory path\n");
		_getws_s(pathto);
		archive(pathfrom, pathto);
		break;
	case '2':
		printf("enter file path to extract\n");
		_getws_s(pathfrom);
		printf("enter out directory path\n");
		_getws_s(pathto);
		extract(pathfrom, pathto);
		break;
	default:
		printf("comand is not exist");
		break;
	}

	
    return 0;
}


//#define COMMAND_LENGTH 20
//#define STDOUT_BUFFER_SIZE 1024
//#define MAX_ADDING_FILES_COUNT 20
//
//BOOL ProcessCommand(LPSTR command);
//
//void PrintHelp();
//
//bool Archive();
//void Dearchive();
//
//LPSTR currentFolder;
//
//int main(int argc, char *argv[])
//{
//	printf("Allows to pack one file and unpack archive with several files.");
//
//	LPSTR command = new CHAR[COMMAND_LENGTH];
//
//	currentFolder = new CHAR[MAX_PATH];
//	GetCurrentDirectoryA(MAX_PATH, currentFolder);
//
//	while (ProcessCommand(command))
//	{
//
//	}
//
//	//system("pause");
//	return 0;
//}
//
//BOOL ProcessCommand(LPSTR command)
//{
//	BOOL result = true;
//
//
//	/*if (PathFileExists("7z.exe") == FALSE)
//	{
//		printf("7z.exe does not exist.\n\n");
//		return false;
//	}*/
//
//	printf("\nEnter command or type 'help': ");
//	scanf("%s", command);
//
//	if (strncmp(command, "exit", COMMAND_LENGTH) == 0)
//	{
//		result = false;
//		printf("\n");
//	}
//	else if (strncmp(command, "a", COMMAND_LENGTH) == 0)
//	{
//		result = Archive();
//	}
//	else if (strncmp(command, "da", COMMAND_LENGTH) == 0)
//	{
//		Dearchive();
//	}
//	else
//	{
//		PrintHelp();
//	}
//
//	return result;
//}
//
//bool Archive()
//{
//	bool result = true;
//
//	LPSTR *inputFiles = new CHAR*[MAX_ADDING_FILES_COUNT];
//	LPSTR archiveName = new CHAR[MAX_PATH];
//
//	int inputFilesCount = 0;
//
//	printf("\nSelect files to be archived.\n\n");
//
//	// Set files to archive.
//
//	LPSTR fileName = new CHAR[MAX_PATH];
//
//	while (1)
//	{
//		printf("File name to archive (-1 to end): ");
//		scanf("%s", fileName);
//
//		if (strncmp(fileName, "-1", MAX_PATH) == 0)
//		{
//			break;
//		}
//
//		inputFiles[inputFilesCount] = new CHAR[MAX_PATH];
//		strcpy(inputFiles[inputFilesCount], fileName);
//
//		inputFilesCount++;
//	}
//
//	// Set output archive name.
//
//	printf("Enter the name of output archive: ");
//	scanf("%s", archiveName);
//
//	// Create PIPE.
//
//	HANDLE hInRead;
//	HANDLE hInWrite;
//
//	HANDLE hOutRead;
//	HANDLE hOutWrite;
//
//	SECURITY_ATTRIBUTES sa;
//
//	sa.bInheritHandle = TRUE;
//	sa.nLength = sizeof(sa);
//	sa.lpSecurityDescriptor = NULL;
//
//	CreatePipe(&hInRead, &hInWrite, &sa, 0);
//	CreatePipe(&hOutRead, &hOutWrite, &sa, 0);
//
//	if (hInRead == INVALID_HANDLE_VALUE ||
//		hInWrite == INVALID_HANDLE_VALUE ||
//		hOutRead == INVALID_HANDLE_VALUE ||
//		hOutWrite == INVALID_HANDLE_VALUE)
//	{
//		printf("Invalid handles\n\n");
//		result = false;
//	}
//
//	// Init process info.
//
//	STARTUPINFOA si;
//	ZeroMemory(&si, sizeof(si));
//	si.cb = sizeof(si);
//	si.hStdOutput = hOutWrite;
//	si.hStdError = hOutWrite;
//	si.hStdInput = hInRead;
//	si.dwFlags |= STARTF_USESTDHANDLES;
//
//	PROCESS_INFORMATION pi;
//	ZeroMemory(&pi, sizeof(pi));
//
//	// Format the command line.
//
//	LPSTR cmdLine = new CHAR[MAX_PATH];
//	ZeroMemory(cmdLine, MAX_PATH);
//
//	strncpy(cmdLine, "7z.exe a ", MAX_PATH - strlen(cmdLine));
//	strncat(cmdLine, archiveName, MAX_PATH - strlen(cmdLine));
//
//	for (int i = 0; i < inputFilesCount; i++)
//	{
//		strncat(cmdLine, " ", MAX_PATH - strlen(cmdLine));
//
//		strncat(cmdLine, inputFiles[i], MAX_PATH - strlen(cmdLine));
//	}
//
//	strncat(cmdLine, " ", MAX_PATH - strlen(cmdLine));
//
//	// Start process.
//
//	if (!CreateProcessA(NULL, cmdLine, NULL, NULL, TRUE, NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi))
//	{
//		printf("Error while creating 7z.exe process.\n\n");
//		result = false;
//	}
//
//	if (result)
//	{
//		printf("\n");
//		printf("Process started...\n");
//		printf("Process finished successfully");
//
//		// Read stdout.
//
//		WaitForSingleObject(pi.hProcess, INFINITE);
//
//		DWORD readBytes = 0;
//		LPSTR outBuff = new CHAR[STDOUT_BUFFER_SIZE];
//		ZeroMemory(outBuff, STDOUT_BUFFER_SIZE);
//		OVERLAPPED overl;
//		ReadFile(hOutRead, outBuff, STDOUT_BUFFER_SIZE, &readBytes, &overl);
//
//		printf("%s", outBuff);
//
//		CloseHandle(pi.hProcess);
//		CloseHandle(pi.hThread);
//	}
//
//	CloseHandle(hOutRead);
//	CloseHandle(hOutWrite);
//
//	CloseHandle(hInRead);
//	CloseHandle(hInWrite);
//
//	return result;
//}
//
//void Dearchive()
//{
//	LPSTR inputFileName = new CHAR[MAX_PATH];
//	LPSTR outputFolder = new CHAR[MAX_PATH];
//
//	printf("Select archive to be dearchived: ");
//	scanf("%s", inputFileName);
//
//	printf("Select output directory: ");
//	scanf("%s", outputFolder);
//
//	LPSTR cmdLine = new CHAR[MAX_PATH];
//	ZeroMemory(cmdLine, MAX_PATH);
//
//	strncpy(cmdLine, "7z.exe e ", MAX_PATH - strlen(cmdLine));
//	strncat(cmdLine, inputFileName, MAX_PATH - strlen(cmdLine));
//
//	strncat(cmdLine, " -o", MAX_PATH - strlen(cmdLine));
//	strncat(cmdLine, outputFolder, MAX_PATH - strlen(cmdLine));
//
//	strncat(cmdLine, " -y", MAX_PATH - strlen(cmdLine));
//
//	STARTUPINFOA si;
//	ZeroMemory(&si, sizeof(si));
//	si.cb = sizeof(si);
//	//si.hStdOutput = hOutWrite;
//	//si.hStdError = hOutWrite;
//	//si.hStdInput = hInRead;
//	si.dwFlags |= STARTF_USESTDHANDLES;
//
//	PROCESS_INFORMATION pi;
//	ZeroMemory(&pi, sizeof(pi));
//
//	//printf("%s\n", cmdLine);
//
//	// Start process.
//
//	if (!CreateProcessA(NULL, cmdLine, NULL, NULL, TRUE, NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi))
//	{
//		printf("Error while creating 7z.exe process.\n\n");
//	}
//}
//
//void PrintHelp()
//{
//	printf(" - 'exit' \t: exit from program\n");
//	printf(" - 'a'  \t: start archiving session\n");
//	printf(" - 'da' \t: start dearchiving session\n");
//}
