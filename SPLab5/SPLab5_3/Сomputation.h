#pragma once
#include "stdafx.h"

DWORD WINAPI SumArr(LPVOID lpParam);
DWORD WINAPI AvgArr(LPVOID lpParam);
DWORD WINAPI MaxArr(LPVOID lpParam);

void Sum();
void Avg();
void Max();

void GenerateArray();
void DeleteCriticalSection();