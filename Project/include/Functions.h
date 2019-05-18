#pragma once
#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <math.h>
#include "graphics.h"
#include "colors.h"

using namespace std;

struct NamesInfo
{
	char ID[11];
	char name[51];
};

struct NamesInfoEmp
{
	char fName[31];
	char lName[31];
	char ID[11];
};

bool CheckLetter(char s);
bool CheckNum(char s);
int  ChangeCharToNum (char s[],int n);
void AddChuoi(char c, char s[]);
void delBlank(char *s);
int  KiemtraNhapLieu(char c, char s[]);
bool KhoaNhapLieu(char s[], int n);
void Nhap(int x, int y, int check, char c, char s[], int n);
char* toChars(int num);
int  canLeGiua(char *S, int dis);


//do hoa
void InThongTin(int x, int y, const char *s);
void ThongBao(int x, int y, char noti[50], int mauChu, int mauNen);
void showPage(int x, int y, int page, int size);

