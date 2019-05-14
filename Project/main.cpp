#include "include/Contents.h"
#include "include/colors.h"
#include "include/Functions.h"
#include "include/create_structure_K.h"
#include "include/create_structure_N.h"

using namespace std;


//==========UI=============
//Cac ham ve
void KhoiTaoChuongTrinh();
void TaoManHinhLamViec();
void VeMenu();
void VeMenuPhu(int x, char menu[][30]);
void NoiBatMuc(int x, int y, char menu[][30], int HL_COLOR, int C_SIZE);
void VeKhung2(char khungNoiDung[][30], int H, int W, int mucChon, int soLuongKhung);
void veNut2(char khungNoiDung[][30], int ViTriKhung[], int SoLuongKhung, int H, int W, int mauNut, int kichThuocNut, int mucChon);
void veKhung(int x, int y, char noiDung[], bool daChon, int mauNen, int mauChu);
void veMuc2Chon(int x, int y, char noiDung[], char noiDungMucChon[][30], bool chonTrai, int mauNen, int mauChu);
void veKhungNut(int H, int W, char khungNoiDung[][30], bool Left, bool reset);
void notiBool(char khungNoiDung[][50], bool &choice, int n);
void inDanhSachMat(char khungNoiDung[][30], int sizeKhungNoiDung[], struct NamesInfo arr[], int start, int Size);

// Cac ham Menu
void Menu();
void MenuPhu(int viTriMenuPhu, char menu[][30], int MAXMENU, int &chonMuc);
void ChonMenuPhu(int x);
void Materials();
void Employees();
void Bill();
void Statistics();
void Help();
void About();
void Guild();
//=========================

//==========DUCKHAI========
	NODEPTR tree = NULL;
	int CountM = 2;
	struct NamesInfo NameM[2];
	// Cau a:
	void VeKhungAddMat(char khungNoiDung[][30], int H, int W);
	void inDanhSachMat(char khungNoiDung[][30], int sizeKhungNoiDung[], struct NamesInfo arr[], int start, int Size);
//=========================

//==========CHINHAN========
struct listEmp ListEmployees;
void VeKhungAddEmp(char khungNoiDung[][30], int H, int W);
void inDanhSachEmp(char khungNoiDung[][30], int sizeKhungNoiDung[], struct NamesInfo arr[], int start, int Size);
//=========================


//==========MAIN====================================
int main()
{
	KhoiTaoChuongTrinh();
	Menu();
	return 0;
}

//==================================================



//==========UI============
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


void NoiBatMuc(int x, int y, char menu[][30], int HL_COLOR, int C_SIZE)
{
	setbkcolor(HL_COLOR);
	setfillstyle(SOLID_FILL, HL_COLOR);
	setcolor(WHITE);
	settextstyle(COMPLEX_FONT, 0, C_SIZE);
	
	
	if (y == 0)
	{
		bar(ViTriMucMenu[x]-DIS_MENUX/2, 0, ViTriMucMenu[x+1]-DIS_MENUX/2, 25);
		outtextxy(ViTriMucMenu[x], 2, menu[x]);
	}
	else
	{
		bar(ViTriMucMenu[x]-DIS_MENUX/2, 
		25+ViTriMucMenuPhu[y-1], 
		ViTriMucMenu[x]-DIS_MENUX/2+KichThuocMenuPhu[x], 
		25+ViTriMucMenuPhu[y]);
		
		outtextxy(ViTriMucMenu[x], 25+ViTriMucMenuPhu[y-1]+DIS_MENUY/2, menu[y-1]);
	}
	
}

