// SP_lab0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <limits.h> 
#include <float.h> 

int main()
{
	printf("\nBYTE\t\nlength - %d\tMIN value: %d\tMAX value: %d", sizeof(BYTE), (BYTE)0x0, (BYTE)0x7f);
	printf("\n\nCHAR\t\nlength - %d\tMIN value: %d\tMAX value: %d", sizeof(CHAR), (CHAR)0x80, (CHAR)0x7f);
	printf("\n\nBOOLEAN\t\nlength - %d\tMIN value: %hhd\tMAX value: %d", sizeof(BOOLEAN), (BOOLEAN)0x80, (BOOLEAN)0x7f);
	
	printf("\n\nWORD\t\nlength - %d\tMIN value: %d\tMAX value: %d", sizeof(WORD), 0, (WORD)0xffff);
	printf("\n\nWCHAR\t\nlength - %d\tMIN value: %hd\tMAX value: %d", sizeof(WCHAR), (WCHAR)0x8000, (WCHAR)0x7fff);
	printf("\n\nTCHAR\t\nlength - %d\tMIN value: %hd\tMAX value: %d", sizeof(TCHAR), (TCHAR)0x8000, (TCHAR)0x7fff);
	printf("\n\nSHORT\t\nlength - %d\tMIN value: %d\tMAX value: %d", sizeof(SHORT), (SHORT)0x8000, (SHORT)0x7fff);


	printf("\n\nBOOL\t\nlength - %d\tMIN value: %d\tMAX value: %d", sizeof(BOOL), (BOOL)0x80000000, (BOOL)0x7fffffff);
	printf("\n\nINT\t\nlength - %d\tMIN value: %d\tMAX value: %d", sizeof(INT), 0x80000000, 0x7fffffff);
	printf("\n\nUINT\t\nlength - %d\tMIN value: %u\tMAX value: %u", sizeof(UINT), 0, 0xffffffff);
	printf("\n\nDWORD\t\nlength - %d\tMIN value: %u\tMAX value: %u", sizeof(DWORD), 0, 0xffffffff);

	return 0;
}