// SP_lab0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <limits.h> 
#include <float.h> 

int main()
{
	printf("\n\nchar\t\nlength - %d\tMIN value: %d\tMAX value: %d", sizeof(CHAR), CHAR_MIN, CHAR_MAX);
	printf("\n\nsigned char\t\nlength - %d\tMIN value: %d\tMAX value: %d", sizeof(CHAR), SCHAR_MIN, SCHAR_MAX);
	printf("\n\nunsigned char\t\nlength - %d\tMIN value: %d\tMAX value: %d", sizeof(CHAR), 0 , UCHAR_MAX);


	printf("\n\nshort\t\nlength - %d\tMIN value: %d\tMAX value: %d", sizeof(SHORT), SHRT_MIN, SHRT_MAX );
	printf("\n\nunsigned short\t\nlength - %d\tMIN value: %d\tMAX value: %d", sizeof(SHORT), 0, USHRT_MAX);


	printf("\n\nint\t\nlength - %d\tMIN value: %d\tMAX value: %d", sizeof(INT), INT_MIN, INT_MAX);
	printf("\n\nunsigned int\t\nlength - %d\tMIN value: %u\tMAX value: %u", sizeof(UINT), 0, UINT_MAX);


	printf("\n\nlong\t\nlength - %d\tMIN value: %li\tMAX value: %li", sizeof(INT), LONG_MIN, LONG_MAX);
	printf("\n\nunsigned long\t\nlength - %d\tMIN value: %u\tMAX value: %lu", sizeof(UINT), 0, ULONG_MAX);
	

	printf("\n\nlong long\t\nlength - %d\tMIN value: %lld\tMAX value: %lld", sizeof(INT), LLONG_MIN, LLONG_MAX);
	printf("\n\nunsigned long long\t\nlength - %d\tMIN value: %u\tMAX value: %llu", sizeof(UINT), 0, ULLONG_MAX);
		

	printf("\nfloat\t\nlength - %d\tMIN value: %d\tMAX value: %d", sizeof(BYTE), FLT_MIN, FLT_MAX);
	printf("\n\ndouble\t\nlength - %d\tMIN value: %hhd\tMAX value: %d", sizeof(BOOLEAN), DBL_MIN, DBL_MAX);
	printf("\n\nlong double\t\nlength - %d\tMIN value: %d\tMAX value: %d", sizeof(WORD), LDBL_MIN, LDBL_MAX);
	return 0;
}