void VeMenuPhu(int x, char menu[][30])
{
	int MAX;
	switch(x)
	{
		case 0: 
		{
			MAX = 4;
			break;
		}
		case 1: 
		{
			MAX = 4;
			break;
		}
		case 2: 
		{
			MAX = 2;
			break;
		}
		case 3: 
		{
			MAX = 2;
			break;
		}
		case 4: 
		{
			MAX = 2;
			break;
		}
		
	}
	setbkcolor(HIGHTLIGHT);
	setfillstyle(SOLID_FILL, HIGHTLIGHT);
	setusercharsize(1, 2, 1, 2);
	setcolor(WHITE);
	settextstyle(COMPLEX_FONT, 0, 2);
	
	bar(ViTriMucMenu[x]-DIS_MENUX/2, 
	25, 
	ViTriMucMenu[x]-DIS_MENUX/2+KichThuocMenuPhu[x], 
	25+ViTriMucMenuPhu[MAX]);
	
	for (int i = 0; i < MAX; i++)
	{
		outtextxy(ViTriMucMenu[x], 25+ViTriMucMenuPhu[i]+DIS_MENUY/2, menu[i]);
	}
}

void MenuPhu(int viTriMenuPhu, char menu[][30], int MAXMENU, int &chonMuc)
{
	chonMuc = 1;
	NoiBatMuc(viTriMenuPhu, chonMuc, menu, HL_MENU_PHU, 2);
	while(1)
	{
		if(kbhit())
		{
			VeMenuPhu(viTriMenuPhu, menu);
			char key = getch();
			if (key == 0)
			{
				char cNext = getch();
				switch(cNext)
				{
					case KEY_UP: 
					{
						chonMuc--;
						break;
					}
					case KEY_DOWN: 
					{
						chonMuc++;
						break;
					}
					default:
						{
							VeMenu();
							chonMuc = -1;
							return;
						}
				}
				if (chonMuc > MAXMENU)
					chonMuc = 1;
				if (chonMuc < 1)
					chonMuc = MAXMENU;
			}
			else if (key == '\r')
			{

				return VeMenu();
			}
			NoiBatMuc(viTriMenuPhu, chonMuc, menu, HL_MENU_PHU, 2);
		}
	}
}

void Materials()
{
	VeMenuPhu(0, MenuMater);
	int thaoTac;
	MenuPhu(0, MenuMater, 4, thaoTac);
	switch (thaoTac)
	{
		case 1:
			{
				VeKhungAddMat(khungMat, 450, 600);
				VeMenu();
				break;
			}
		case 2:
			{
				VeKhungAddEmp(khungEmp, 450, 600);
				break;
			}
		case 3:
			{
				inDanhSachMat(danhSachMat, sizeDanhSachMat, NameM, 0, CountM);
				break;
			}
	}
}

void Employees()
{
	VeMenuPhu(1, MenuEmp);
	int thaoTac;
	MenuPhu(1, MenuEmp, 4, thaoTac);
	switch (thaoTac)
	{
		case 1:
			{
				return VeKhungAddEmp(khungEmp, 450, 600);
			}
		case 2:
			{
				return VeKhungAddMat(khungMat, 450, 600);
				break;
			}
		case 3:
			{
				About();
				break;
			}
		case 4:
			{
				return inDanhSachEmp(danhSachEmp, sizeDanhSachEmp, NameM, 0, CountM);
				break;
			}
	}
}

void Bill()
{
	VeMenuPhu(2, MenuBill);
	int thaoTac;
	MenuPhu(2, MenuBill, 2, thaoTac);
	if (thaoTac == 1)
	{
		
	}
}

void Statistics()
{
	VeMenuPhu(3, MenuStat);
	int thaoTac;
	MenuPhu(3, MenuStat, 2, thaoTac);
}

void Help()
{
	VeMenuPhu(4, MenuHelp);
	int thaoTac;
	MenuPhu(4, MenuHelp, 2, thaoTac);
	switch (thaoTac)
	{
		case 1:
			{
				Guild();
				break;
			}
		case 2:
			{
				About();
				break;
			}
	}
}

void ChonMenuPhu(int x)
{
	switch(x)
	{
		case 0:	return Materials();
		case 1: return Employees();
		case 2:	return Bill();
		case 3:	return Statistics();
		case 4:	return Help();
		default : return;
	}
}

