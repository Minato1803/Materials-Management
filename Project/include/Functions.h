#pragma once
#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <math.h>
#include "graphics.h"
#include "colors.h"

using namespace std;


bool  CheckLetter(char s);
bool  CheckNum(char s);
bool  KhoaNhapLieu(char s[], int n);
char* toChars(unsigned long long num);
char* charDate(int day, int month, int year);
int   KiemtraNhapLieu(char c, char s[]);
int   canLeGiua(char *S, int dis);
void  AddChuoi(char c, char s[]);
void  get_chuoi(char *des, char *s );
void  delBlank(char *s);
void  Nhap(int x, int y, int check, char c, char s[], int n);
unsigned long long  ChangeCharToNum (char s[]);


//do hoa
void  InThongTin(int x, int y, const char *s);
void  ThongBao(int x, int y, char noti[50], int mauChu, int mauNen);
void  showPage(int x, int y, int page, int size);

