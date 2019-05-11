#include "Functions.h"

bool CheckLetter(char s)
{
	if((s>= 65 && s<= 90) || (s>= 97 && s<= 122 ) || (s==32))
	{
		return 1;
	}
	return 0;	 
}

bool CheckNum(char s)
{
		if(s >= 48 && s <= 57)
		{
			return 1;
		}
	return 0;	 
}

void AddChuoi(char c, char s[])
{
	strncat(s, &c,1);
}


int KiemtraNhapLieu(char c, char s[])
{
	if(strlen(s) == 0 && c == ' ') // block space
		return 0;
	else	
		if(strlen(s) != 0 && s[strlen(s)-1] == ' ' && c == ' ') // block double space 
			return 0;	
	else	
		if((strlen(s) != 0 && s[strlen(s)-1] == ' ' && c != ' ') || (strlen(s) == 0 && c != ' '))// upper Letter
			return -1;
	return 1;	 
}

bool KhoaNhapLieu(char s[], int n)
{
	if(strlen(s)<n)
		return 1;
	return 0;	
}

void Nhap(int x, int y,int check, char c, char s[], int n)
{
	c = tolower(c);
	if(c == 8 && strlen(s) != 0)
	{
		s[strlen(s)-1] = '\0';
	}	
	if(check == 1)
	{
		if(CheckLetter(c) && KhoaNhapLieu(s,n))
		{
			if(KiemtraNhapLieu(c,s) == 1)
			{
				AddChuoi(c,s);
//				outtextxy(x,y,s);
			}
			else
				if(KiemtraNhapLieu(c,s)==-1)
				{
					c = toupper(c);
					AddChuoi(c,s);
				}		
		}
		
	}
	else
	if(check==0)
	{
		if(CheckNum(c) && KhoaNhapLieu(s,n))
		{
			if(KiemtraNhapLieu(c,s) == 1 || KiemtraNhapLieu(c,s) == -1)
			{
				AddChuoi(c,s);
			}
		}
	}
	else
	if(check == -1)
	{
		if((CheckNum(c) || CheckLetter(c)) && KhoaNhapLieu(s,n) && c != ' ')
		{
			
			if(KiemtraNhapLieu(c,s) == 1|| KiemtraNhapLieu(c,s) == -1)
			{
				c = toupper(c);
				AddChuoi(c,s);
			}
		}
	}
	setcolor(WHITE);
	outtextxy(x,y,s);
}

void InThongTin(int x, int y, const char *s)
{
	setcolor(WHITE);
	outtextxy(x, y, s);
}

void ThongBao(int x, int y, char noti[50], int mauChu, int mauNen)
{	
	setbkcolor(mauNen);
	setcolor(mauChu);
	outtextxy(x, y, noti);
	Sleep(1500);
	setfillstyle(SOLID_FILL, mauNen);
	bar(x, y, x + textwidth(noti), y + textheight(noti));
}