void TaoManHinhLamViec()
{
	VeMenu();
	NoiBatMuc(0, 0, MenuChinh, HIGHTLIGHT, USER_CHAR_SIZE);
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
	NoiBatMuc(chiMuc, 0, MenuChinh, HIGHTLIGHT, USER_CHAR_SIZE);
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
			else if (key == 13)
			{
				VeMenu();
				ChonMenuPhu(chiMuc);
			}
			NoiBatMuc(chiMuc, 0, MenuChinh, HIGHTLIGHT, USER_CHAR_SIZE);
		}
	}
}

void About()
{
	MessageBox(GetActiveWindow(), 
	"Materials-Management \n"
	"Version Beta 1.0\n\n"
	"Authors:\n"
	"Nguyen Duc Khai 	  \t- N17DCCN066\n"
	"Tran Nguyen Chi Nhan \t- N17DCCN115\n",
	"About", MB_APPLMODAL | MB_ICONINFORMATION);
}

void Guild()
{
	MessageBox(GetActiveWindow(), 
	"Di chuyen: Dung phim mui ten.\n"
	"Chon: Dung phim Enter.\n"
	"Cuon trang: Dung phim pgUp, pgDown.\n"
	"Thoat: Dung phim ESC.",
	"Guild", MB_APPLMODAL | MB_ICONINFORMATION);
}


void VeKhung2(char khungNoiDung[][30], int H, int W, int mucChon, int soLuongKhung)
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
	veNut2(khungNoiDung, ViTriKhung, soLuongKhung, H, W, NEN_KHUNG, kichThuocNut, mucChon);
}

void veNut2(char khungNoiDung[][30], int ViTriKhung[], int SoLuongKhung, int H, int W, int mauNut, int kichThuocNut, int mucChon)
{
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
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
	//ve khung nhap lieu
	for (int i = 1; i <= SoLuongKhung; i++)
	{
		if (i != mucChon)
		{
			if (i == 1)
				veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 1, NEN_KHUNG, WHITE);
			else
				veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, WHITE);
		}
		else
		{
			veMuc2Chon(380, ViTriKhung[i], khungNoiDung[i+2], Sex, 1, NEN_KHUNG, WHITE);
		}
	}
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
				//VeMenu();
				return;
			}
			
			for (int i = 1; i <= SoLuongKhung; i++)
			{
				if (i != mucChon)
					veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, WHITE);
				else
					veMuc2Chon(380, ViTriKhung[i], khungNoiDung[i+2], Sex, fst, NEN_KHUNG, WHITE);
			}
			switch(pos)
			{
				case 1:
					{
						veKhung(380, 200, khungNoiDung[3], 1, NEN_KHUNG, WHITE);
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
						if (pos == mucChon)
						{
							veMuc2Chon(380, 380, khungNoiDung[6], Sex, fst, NEN_KHUNG, WHITE);
							while(1)
							{
								if (kbhit())
								{
									key = getch();
									if (key == 0)
									{
										cNext = getch();
										switch(cNext)
										{
											case KEY_LEFT:
												{
													fst++;
													break;
												}
											case KEY_RIGHT:
												{
													fst--;
													break;
												}
											case KEY_UP:
												{
													pos--;
													goto cpos;
													break;
												}
											case KEY_DOWN:
												{
													pos++;
													goto cpos;
													break;
												}
										}
									}
									else if (key == '\r')
									{
										pos++;
										goto cpos;
									}
									if (fst == -1)
										fst = 1;
									if (fst > 1)
										fst = 0;								
								}
								veMuc2Chon(380, 380, khungNoiDung[6], Sex, fst, NEN_KHUNG, WHITE);
							}
						}
						else
						{
							veKhung(380, 380, khungNoiDung[6], 1, NEN_KHUNG, WHITE);
						}
						break;
					}
				case 5:
					{
						veKhung(380, 380, khungNoiDung[1], 1, NEN_KHUNG, WHITE);
						break;
					}
				case 6:
					{
						veKhung(380, 380, khungNoiDung[2], 1, NEN_KHUNG, WHITE);
						break;
					}
			}
		}
		
	}
}

