#pragma once
#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <math.h>
#include "graphics.h"
#include "colors.h"

using namespace std;
//struct NamesInfoEmp
//{
//	char fName[31];
//	char lName[31];
//	char ID[11];
//};

bool CheckLetter(char s);
bool CheckNum(char s);
long  ChangeCharToNum (char s[]);
void AddChuoi(char c, char s[]);
void get_chuoi(char *des, char *s );
void delBlank(char *s);
int  KiemtraNhapLieu(char c, char s[]);
bool KhoaNhapLieu(char s[], int n);
void Nhap(int x, int y, int check, char c, char s[], int n);
char* toChars(long num);
int  canLeGiua(char *S, int dis);
char* charDate(int day, int month, int year);


//do hoa
void InThongTin(int x, int y, const char *s);
void ThongBao(int x, int y, char noti[50], int mauChu, int mauNen);
void showPage(int x, int y, int page, int size);

