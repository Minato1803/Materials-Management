#include <iostream>
#include <string>
using namespace std;

struct text
{
	int length;
	char *text[];
	int MaxLength;
};

bool CheckLetter(char s)
{
			if((s< 65||s> 90) || (s< 97 && s> 90 ) || (s> 122))
			{
				return 0;
			}
	return 1;	 
}

bool CheckNum(char s)
{
		if(s < 48 || s > 57)
		{
			return 0;
		}
	return 1;	 
}

void AddChuoi(char c[], char s[])
{
	strcat(s,c);
}

char  NhapChuoi()
{
	char c;
	loop:
	c = getch();
	if(CheckLetter(c))
		return c;
	else
		goto loop;	
}

char NhapSo()
{
	char c;
	loop:
	c = getch();
	if(CheckNum(c))
		return c;
	else
		goto loop;		
}

int KiemtraNhapLieu(char c, char s[])
{
	if(strlen(s) == 0 && c == ' ')
		return 0;
	if(strlen(s) != 0 && s[strlen(s)-1] == ' ' && c == ' ')
		return 0;	
	if((strlen(s) != 0 && s[strlen(s)-1] == ' ' && c != ' ') || strlen(s) == 0)
		return -1;
	return 1;	 
}

bool KhoaNhapLieu(char s[], int n)
{
	if(strlen(s)>=n)
		return 1;
	return 0;	
	
}