void veKhung(int x, int y, char noiDung[], bool daChon, int mauNen, int mauChu)
{
	setbkcolor(mauNen);
	setcolor(mauChu);
	outtextxy(x, y, noiDung);
	int H = textheight(noiDung);
	int W = 275;
	int dis = 175;
	if (daChon)
		setfillstyle(SOLID_FILL, WHITE);
	else
		setfillstyle(SOLID_FILL, BLACK);
	bar (x+dis-1, y-2-1, x+dis+W+1, y+2+textheight(noiDung)+1);
	setfillstyle(SOLID_FILL, TEXTBOX);
	bar (x+dis, y-2, x+dis+W, y+2+textheight(noiDung));
}

void veMuc2Chon(int x, int y, char noiDung[], char noiDungMucChon[][30], bool chonTrai, int mauNen, int mauChu)
{
	setbkcolor(mauNen);
	setcolor(mauChu);
	outtextxy(x, y, noiDung);
	int H = textheight(noiDung);
	int W = 275;
	int rad = H/2-2;
	int dis1 = 180;
	int dis2 = 320;
	outtextxy(x+dis2+H, y, noiDungMucChon[1]);
	outtextxy(x+dis1+H, y, noiDungMucChon[0]);
	setfillstyle(SOLID_FILL, GREEN);
	if (chonTrai)
	{
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
		circle(x+dis1, y+H/2, rad);
		setfillstyle(SOLID_FILL, GREEN);
		setcolor(BLACK);
		circle(x+dis1, y+H/2, rad-2);
		floodfill(x+dis1, y+H/2, BLACK);
		
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
		circle(x+dis2, y+H/2, rad);
		setfillstyle(SOLID_FILL, mauNen);
		setcolor(BLACK);
		circle(x+dis2, y+H/2, rad-2);
		floodfill(x+dis2, y+H/2, BLACK);
	}
	else
	{
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
		circle(x+dis1, y+H/2, rad);
		setfillstyle(SOLID_FILL, mauNen);
		setcolor(BLACK);
		circle(x+dis1, y+H/2, rad-2);
		floodfill(x+dis1, y+H/2, BLACK);
		
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
		circle(x+dis2, y+H/2, rad);
		setfillstyle(SOLID_FILL, GREEN);
		setcolor(BLACK);
		circle(x+dis2, y+H/2, rad-2);
		floodfill(x+dis2, y+H/2, BLACK);
	}
	
	setfillstyle(SOLID_FILL, TEXTBOX);
}

void veKhungNut(int H, int W, char khungNoiDung[][30], bool Left, bool reset)
{
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);
	int MAU_NUT_HL = HL_MENU_PHU;
	if (reset)
		MAU_NUT_HL = NEN_KHUNG;
	setfillstyle(SOLID_FILL, MAU_NUT_HL);
	if (Left)
	{
		bar (L, D-kichThuocNut, WD_WIDTH/2, D);
		setbkcolor(MAU_NUT_HL);
		setcolor(WHITE);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
		setbkcolor(NEN_KHUNG);
		outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	}
	else	
	{
		bar (WD_WIDTH/2, D-kichThuocNut, R, D);
		setcolor(WHITE);
		setbkcolor(NEN_KHUNG);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
		setbkcolor(MAU_NUT_HL);
		outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	}
	setcolor(BLACK);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
}

