#include "stdafx.h"

int Split(char*a,char**b,char*c);
bool checkPath(char* curDir,char* src);
void ls(char*);
void cd(char*,char**);
void mkdir(char*,char**);
void rmdir(char*,char**);
void rmfile(char*,char**);
void cp(char*,char**);
void finfo(char**);

char startDir[100];

int main(int argc, char* argv[])
{
	
	char commands[7][7] = {"cd","ls","mkdir","rmdir","rmfile","cp", "finfo"};
	char descriptions[7][70] = {"(path) - change directory","(path) - print all files and directoryes","(folder) - create new folder",
		"(folder) - delete folder","(file) - delete file","(source,destination) - copy from source to destination",
		"(file) - print info about file"};
	char command[100];
	char* arr[10];
	char curDir[100],tmpDir[100],tmpPath[100];
	int count;
	char *direction;
	int idCmd;
	SetCurrentDirectoryA("WorkingDir");
	GetCurrentDirectoryA(255,curDir);
	strcpy(startDir, curDir);
	puts("Commands:");
	for (int i = 0; i < 7; i++)
	{
		printf("%s %s\n",commands[i],descriptions[i]);
	}
	puts("");
	for(;;)
	{		
		GetCurrentDirectoryA(255,curDir);
		printf("%s: ",curDir);
		gets_s(command);
		count = Split(command,arr," ");
		idCmd=-1;
		for (int i = 0; i < 7; i++)
		{
			char *a = commands[i];
			if (strcmp(command,commands[i])==0)
			{
				idCmd = i;
				break;
			}
		}
		switch (idCmd)
		{
		case 0:
			if(count>2)
				puts("Invalid arguments count");
			else if(count==2)
			{
				cd(curDir,arr);
			}
			else
			{
				SetCurrentDirectoryA(startDir);
			}
			break;
		case 1:
			if(count!=2)
				puts("Invalid arguments count");
			else 			
			{
				Split(command,arr," ");
				ls(arr[1]);
			}
			break;
		case 2:
			if(count!=2)
				puts("Invalid arguments count");
			else
			{	
				mkdir(curDir,arr);
			}
			break;
		case 3:
			if(count!=2)
				puts("Invalid arguments count");
			else
			{
				rmdir(curDir,arr);
			}
			break;			
		case 4:			
			if(count!=2)
				puts("Invalid arguments count");
			else
			{
				rmfile(curDir,arr);
			}
			break;			
		case 5:			
			if(count!=3)
				puts("Invalid arguments count");
			else
			{
				cp(curDir,arr);
			}
			break;			
		case 6:			
			if(count!=2)
				puts("Invalid arguments count");
			else
			{
				finfo(arr);
			}
			break;
		default:
			puts("Command is not exist");
			break;
		}
	}
	return 0;
}

int Split(char* str, char**arr,char* splitter)
{
	int count=0;
	char* dst;
	dst = strtok(str,splitter);
	while (dst != NULL && count < 10)                         
	{
		arr[count] = dst;
		dst = strtok (NULL, splitter);
		count++;
	}
	return count;
}

bool checkPath(char* curDir,char* src)
{
	bool ret;
	char tmp[100];
	char* arr[10];
	char separator[10];
	strcpy(tmp,curDir);
	strcpy(tmp,"");
	if(strstr(src,"\\")!=NULL||strstr(src,"/")!=NULL)
	{
		if(strstr(src,"\\")!=NULL)
		{
			strcpy(separator,"\\");
		}
		else
		{
			strcpy(separator,"/");
		}
	}
	for (int i = 0; i < Split(src,arr,separator)-1; i++)
	{
		strcat(tmp,arr[i]);
		strcat(tmp,separator);
	}
	SetCurrentDirectoryA(tmp);
	GetCurrentDirectoryA(100,tmp);
	if(strstr(tmp,startDir)==NULL)
	{
		ret = false;
	}
	else
	{
		ret = true;
	}	
	SetCurrentDirectoryA(curDir);
	return ret;
}

