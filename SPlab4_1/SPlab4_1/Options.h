#pragma once
#define ZIP_PATH TEXT("C:\\Program Files\\7-Zip\\7z.exe")

void archive(LPCTSTR lpPathName, LPCTSTR lpOutArchivePath);
void extract(LPCTSTR lpArchivePath, LPCTSTR lpOutPathName);
void zipWork(wchar_t* strCom);