void notiBool(char khungNoiDung[][50], bool &choice, int n)
{
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	int H = 200;
	int W = 450;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	setcolor(BLACK);
	rectangle(L-1, U-1, R+1, D+1);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setcolor(MAU_TEXT_KHUNG);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[n]))/2 + textheight(khungNoiDung[n]);
	setcolor(WHITE);
	outtextxy(L+25, ViTriKhung[3]-15, khungNoiDung[n]);
	outtextxy(L+25, ViTriKhung[4]-15, khungNoiDung[3]);	
	setfillstyle(SOLID_FILL, HL_MENU_PHU);									//do mau nen cho nut
	if (choice)
	{
		bar (L, D-kichThuocNut, WD_WIDTH/2, D);
		setbkcolor(HL_MENU_PHU);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
		setbkcolor(NEN_KHUNG);
		outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	}
	else	
	{
		bar (WD_WIDTH/2, D-kichThuocNut, R, D);
		setbkcolor(NEN_KHUNG);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
		setbkcolor(HL_MENU_PHU);
		outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	}
	setcolor(BLACK);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
	
	while(1)
	{
		if(kbhit())
		{
			char keyNoti = getch();
			char ckeyNoti;
			if(keyNoti==0)
			{
				ckeyNoti = getch();
				if(ckeyNoti == KEY_LEFT || ckeyNoti == KEY_RIGHT)
				{
					choice ^= 1;
					setcolor(WHITE);
					setfillstyle(SOLID_FILL, NEN_KHUNG);
					if (choice)
					{
						bar (WD_WIDTH/2, D-kichThuocNut, R, D);
						setfillstyle(SOLID_FILL, HL_MENU_PHU);									//do mau nen cho nut
						bar (L, D-kichThuocNut, WD_WIDTH/2, D);
						setbkcolor(HL_MENU_PHU);
						outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
						setbkcolor(NEN_KHUNG);
						outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
					}
					else	
					{
						bar (L, D-kichThuocNut, WD_WIDTH/2, D);
						setfillstyle(SOLID_FILL, HL_MENU_PHU);									//do mau nen cho nut
						bar (WD_WIDTH/2, D-kichThuocNut, R, D);
						setbkcolor(NEN_KHUNG);
						outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
						setbkcolor(HL_MENU_PHU);
						outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
					}
					setcolor(BLACK);
					line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
					line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
				}
			}
			else if(keyNoti == '\r')
			{
				return;
			}
			else if(keyNoti == 27)
			{
				choice = 0;
				return;
			}			
		}
	}
}

//=============endUI============//


