#ifndef FUNC_DEF
#define FUNC_DEF
#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

struct text
{
	int length;
	char *text[];
	int MaxLength;
};
bool CheckLetter(char s);
bool CheckNum(char s);
void AddChuoi(char c[], char s[]);
void Nhap(int x, int y, bool check, char s[]);
void Nhap(int x, int y, bool check, char s[]);
char NhapChuoi();
char NhapSo();
int  KiemtraNhapLieu(char c, char s[]);
bool KhoaNhapLieu(char s[], int n);

#endif
