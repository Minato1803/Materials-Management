#include <iostream>
#include "colors.h"
#include "UI.h"

using namespace std;

void VeMenu()
{
	setbkcolor(MAU_NEN);
	cleardevice();
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar(0, 0, WD_WIDTH+1000, 25);
	setcolor(WHITE);
	setusercharsize(1, 2, 1, 2);
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	for (int i = 0; i < MAX_MENU; i++)
	{
		outtextxy(ViTriMucMenu[i], 2, MenuChinh[i]);
		ViTriMucMenu[i+1] = ViTriMucMenu[i] + textwidth(MenuChinh[i]) + DIS_MENUX;
	}
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(0, 25, WD_WIDTH+1000, 25);
}

//void NoiBatMuc(int x)
//{
//	setbkcolor(HIGHTLIGHT);
//	setfillstyle(SOLID_FILL, HIGHTLIGHT);
//	setusercharsize(1, 2, 1, 2);
//	setcolor(WHITE);
//	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
//	bar(ViTriMucMenu[x]-DIS_MENUX/2, 0, ViTriMucMenu[x+1]-DIS_MENUX/2, 25);
//	outtextxy(ViTriMucMenu[x], 2, MenuChinh[x]);
//}

void NoiBatMuc(int x, int y, char menu[][30])
{
	setbkcolor(HIGHTLIGHT);
	setfillstyle(SOLID_FILL, HIGHTLIGHT);
	setusercharsize(1, 2, 1, 2);
	setcolor(WHITE);
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	
	if (y == 0)
	{
		bar(ViTriMucMenu[x]-DIS_MENUX/2, 0, ViTriMucMenu[x+1]-DIS_MENUX/2, 25);
		outtextxy(ViTriMucMenu[x], 2, menu[x]);
	}
	else
	{
		bar(ViTriMucMenu[x]-DIS_MENUX/2, 25+ViTriMucMenuPhu[y-1], ViTriMucMenu[x]-DIS_MENUX/2+KichThuocMenuPhu[x], 25+ViTriMucMenuPhu[y-1]+DIS_MENUY);
		outtextxy(ViTriMucMenu[x], 25+ViTriMucMenuPhu[y-1]+DIS_MENUY/2, menu[x]);
	}	
}

void ShowMenuPhu(int x, char menu[][30])
{
	int MAX;
	switch(x)
	{
		case 0: 
		{
			MAX = 3;
			break;
		}
		case 1: 
		{
			MAX = 3;
			break;
		}
		case 2: 
		{
			MAX = 3;
			break;
		}
		case 3: 
		{
			MAX = 2;
			break;
		}
		case 4: 
		{
			MAX = 1;
			break;
		}
		
	}
	setbkcolor(HIGHTLIGHT);
	setfillstyle(SOLID_FILL, HIGHTLIGHT);
	setusercharsize(1, 2, 1, 2);
	setcolor(WHITE);
	settextstyle(COMPLEX_FONT, 0, 2);
	bar(ViTriMucMenu[x]-DIS_MENUX/2, 25, ViTriMucMenu[x]-DIS_MENUX/2+KichThuocMenuPhu[x], 25+ViTriMucMenuPhu[MAX] + DIS_MENUY);
	for (int i = 0; i < MAX; i++)
	{
		outtextxy(ViTriMucMenu[x], 25+ViTriMucMenuPhu[i]+DIS_MENUY/2, menu[i]);
	}
}
//switch(x)
//	{
//		case 0:
//		{
//			menu = MenuMater[][30];
//			MAX = 3;
//			break;	
//		}
//		case 0:
//		{
//			menu = MenuEmp[][30];
//			MAX = 3;
//			break;	
//		}
//		case 0:
//		{
//			menu = MenuShow[][30];
//			MAX = 3;
//			break;	
//		}
//		case 0:
//		{
//			menu = MenuStat[][30];
//			MAX = 2;
//			break;	
//		}
//		case 0:
//		{
//			menu = MenuHelp[][30];
//			MAX = 1;
//			break;	
//		}
//	}

void Materials()
{
	ShowMenuPhu(0, MenuMater);
	
}

void Employees()
{
	ShowMenuPhu(1, MenuEmp);
}

void Show()
{
	ShowMenuPhu(2, MenuShow);
}

void Statistics()
{
	ShowMenuPhu(3, MenuStat);
}

void Help()
{
	ShowMenuPhu(4, MenuHelp);
}
void MenuPhu(int x)
{
	switch(x)
	{
		case 0:	return Materials();
		case 1:	return Employees();
		case 2:	return Show();
		case 3:	return Statistics();
		case 4:	return Help();
		default : return;
	}
}

void TaoManHinhLamViec()
{
	VeMenu();
	NoiBatMuc(0, 0, MenuChinh);
}

void KhoiTaoChuongTrinh()
{
	initwindow(WD_WIDTH, WD_HEIGHT);
	setwindowtitle("Materials-Management Beta");
	TaoManHinhLamViec();
}

void Menu()
{
	VeMenu();
	int chiMuc = 0;
	NoiBatMuc(chiMuc, 0, MenuChinh);
	while(1)
	{
		if(kbhit())
		{
			VeMenu();
			char key = getch();
			if (key == 0)
			{
				char cNext = getch();
				switch(cNext)
				{
					case KEY_LEFT: 
					{
						chiMuc--;
						break;
					}
					case KEY_RIGHT: 
					{
						chiMuc++;
						break;
					}
				}
				if (chiMuc == MAX_MENU)
					chiMuc = 0;
				if (chiMuc < 0)
					chiMuc = MAX_MENU-1;
			}
			else if (key == '\r')
			{
				MenuPhu(chiMuc);
			}
			NoiBatMuc(chiMuc, 0, MenuChinh);
		}
	}
}



int main()
{
	KhoiTaoChuongTrinh();
	Menu();
	delay(20000);
	return 0;
}