void ls(char* dir)
{
	printf("Directories: \n");
	WIN32_FIND_DATA fd;
	LARGE_INTEGER filesize;
	SYSTEMTIME sTime;
	HANDLE fp;
	wchar_t wdir[100];
	MultiByteToWideChar(GetACP(),0,dir,-1,wdir,strlen(dir)*2+2);
	wcscat(wdir,L"/*");
	fp = FindFirstFile(wdir,&fd);
	if(fp==INVALID_HANDLE_VALUE)
	{
		exit(0);
	}	
	do
	{
		puts("____________________________________________");
		if(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			_tprintf(L"%s   <DIR>\n",fd.cFileName);
		else
			_tprintf(L"%s   <FILE>\n",fd.cFileName);

		filesize.LowPart = fd.nFileSizeLow;
		filesize.HighPart = fd.nFileSizeHigh;
		FileTimeToSystemTime(&fd.ftCreationTime,&sTime);
		printf("Size of file: %ld byte\n",filesize);
		printf("Creation time: %ld.%ld.%ld  %ld:%ld:%ld\n",sTime.wDay,sTime.wMonth,sTime.wYear,sTime.wHour,sTime.wMinute,sTime.wSecond);		
	}
	while (FindNextFile(fp,&fd)!=0);
	FindClose(fp);
}

void cd(char* curDir, char** arr)
{
	char tmpDir[100];
	strcpy(tmpDir,curDir);
	if(!SetCurrentDirectoryA(arr[1]))
	{
		puts("Enter valid path!");
	}
	else 
	{
		GetCurrentDirectoryA(255,curDir);
		if(strstr(curDir,startDir)==NULL)
		{
			puts("Access denied!");
			

			strcpy(curDir, startDir);
			SetCurrentDirectoryA(curDir);
			
		}
	}
}

void mkdir(char* curDir, char** arr)
{
	char tmpDir[100],tmpPath[100];
	strcpy(tmpDir,curDir);
	strcpy(tmpPath,arr[1]);
	if(!checkPath(curDir,arr[1]))
	{
		puts("Access denied!");
		strcpy(curDir,tmpDir);						
		SetCurrentDirectoryA(curDir);
	}
	else
		if(!CreateDirectoryA(tmpPath,0))
			puts("Could not create folder!");
		else
			puts("New foder was created!");
}

void rmdir(char* curDir, char** arr)
{
	char tmpDir[100],tmpPath[100];
	strcpy(tmpDir,curDir);
	strcpy(tmpPath,arr[1]);
	if(!checkPath(curDir,arr[1]))
	{
		puts("Access denied!");
		strcpy(curDir,tmpDir);						
		SetCurrentDirectoryA(curDir);
	}
	else
		if(!RemoveDirectoryA(tmpPath))
		{
			puts("Could not delete folder!");
		}
		else
			puts("Folder was deleted!");
}

void rmfile(char* curDir, char** arr)
{
	char tmpDir[100],tmpPath[100];
	strcpy(tmpDir,curDir);
	strcpy(tmpPath,arr[1]);
	if(!checkPath(curDir,arr[1]))
	{
		puts("Access denied!");
		strcpy(curDir,tmpDir);						
		SetCurrentDirectoryA(curDir);
	}
	else
		if(!DeleteFileA(tmpPath))
		{
			puts("Could not delete file!");
		}
		else
			puts("File was deleted!");				
}

void cp(char* curDir,char** arr)
{
	char tmpDir[100],tmpPath[100];
	strcpy(tmpDir,arr[1]);
	strcpy(tmpPath,arr[2]);
	if(!checkPath(curDir,arr[1])||!checkPath(curDir,arr[2]))
	{
		puts("Access denied!");
	}
	else
		if(!CopyFileA(tmpDir,tmpPath,true))
		{
			puts("Could not copy file!");
		}
		else
			puts("File was copied!");		
}

void finfo(char** arr)
{
	SYSTEMTIME sTime;
	LARGE_INTEGER filesize;
	int locCount;
	HANDLE hFile = CreateFileA(arr[1],GENERIC_READ, FILE_SHARE_READ,NULL,OPEN_EXISTING,0,0);
	
	BY_HANDLE_FILE_INFORMATION info;
	GetFileInformationByHandle(hFile,&info);
	locCount = Split(arr[1],arr,"\\");
	filesize.LowPart = info.nFileSizeLow;
	filesize.HighPart = info.nFileSizeHigh;
	printf("Size of file: %ld byte\n",filesize);
	FileTimeToSystemTime(&info.ftCreationTime,&sTime);
	printf("Creation time: %ld.%ld.%ld  %ld:%ld:%ld\n",sTime.wDay,sTime.wMonth,sTime.wYear,sTime.wHour,sTime.wMinute,sTime.wSecond);
	FileTimeToSystemTime(&info.ftLastAccessTime,&sTime);
	printf("Last access time: %ld.%ld.%ld  %ld:%ld:%ld\n",sTime.wDay,sTime.wMonth,sTime.wYear,sTime.wHour,sTime.wMinute,sTime.wSecond);
	FileTimeToSystemTime(&info.ftLastWriteTime,&sTime);
	printf("Last write time: %ld.%ld.%ld  %ld:%ld:%ld\n",sTime.wDay,sTime.wMonth,sTime.wYear,sTime.wHour,sTime.wMinute,sTime.wSecond);
	printf("Number of links: %ld\n",info.nNumberOfLinks);

}