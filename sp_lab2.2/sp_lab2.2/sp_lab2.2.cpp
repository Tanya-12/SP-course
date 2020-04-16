

#include "stdafx.h"

void readline(char str[], int str_len);

struct header
{
	int countRecords;
	DWORD size;
};

struct record
{		
	int num;		
	int countChanges;
	char text[80];
};
int start = sizeof(header);

void inline myfunc(HANDLE hFile,long offset,DWORD dwRead,record newRec)
{
	SetFilePointer(hFile,offset,0,FILE_BEGIN);
	WriteFile(hFile, &newRec, sizeof(record), &dwRead, NULL);
//	SetFilePointer(hFile,start,0,FILE_BEGIN);
}

int _tmain(int argc, _TCHAR* argv[])
{	
	record *recs, out[100], newRec;
	header head;
	int numOfStruct,command;
	DWORD dwRead;
	int choose;
	long offset;
	char newText[80];	
	HANDLE hFile = CreateFile(L"records.txt",GENERIC_READ| GENERIC_WRITE,NULL,NULL,OPEN_EXISTING,NULL,0);
	if(hFile!=INVALID_HANDLE_VALUE)
	{
		ReadFile(hFile,&head,sizeof(head),&dwRead,0);
		ReadFile(hFile,&out,head.size-start,&dwRead,0);
		for (int i = 0; i < head.countRecords; i++) 
		{ 			
			printf("Record: %i\n",out[i].num);
			printf("Text: %s\n",out[i].text);
			printf("Changes: %i\n\n",out[i].countChanges);

		}	
		for(;;)
		{
			ReadFile(hFile,&out,head.size-start,&dwRead,0);
			puts("Choose record:");
			scanf_s("%i",&choose);
			if(choose>head.countRecords||choose<0)
			{
				printf("Input value from 1 to %i\n",head.countRecords);
				continue;
			}
			puts("What do you want to do with record:\n1-view\n2-change\n3-clear\n4-quit\n");
			scanf_s("%i",&command);
			fflush(stdin);
			memset(newRec.text,0,sizeof(char[80]));
			newRec.num=out[choose-1].num;
			newRec.countChanges=out[choose-1].countChanges;
			switch (command)
			{
			case 1: 
				printf("Record: %i\n",out[choose-1].num);
				printf("Text: %s\n",out[choose-1].text);
				printf("Changes: %i\n\n",out[choose-1].countChanges);
				break;
			case 2: 
				newRec.countChanges = out[choose-1].countChanges+1;
				puts("Input new text:");
				readline(newText, 80);
				//gets_s(newText);
				//fflush(stdin);
				strcpy(newRec.text,newText);	
				offset = start+(choose-1)*sizeof(record);
				myfunc(hFile,offset,dwRead,newRec);
				break;
			case 3: 
				newRec.countChanges = out[choose-1].countChanges+1;
				offset = start+(choose-1)*sizeof(record);	
				myfunc(hFile,offset,dwRead,newRec);
				break;
			case 4: 
				return 0;
			default:
				puts("There is no command like this");
				break;
			}	
		}
		CloseHandle(hFile);
	}
	else
	{	
		HANDLE hFile = CreateFile(L"records.txt", GENERIC_WRITE, NULL, NULL, CREATE_NEW, NULL, 0);
		puts("Hello, input how many records must be in new the file: ");
		scanf_s("%i",&numOfStruct);
		if(numOfStruct<0)
		{
			puts("Input value more then zero");
			return 0;
		}
		head.countRecords=numOfStruct;
		head.size = sizeof(header)+numOfStruct*sizeof(record);
		WriteFile(hFile, &head, sizeof(header), &dwRead, NULL);		
		recs = (record *)malloc(sizeof(record)*numOfStruct);
		for (int i = 0; i < numOfStruct; i++) { 
			memset(recs[i].text,0,sizeof(char[80]));
			recs[i].num = (i+1); 
			recs[i].countChanges = 0; 
			WriteFile(hFile, &recs[i], sizeof(recs[i]), &dwRead, NULL); 
		}		
		puts("Records created");
		CloseHandle(hFile);
	}
	return 0;
}

void readline(char str[], int str_len)
{
	int i = 0, ch;
	while (isspace(ch = getchar()));
	while (ch != '\n')
	{
		if (i < str_len)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
}