#ifndef FUNC_DEF
#define FUNC_DEF
#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
#include "graphics.h"

using namespace std;

struct Namesinfo
{
	char ID[11];
	char name[51];
};


bool CheckLetter(char s);
bool CheckNum(char s);
int ChangeCharToNum (char s[],int n);
void AddChuoi(char c, char s[]);
void delBlank(char *s);
int  KiemtraNhapLieu(char c, char s[]);
bool KhoaNhapLieu(char s[], int n);
void Nhap(int x, int y, int check, char c, char s[], int n);

//do hoa
void InThongTin(int x, int y, const char *s);
void ThongBao(int x, int y, char noti[50], int mauChu, int mauNen);



#endif