//============DUCKHAI===========//
void VeKhungAddMat(char khungNoiDung[][30], int H, int W)
{
	struct Material tmp;
	NotiN:
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
	InThongTin(560, ViTriKhung[1], tmp.code);
			InThongTin(560, ViTriKhung[2], tmp.name);
			InThongTin(560, ViTriKhung[3], tmp.type);
			InThongTin(560, ViTriKhung[4], tmp.amount);
	//===== Chon vi tri ======//
	int pos = 1;
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
					pos = 5;
				if (pos > 5)
					pos = 1;
			}
			else if (key == '\r')
			{
				if (pos <= 4)
					pos++;
//				else
//					return;
			}
			else if (key == 27)
			{
				//VeMenu();
				return;
			}
			
			
			for (int i = 1; i <= SoLuongKhung; i++)
			{
				veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, WHITE);
			}
			setbkcolor(NEN_TEXT);
			InThongTin(560, ViTriKhung[1], tmp.code);
			InThongTin(560, ViTriKhung[2], tmp.name);
			InThongTin(560, ViTriKhung[3], tmp.type);
			InThongTin(560, ViTriKhung[4], tmp.amount);
			veKhungNut(H, W, khungNoiDung, 1, 1);
			//===di chuyen trong menu===//
			switch(pos)
			{
				case 1:
					{
						veKhung(380, 200, khungNoiDung[3], 1, NEN_KHUNG, WHITE);
						Nhap(560,200,-1, key, tmp.code,10);
						break;
					}
				case 2:
					{
						veKhung(380, 260, khungNoiDung[4], 1, NEN_KHUNG, WHITE);
						Nhap(560,260,1, key, tmp.name, 25);
						break;
					}
				case 3:
					{
						veKhung(380, 320, khungNoiDung[5], 1, NEN_KHUNG, WHITE);
						Nhap(560,320,1, key, tmp.type,25);
						break;
					}
				case 4:
					{
						veKhung(380, 380, khungNoiDung[6], 1, NEN_KHUNG, WHITE);
						Nhap(560,380,0, key, tmp.amount,18);
						
						break;
					}
				case 5:
					{
						// AddMaterials
//						veKhung(380, 380, khungNoiDung[1], 1, NEN_KHUNG, WHITE);

						bool buttonL = 1;
						veKhungNut(H, W, khungNoiDung, buttonL, 0);
						while(1)
						{
							if(kbhit())
							{
								char key5 = getch();
								char c5Next;
								if (key5 == 0)
								{
									c5Next = getch();
									switch(c5Next)
									{
										case KEY_UP:
											{
												pos--;
												veKhungNut(H, W, khungNoiDung, buttonL, 1);
												goto cpos;
											}
										case KEY_DOWN:
											{
												pos++;
												veKhungNut(H, W, khungNoiDung, buttonL, 1);
												goto cpos;
											}
										case KEY_LEFT:
											{
												buttonL ^= 1;
												break;
											}
										case KEY_RIGHT:
											{
												buttonL ^= 1;
												break;
											}
									}
								}
								else if (key5 == '\r')
								{
									//return;
									if (buttonL == 1)
									{
										//===thong bao loi===//
										if(strlen(tmp.code) != 0 && strlen(tmp.name) != 0 && strlen(tmp.type) != 0 && strlen(tmp.amount) != 0)
										{
											if(Search(tree, tmp.code) == NULL)
											{
												NotiY:
												ThongBao(725, 130, Success[0], GREEN, MAU_MENU);	
												
												tmp.RealAmount =  (tmp.amount,tmp.RealAmount);
												Insert(tree,tmp.code,tmp);													
												return VeKhungAddMat(khungMat, 450, 600);	
											}
											else
											{
												bool x = 1;
												notiBool(sameMat, x, 0);
												if(x)
													goto NotiY;
												else
													goto NotiN;
													
											}
										}
										else
										{
											ThongBao(780, 130, Fail[0], LIGHTRED, MAU_MENU);
											goto NotiN;
										}
										
										
									}
									else
									{
										
										saveFile(tree);
										VeMenu();
										return;
									}
								}
								else if (key5 == 27)
								{
									VeMenu();
									return;
								}
								veKhungNut(H, W, khungNoiDung, buttonL, 0);
							}
						}
					}
			}
		}
		
	}
}

void inDanhSachMat(char khungNoiDung[][30], int sizeKhungNoiDung[], struct NamesInfo arr[], int start, int Size)
{
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	int h = textheight(khungNoiDung[0]);
	int H = (h+5*2)*OBJ_PER_PAGE + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 5; i++)
	{
		W += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i]*2;
	}
	
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	int dis = L;
	for (int i = 0; i < 5; i++)
	{
		dis += sizeKhungNoiDung[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, khungNoiDung[i]);
		dis += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i];
		setcolor(BLACK);
		line(dis, U, dis, D);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 20; i++)
	{
		dis += h+5*2;
		line(L, dis, R, dis);
	}
	// tim thong tin
	
	// in thong tin
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	//Size = 20;
	for (int i = start; i < min(start+OBJ_PER_PAGE, Size); i++)
	{
		dis += 5;
		int disW = L;
		for (int j = 0; j < 5; j++)
		{
			if (j == 0)
			{
				char *d = toChars(i+1);
				outtextxy(disW + canLeGiua(d, textwidth(khungNoiDung[j])+sizeKhungNoiDung[j]*2), dis, d);
				disW += textwidth(khungNoiDung[j]) + sizeKhungNoiDung[j]*2;
			}
			else
			{
				if (j != 2)	//can le giua
				{
					outtextxy(disW + canLeGiua(khungNoiDung[j], textwidth(khungNoiDung[j])+sizeKhungNoiDung[j]*2), dis, khungNoiDung[j]);
					disW += textwidth(khungNoiDung[j]) + sizeKhungNoiDung[j]*2;
				}
				else
				{
					outtextxy(disW + 10, dis, khungNoiDung[j]);
					disW += textwidth(khungNoiDung[j]) + sizeKhungNoiDung[j]*2;
				}
				
			}
		}
		dis += h+5;
	}
	
}


