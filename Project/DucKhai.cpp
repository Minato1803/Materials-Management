#include "DucKhai.h"

// Ve khung them Vat lieu
void VeKhungAddMat(char khungNoiDung[][30], int H, int W)
{
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(310, 130, khungNoiDung[0]);
	
	//
	//Ve cac khung ban dau===
	int SoLuongKhung = 4;
	int mauNut = NEN_KHUNG;
	setfillstyle(SOLID_FILL, mauNut);
	bar (L, D-kichThuocNut, R, D);
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(WHITE);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	
	for (int i = 1; i <= SoLuongKhung; i++)
	{
		if (i == 1)
			veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 1, NEN_KHUNG, WHITE);
		else
			veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, WHITE);
	}
	//Chon vi tri ======
	int pos = 1;
	int fst = 1;			//SEX
	while(1)
	{
		if(kbhit())
		{
			char key = getch();
			char cNext;
			if (key == 0)
			{
				cNext = getch();
				switch(cNext)
				{
					case KEY_UP:
						{
							pos--;
							break;
						}
					case KEY_DOWN:
						{
							pos++;
							break;
						}
				}
				cpos:
				if (pos == 0)
					pos = 4;
				if (pos > 4)
					pos = 1;
			}
			else if (key == '\r')
			{
				if (pos <= 4)
					pos++;
				else
					return;
			}
			else if (key == 27)
			{
				VeMenu();
				return;
			}
			
			for (int i = 1; i <= SoLuongKhung; i++)
			{
				veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, WHITE);
			}
			switch(pos)
			{
				case 1:
					{
						veKhung(380, 200, khungNoiDung[3], 1, NEN_KHUNG, WHITE);
						// nhap
						break;
					}
				case 2:
					{
						veKhung(380, 260, khungNoiDung[4], 1, NEN_KHUNG, WHITE);
						break;
					}
				case 3:
					{
						veKhung(380, 320, khungNoiDung[5], 1, NEN_KHUNG, WHITE);
						break;
					}
				case 4:
					{
						veKhung(380, 380, khungNoiDung[6], 1, NEN_KHUNG, WHITE);
						break;
					}
				case 5:
					{
						// AddMaterials
						veKhung(380, 380, khungNoiDung[1], 1, NEN_KHUNG, WHITE);
						break;
					}
				case 6:
					{
						//Exit
						veKhung(380, 380, khungNoiDung[2], 1, NEN_KHUNG, WHITE);
						break;
					}
			}
		}
		
	}
}