//===========endDUCKHAI=========

//===========CHINHAN============

void VeKhungAddEmp(char khungNoiDung[][30], int H, int W)
{
	int soLuongKhung = 4;
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
	setfillstyle(SOLID_FILL, NEN_KHUNG);
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
	//ve khung nhap lieu
	for (int i = 1; i <= soLuongKhung; i++)
	{
		if (i != soLuongKhung)
		{
			if (i == 1)
				veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 1, NEN_KHUNG, WHITE);
			else
				veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, WHITE);
		}
		else
		{
			veMuc2Chon(380, ViTriKhung[i], khungNoiDung[i+2], Sex, 1, NEN_KHUNG, WHITE);
		}
	}
	int pos = 1;
	int fst = 1;			//SEX
	
	struct Employee *tmpE = new struct Employee;
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
					pos = 5;
				if (pos > 5)
					pos = 1;
			}
			else if (key == '\r')
			{
				if (pos <= 4)
					pos++;
			}
			else if (key == 27)
			{
				//VeMenu();
				return;
			}
			
			setbkcolor(NEN_TEXT);	
			for (int i = 1; i <= 4; i++)
			{
				if (i != 4)
					veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, WHITE);
				else
					veMuc2Chon(380, ViTriKhung[i], khungNoiDung[i+2], Sex, fst, NEN_KHUNG, WHITE);
				setcolor(WHITE);
			}
			setbkcolor(NEN_TEXT);
			InThongTin(560, ViTriKhung[1], tmpE->ID);
			InThongTin(560, ViTriKhung[2], tmpE->firstName);
			InThongTin(560, ViTriKhung[3], tmpE->lastName);
			switch(pos)
			{
				case 1:
					{
						veKhung(380, 200, khungNoiDung[3], 1, NEN_KHUNG, WHITE);
						Nhap(560, 200, -1, key, tmpE->ID, 10);
						break;
					}
				case 2:
					{
						veKhung(380, 260, khungNoiDung[4], 1, NEN_KHUNG, WHITE);
						Nhap(560, 260, 1, key, tmpE->firstName, 25);
						break;
					}
				case 3:
					{
						veKhung(380, 320, khungNoiDung[5], 1, NEN_KHUNG, WHITE);
						Nhap(560, 320, 1, key, tmpE->lastName, 25);
						break;
					}
				case 4:
					{
						veMuc2Chon(380, 380, khungNoiDung[6], Sex, fst, NEN_KHUNG, WHITE);
						while(1)
						{
							if (kbhit())
							{
								char key4 = getch();
								if (key4 == 0)
								{
									char c4Next = getch();
									switch(c4Next)
									{
										case KEY_LEFT:
											{
												fst++;
												break;
											}
										case KEY_RIGHT:
											{
												fst--;
												break;
											}
										case KEY_UP:
											{
												pos--;
												goto cpos;
											}
										case KEY_DOWN:
											{
												pos++;
												goto cpos;
											}
									}
								}
								else if (key4 == '\r')
								{
									pos++;
									goto cpos;
									break;
								}
								else if (key4 == 27)
								{
									return;
								}
								if (fst == -1)
									fst = 1;
								if (fst > 1)
									fst = 0;								
								veMuc2Chon(380, 380, khungNoiDung[6], Sex, fst, NEN_KHUNG, WHITE);
								tmpE->sex = fst;
							}
						}
						break;
					}
				case 5:
					{
						bool buttonL = 1;
						veKhungNut(H, W, khungNoiDung, buttonL, 0);
						while(1)
						{
							if(kbhit())
							{
								char key5 = getch();
								char c5Next;
								if (key5 == 0)
								{
									c5Next = getch();
									switch(c5Next)
									{
										case KEY_UP:
											{
												pos--;
												veKhungNut(H, W, khungNoiDung, buttonL, 1);
												goto cpos;
											}
										case KEY_DOWN:
											{
												pos++;
												veKhungNut(H, W, khungNoiDung, buttonL, 1);
												goto cpos;
											}
										case KEY_LEFT:
											{
												buttonL ^= 1;
												break;
											}
										case KEY_RIGHT:
											{
												buttonL ^= 1;
												break;
											}
									}
								}
								else if (key5 == '\r')
								{
									//return;
									if (buttonL == 1)
									{
										if(strlen(tmpE->ID) != 0 && strlen(tmpE->firstName) != 0 && strlen(tmpE->lastName) != 0)
										{
											if (!ListEmployees.isFull() && ListEmployees.Search_info(tmpE) == -1)
											{
												ListEmployees.Insert(tmpE);
												ThongBao(725, 130, Success[0], GREEN, MAU_MENU);
											}
											else
											{
												bool chooseY = 1;
												notiBool(sameEmp, chooseY, 0);
												if(chooseY)
												{
													About();  //Adjust------
												}
											}	
											return VeKhungAddEmp(khungEmp, 450, 600);
										}
										else
										{
											ThongBao(780, 130, Fail[0], LIGHTRED, MAU_MENU);
										}
									}
									else
									{
										VeMenu();
										return;
									}
								}
								else if (key5 == 27)
								{
									VeMenu();
									return;
								}
								veKhungNut(H, W, khungNoiDung, buttonL, 0);
							}
						}
					}
			}
		}
	}
}


void inDanhSachEmp(char khungNoiDung[][30], int sizeKhungNoiDung[], struct NamesInfo arr[], int start, int Size)
{
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	int h = textheight(khungNoiDung[0]);
	int H = (h+5*2)*OBJ_PER_PAGE + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 5; i++)
	{
		W += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i]*2;
	}
	
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	int dis = L;
	for (int i = 0; i < 5; i++)
	{
		dis += sizeKhungNoiDung[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, khungNoiDung[i]);
		dis += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i];
		setcolor(BLACK);
		line(dis, U, dis, D);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 20; i++)
	{
		dis += h+5*2;
		line(L, dis, R, dis);
	}
	// tim thong tin
	
	// in thong tin
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	//Size = 20;
	for (int i = start; i < min(start+OBJ_PER_PAGE, Size); i++)
	{
		dis += 5;
		int disW = L;
		for (int j = 0; j < 5; j++)
		{
			if (j == 0)
			{
				char *d = toChars(i+1);
				outtextxy(disW + canLeGiua(d, textwidth(khungNoiDung[j])+sizeKhungNoiDung[j]*2), dis, d);
				disW += textwidth(khungNoiDung[j]) + sizeKhungNoiDung[j]*2;
			}
			else
			{
				if (j != 2)	//can le giua
				{
					outtextxy(disW + canLeGiua(khungNoiDung[j], textwidth(khungNoiDung[j])+sizeKhungNoiDung[j]*2), dis, khungNoiDung[j]);
					disW += textwidth(khungNoiDung[j]) + sizeKhungNoiDung[j]*2;
				}
				else
				{
					outtextxy(disW + 10, dis, khungNoiDung[j]);
					disW += textwidth(khungNoiDung[j]) + sizeKhungNoiDung[j]*2;
				}
				
			}
		}
		dis += h+5;
	}
	
}
//==========endCHINHAN========


