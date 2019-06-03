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
void veMuc3Chon(int x, int y, char khungNoiDung[][30],int choose, bool reset, int &stt);
void veKhungNut(int H, int W, char khungNoiDung[][30], bool Left, bool reset, int n);
void VeMucChonNgay(int x, int y, char noiDungMucChon[][30], int ViTri, int mauNen, int mauChu);
void notiBool(char khungNoiDung[][50], bool &choice, int n);
void noti(char khungNoiDung[][50]);

// Cac ham Menu
void Menu(struct listEmp &ListEmployees,NODEPTR &tree);
void MenuPhu(int viTriMenuPhu, char menu[][30], int MAXMENU, int &chonMuc);
void ChonMenuPhu(int x, struct listEmp &ListEmployees, NODEPTR &tree);
void Materials(NODEPTR &tree);
void Employees(struct listEmp &ListEmployees);
void Bill(NODEPTR &tree);
void Statistics();
void Help();
void About();
void Guild();
//=========================

//==========DUCKHAI==============================================================================
	int index = 0;
	// Cau a:
	void VeKhungAddMat(NODEPTR &tree, char khungNoiDung[][30], int H, int W,int Mcase,  Material tmp);
	void infoText(int x, int y, char noiDung[],char info[]);
	void hienThiInfoMat(NODEPTR &tree, char khungNoiDung[][30], int H, int W, char keyword[]);
	void inChoiceMat(NODEPTR &tree, char khungNoiDung[][30],bool RoA);
	void danhSachRoAMat(NODEPTR &tree, int &CountM, bool RoA);
	void chonTuDanhSachMat(NODEPTR &tree, Name_Mat *arrM, int CountM, int &stt, int &startPage, bool &selected);
	void inTrangMat(NODEPTR &tree, char khungNoiDung[][30], int sizeKhungNoiDung[], Name_Mat arr[], int start);
	void taoMangMat(NODEPTR &tree, Name_Mat arrM[]);
	void inVatTu(Material VT, int posX, int posY);
	void inDanhSachMat(NODEPTR &tree);
//=========================

//==========CHINHAN========
void VeKhungAddEmp(struct listEmp &ListEmployees, char khungNoiDung[][30], int H, int W);
void taoMangEmp(struct listEmp &ListEmployees, struct NamesInfoEmp *arr);
void inDanhSachEmp(struct listEmp &ListEmployees);
void inTrangEmp(struct listEmp &list, char khungNoiDung[][30], int sizeKhungNoiDung[], struct NamesInfoEmp arr[], int start);
//void chonTuTrangEmp(char khungNoiDung[][30], int sizeKhungNoiDung[], struct NamesInfoEmp arr[], int start, int &selection);
void inNhanVien(struct Employee *NV, int posX, int posY);
void chonTuDanhSach(struct listEmp &ListEmployees, NamesInfoEmp *arrEmp, int &stt, int &startPage, bool &selected);
void hienThiInfoEmp(char khungNoiDung[][30], int H, int W, struct Employee *Info);
void inRemoveEmp(char khungNoiDung[][30], struct listEmp &ListEmployees);
void thongKeBill(struct listEmp &ListEmployees);
void taoMangBillDate(struct listEmp &List, struct listBillDate *arr, struct Dates dayBegin, struct Dates dayEnd);
void inTrangBill(struct listEmp &list, struct listBillDate *arr, int start);


//=========================
void VeKhungAddBill(NODEPTR &tree, char khungNoiDung[][30], int H, int W);
void danhSachBill(NODEPTR &tree, int &CountM, bool choice);
void chonTuDanhSachBill(NODEPTR &tree, Name_Mat *arrM, int CountM, int &stt, bool &selected);
void inTrangBill(NODEPTR &tree, char khungNoiDung[][30], int sizeKhungNoiDung[], Name_Mat arr[], int start);
void inChoiceBill(NODEPTR &tree, char khungNoiDung[][30],bool NoX); // NoX = 1  nhap, RoA = 0 xuat
void hienThiInfoBill(NODEPTR &tree, char khungNoiDung[][30], int H, int W, char keyword[]);
void VeKhungChooseBill(NODEPTR &tree, char khungNoiDung[][30], int H, int W, Material tmp);
//==========MAIN====================================
int main()
{
	KhoiTaoChuongTrinh();
	NODEPTR tree = NULL;
	loadFile(tree, CountM);
	struct listEmp ListEmployees;
	loadEmp(ListEmployees);
	Menu(ListEmployees,tree);
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
//					default:
//						{
//							VeMenu();
//							chonMuc = -1;
//							return;
//						}
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
			else if (key == 27)
			{
				chonMuc = -1;
				VeMenu();
				return;
			}
			NoiBatMuc(viTriMenuPhu, chonMuc, menu, HL_MENU_PHU, 2);
		}
	}
}

void Materials(NODEPTR &tree)
{
	VeMenuPhu(0, MenuMater);
	int thaoTac;
	MenuPhu(0, MenuMater, 4, thaoTac);
	switch (thaoTac)
	{
		case 1:
			{
				Material newM;
				return VeKhungAddMat(tree, khungMat, 450, 600,1, newM);
			}
		case 2:
			{
				return inChoiceMat(tree, choiceObject,1);
			}
		case 3:
			{
				return inChoiceMat(tree, choiceObject,0);
			}
		case 4:
			{
				return inDanhSachMat(tree);
			}
	}
}

void Employees(struct listEmp &ListEmployees)
{
	VeMenuPhu(1, MenuEmp);
	int thaoTac;
	MenuPhu(1, MenuEmp, 4, thaoTac);
	switch (thaoTac)
	{
		case 1:
			{
				return VeKhungAddEmp(ListEmployees, khungEmp, 450, 600);
			}
		case 2:
			{
				return VeKhungAddEmp(ListEmployees, khungEmp, 450, 600);
			}
		case 3:
			{
				return showPage(300, 300 , 1, ceil(4/4));
			}
		case 4:
			{
				return inDanhSachEmp(ListEmployees);
			}
	}
}

void Bill(NODEPTR &tree)
{
	VeMenuPhu(2, MenuBill);
	int thaoTac;
	MenuPhu(2, MenuBill, 2, thaoTac);
	if (thaoTac == 1)
	{
		return VeKhungAddBill(tree, khungBill, 450, 600);	
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

void ChonMenuPhu(int x, struct listEmp &ListEmployees, NODEPTR &tree)
{
	switch(x)
	{
		case 0:	return Materials(tree);
		case 1: return Employees(ListEmployees);
		case 2:	return Bill(tree);
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

void Menu(struct listEmp &ListEmployees, NODEPTR &tree)
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
			else if (key == '\r')
			{
				VeMenu();
				ChonMenuPhu(chiMuc, ListEmployees, tree);
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


void VeMucChonNgay(int x, int y, char noiDungMucChon[][30], int ViTri, int mauNen, int mauChu)
{
	setbkcolor(mauNen);
	setcolor(mauChu);
	outtextxy(x, y, noiDungMucChon[4]);
	int H = textheight(noiDungMucChon[4]);
	int W = 55;
	int dis = 175;
	for(int i= 1; i <= 5; i++)
	{
		setfillstyle(SOLID_FILL, BLACK);
		if(i % 2 != 0)
		{
			setcolor(BLACK);
			if(i==1)
			{
				if (ViTri==1)
				{
					setfillstyle(SOLID_FILL, WHITE);
					setcolor(WHITE);					
				}
				else
					setfillstyle(SOLID_FILL, BLACK);
				line((x+dis-1)-1, y-2-1, (x+dis-1)-1, y+textheight(noiDungMucChon[4])+2);
				bar ((x+dis-1), y-2-1, (x+dis+sizeKhungDate[i-1]), y+textheight(noiDungMucChon[4])+2);
				setfillstyle(SOLID_FILL, TEXTBOX);
				bar ((x+dis-1), y-2,(x+dis+sizeKhungDate[i-1]), y+textheight(noiDungMucChon[4])+1);
			}
			else
			{
				if(ViTri == 2)
				{
					setfillstyle(SOLID_FILL, WHITE);
					setcolor(WHITE);
				}
				line((x+dis-1)+sizeKhungDate[1]-1, y-2-1, (x+dis-1)+sizeKhungDate[1]-1, y+textheight(noiDungMucChon[4])+2);
				bar ((x+dis-1)+sizeKhungDate[1], y-2-1, (x+dis+sizeKhungDate[2]), y+textheight(noiDungMucChon[4])+2);
				setfillstyle(SOLID_FILL, TEXTBOX);
				bar ((x+dis-1)+sizeKhungDate[1], y-2,(x+dis+sizeKhungDate[2]), y+textheight(noiDungMucChon[4])+1);
				line((x+dis+sizeKhungDate[2]), y-2-1, (x+dis+sizeKhungDate[2]), y+textheight(noiDungMucChon[4])+2);
				setfillstyle(SOLID_FILL, BLACK);
				setcolor(BLACK);
				if(ViTri == 3)
				{
					setfillstyle(SOLID_FILL, WHITE);
					setcolor(WHITE);
				}
				line((x+dis-1)+sizeKhungDate[3]-1, y-2-1, (x+dis-1)+sizeKhungDate[3]-1, y+textheight(noiDungMucChon[4])+2);
				bar ((x+dis-1)+sizeKhungDate[3], y-2-1, (x+dis+sizeKhungDate[4]), y+textheight(noiDungMucChon[4])+2);
				setfillstyle(SOLID_FILL, TEXTBOX);
				bar ((x+dis-1)+sizeKhungDate[3], y-2,(x+dis+sizeKhungDate[4]), y+textheight(noiDungMucChon[4])+1);
				line((x+dis+sizeKhungDate[4]), y-2-1, (x+dis+sizeKhungDate[4]), y+textheight(noiDungMucChon[4])+2);
			}
		}
		else
		{
			setcolor(WHITE);
			outtextxy(x+dis+(sizeKhungDate[i-2] + sizeKhungDate[i-1]) /2 , y-2, type[2] );
		}
			line((x+dis+sizeKhungDate[i-1]), y-2-1, (x+dis+sizeKhungDate[i-1]), y+textheight(noiDungMucChon[4])+2);
	}
}

void veKhungNut(int H, int W, char khungNoiDung[][30], bool Left, bool reset, int n)
{
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[n]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[n]))/2 + textheight(khungNoiDung[n]);
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
		outtextxy(L+midText1, D-midTextH, khungNoiDung[n]);
		setbkcolor(NEN_KHUNG);
		outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	}
	else	
	{
		bar (WD_WIDTH/2, D-kichThuocNut, R, D);
		setcolor(WHITE);
		setbkcolor(NEN_KHUNG);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[n]);
		setbkcolor(MAU_NUT_HL);
		outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	}
	setcolor(BLACK);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
}
void veMuc3Chon(int H, int W, char khungNoiDung[][30],int choose, bool reset, int &stt)
{
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2 +1;
	int R =	WD_WIDTH/2 + W/2 -1;
	int midText1 = ((R-L)/3 - textwidth(khungNoiDung[0]))/2;
	int midText2 = ((R-L)/3 - textwidth(khungNoiDung[1]))/2;
	int midText3 = ((R-L)/3 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut + 10 - textheight(khungNoiDung[0]))/2 + textheight(khungNoiDung[0]);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D-kichThuocNut/4);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(L, D-kichThuocNut/4, R, D-kichThuocNut/4);							//top line
	line(L, D-kichThuocNut, L, D-kichThuocNut/4);							//left line
	line(R, D-kichThuocNut, R, D-kichThuocNut/4);							//right line
	line(L+(R-L)/3, D-kichThuocNut, L+(R-L)/3, D-kichThuocNut/4);			//line between add and confirm 
	line(L+2*(R-L)/3, D-kichThuocNut, L+2*(R-L)/3, D-kichThuocNut/4);		// line between confirm and exit		
//	int choose = 1;
	int MAU_NUT_HL = HL_MENU_PHU;
	if (reset)
		MAU_NUT_HL = NEN_KHUNG;
	setfillstyle(SOLID_FILL, NEN_KHUNG);	
	if (choose == 1)
	{
		bar (L+(R-L)/3, D-kichThuocNut, L+2*(R-L)/3, D-kichThuocNut/4);
		bar (L+2*(R-L)/3, D-kichThuocNut, R, D-kichThuocNut/4);
		setfillstyle(SOLID_FILL, MAU_NUT_HL);	
		bar (L, D-kichThuocNut, L+(R-L)/3, D-kichThuocNut/4);
		setbkcolor(MAU_NUT_HL);
		setcolor(WHITE);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[0]);
		setbkcolor(NEN_KHUNG);
		outtextxy(L+(R-L)/3+midText2, D-midTextH, khungNoiDung[1]);
		setbkcolor(NEN_KHUNG);
		outtextxy(L+2*(R-L)/3+midText3, D-midTextH, khungNoiDung[2]);
	}
	else if(choose == 2)	
	{
		bar (L, D-kichThuocNut, L+(R-L)/3, D-kichThuocNut/4);
		bar (L+2*(R-L)/3, D-kichThuocNut, R, D-kichThuocNut/4);
		setfillstyle(SOLID_FILL, MAU_NUT_HL);	
		bar (L+(R-L)/3, D-kichThuocNut, L+2*(R-L)/3, D-kichThuocNut/4);
		setbkcolor(MAU_NUT_HL);
		setcolor(WHITE);
		outtextxy(L+(R-L)/3+midText2, D-midTextH, khungNoiDung[1]);
		setbkcolor(NEN_KHUNG);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[0]);
		setbkcolor(NEN_KHUNG);
		outtextxy(L+2*(R-L)/3+midText3, D-midTextH, khungNoiDung[2]);
	}
	else if(choose == 3)
	{
		bar (L, D-kichThuocNut, L+(R-L)/3, D-kichThuocNut/4);
		bar (L+(R-L)/3, D-kichThuocNut, L+2*(R-L)/3, D-kichThuocNut/4);
		setfillstyle(SOLID_FILL, MAU_NUT_HL);	
		bar (L+2*(R-L)/3, D-kichThuocNut, R, D-kichThuocNut/4);
		setbkcolor(MAU_NUT_HL);
		setcolor(WHITE);
		outtextxy(L+2*(R-L)/3+midText3, D-midTextH, khungNoiDung[2]);
		setbkcolor(NEN_KHUNG);
		outtextxy(L+(R-L)/3+midText2, D-midTextH, khungNoiDung[1]);
		setbkcolor(NEN_KHUNG);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[0]);
	}
	setcolor(BLACK);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(L, D-kichThuocNut/4, R, D-kichThuocNut/4);							//top line
	line(L, D-kichThuocNut, L, D-kichThuocNut/4);							//left line
	line(R, D-kichThuocNut, R, D-kichThuocNut/4);							//right line
	line(L+(R-L)/3, D-kichThuocNut, L+(R-L)/3, D-kichThuocNut/4);			//line between add and confirm 
	line(L+2*(R-L)/3, D-kichThuocNut, L+2*(R-L)/3, D-kichThuocNut/4);		// line between confirm and exit	
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

void noti(char khungNoiDung[])
{
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	int H = 100;
	int W = 250;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, D);
	
	setcolor(BLACK);
	rectangle(L-1, U-1, R+1, D+1);
	
	//in thong bao
	setcolor(WHITE);
	outtextxy(L+canLeGiua(khungNoiDung, W), U+(H-textheight(khungNoiDung))/2, khungNoiDung);
}

//=============endUI============//



//=========================================================DUCKHAI=================================================================//
void VeKhungAddMat(NODEPTR &tree, char khungNoiDung[][30], int H, int W,int Mcase, Material tmp) // 1: choose addMat 0: choose adjust
{
//	Material tmp;
	int cases = 1;
	if(Mcase == 0)
		cases = 7;
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
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[cases]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[cases]))/2 + textheight(khungNoiDung[cases]);
	setcolor(WHITE);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[cases]);
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
			veKhungNut(H, W, khungNoiDung, 1, 1,cases);
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
							veKhungNut(H, W, khungNoiDung, buttonL, 0,cases);
							
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
												veKhungNut(H, W, khungNoiDung, buttonL, 1,cases);
												goto cpos;
											}
										case KEY_DOWN:
											{
												pos++;
												veKhungNut(H, W, khungNoiDung, buttonL, 1,cases);
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
											NODEPTR p = Search(tree, tmp.code);
											if(p == NULL)
											{
												NotiY:
												++CountM;
												tmp.RealAmount =  ChangeCharToNum(tmp.amount,tmp.RealAmount);
												tree = Insert(tree,tmp.code,tmp);
												if(Mcase == 1)	
												{
													ThongBao(725, 130, Success[0], GREEN, MAU_MENU);
													Material newM;													
													return VeKhungAddMat(tree, khungMat, 450, 600,1,newM);	
												}
												else
												{
													ThongBao(720, 130, Success[2], GREEN, MAU_MENU);
													saveFile(tree, CountM);
													VeMenu();		
													return inChoiceMat(tree, choiceObject, 0);
												}
											}
											else
											{
												bool x = 1;
												notiBool(sameMat, x, 0);
												if(x)
												{
													--CountM;
													goto NotiY;
												}
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
										
										saveFile(tree, CountM);
										VeMenu();
										return;
									}
								}
								else if (key5 == 27)
								{
									saveFile(tree, CountM);
									VeMenu();
									return;
								}
								veKhungNut(H, W, khungNoiDung, buttonL, 0,cases);
							}
						}
					}
			}
		}
		
	}
}

void infoText(int x, int y, char noiDung[],char info[])
{
	setbkcolor(NEN_KHUNG);
	setcolor(WHITE);
	outtextxy(x, y, noiDung);
	int dis = 175;
	outtextxy(x+dis-1, y, info);
}

void hienThiInfoMat(NODEPTR &tree, char khungNoiDung[][30], int H, int W, char keyword[])
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
	//info
	NODEPTR tmp;
	tmp = Search(tree,keyword);
	infoText(380, ViTriKhung[1], khungNoiDung[1+2],tmp->info.code);
	infoText(380, ViTriKhung[2], khungNoiDung[2+2],tmp->info.name);
	infoText(380, ViTriKhung[3], khungNoiDung[3+2],tmp->info.type);
	infoText(380, ViTriKhung[4], khungNoiDung[4+2],tmp->info.amount);
	bool button = 1;
	veKhungNut(H, W, khungNoiDung, button, 0,1);
	while(1)
	{
		if(kbhit())
		{
			char key = getch();
			char ckey; 
			if(key == 0)
			{
				ckey = getch();
				switch(ckey)
				{
					case KEY_LEFT:
					{
						button ^= 1;
						break;
					}
					case KEY_RIGHT:
					{
						button ^= 1;
						break;
					}
				}
			}
			if(key == '\r')
				 {
				 	if(button == 1)
				 	{
				 		ThongBao(720, 130, Success[1], GREEN, MAU_MENU);
				 		--CountM;
				 		tree = deleteNode(tree,tmp->key);
						saveFile(tree, CountM);
				 		VeMenu();
				 		return inChoiceMat(tree, choiceObject,1);
					}
					else
					{
						VeMenu();
						return inChoiceMat(tree, choiceObject,1);
//						return; 
					}
				 }
			if(key==27)
			{
			 	VeMenu();
				return inChoiceMat(tree, choiceObject,1);
	//				 	return; 
			}
			veKhungNut(H, W, khungNoiDung, button, 0,1);
		}
	}
	
}


void inChoiceMat(NODEPTR &tree, char khungNoiDung[][30],bool RoA) // RoA = 1  remove, RoA = 0 adjust
{
	bool choice = 1;
	bool choiceN = 1; 
	int posR = 0;
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
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[3]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[4]))/2;
	int midText3 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(WHITE);
	// ve khung chon id
	rectangle(L+14, ViTriKhung[3]-11,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	setbkcolor(HL_MENU_PHU);
	setfillstyle(SOLID_FILL, HL_MENU_PHU);
	bar (L+15, ViTriKhung[3]-10,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
	setfillstyle(SOLID_FILL, TEXTBOX);
	bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
	rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
	//nhap o day
	// ve khung chon materials list 
	rectangle(WD_WIDTH/2-1, ViTriKhung[3]-11, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	setbkcolor(NEN_KHUNG);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(WD_WIDTH/2, ViTriKhung[3]-10, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[1]);	
	setfillstyle(SOLID_FILL, HL_MENU_PHU);	
	// 2 nut check and exit
	outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
	//make ur choice
	char findID[11];
	findID[0] = '\0';
	while(1)
	{
		InThongTin(L+30+2*textwidth(khungNoiDung[0]),ViTriKhung[3],findID);
		if(kbhit())
		{
			char keyR = getch();
				char ckeyR;
				if(keyR==0)
				{
					ckeyR = getch();
					switch(ckeyR)
					{
						case KEY_LEFT:
						{
							if(posR==1 || posR==0)
								choice ^= 1; // 1: trai 0: phai
							if(posR==2 || posR==3)
								choiceN ^= 1;	
							break;
						}
						case KEY_RIGHT:
						{
							if(posR==1 || posR==0)
								choice ^= 1; // 1: trai 0: phai
							if(posR==2 || posR==3)
								choiceN ^= 1;	
							break;
						}
						case KEY_UP:
						{
							if(posR == 0 || posR == 1)
							{
								posR = 2;
								break;
							}
							else if(posR == 2 || posR == 3)
								 {
								 	posR =0;
								 	choiceN = 1;
								 	break;
								 }		
						}
						case KEY_DOWN:
						{
							if(posR == 0 || posR == 1)
							{
								posR = 2;
								break;
							}
							else if(posR == 2 || posR == 3)
								 {
								 	posR =0;
								 	choiceN = 1;
								 	break;
								 }	
						}	
					}
				}
				if(keyR == '\r')
				{
					if(posR == 0 || posR == 1)
					{
						posR = 2;
					}
					else
					{
						if(choiceN)
						{
							if(choice == 1)
							{
								if(strlen(findID) != 0)
								{
									if(Search(tree,findID)==NULL)
									{
										//loi ko ton tai
										ThongBao(740, 255, Fail[1], LIGHTRED, MAU_MENU);
									}
									else
									{	
										if(RoA == 1)
											return hienThiInfoMat(tree, checkMat, 450, 600, findID); // den khung check info 1 Mats
										else
										{
											NODEPTR findM = Search(tree,findID);
											--CountM;
											Material CurrentM;
											CurrentM = findM->info;
											tree = deleteNode(tree, findID);
											return VeKhungAddMat(tree, khungMat, 450, 600,0,CurrentM);	
										}
									}
								}
								else
								{
									ThongBao(720, 255, Fail[0], LIGHTRED, MAU_MENU);
									posR = 0;
								}
							}
							else
							{
								return danhSachRoAMat(tree, CountM,RoA); //den khung danh sach
							}	
						}
						else
						{
							saveFile(tree, CountM);
							VeMenu();
							return;
						}
					}
				}
				if(keyR == 27)
				{
					saveFile(tree, CountM);
					VeMenu();
					return;
				}
		// hien thi
		 if(posR==0 || posR == 1)
		{
			setcolor(WHITE);
			setfillstyle(SOLID_FILL, NEN_KHUNG);
			if(choice)
			{
				// ID
				setbkcolor(NEN_KHUNG);
				bar(WD_WIDTH/2, ViTriKhung[3]-10, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[1]);
				setbkcolor(HL_MENU_PHU);
				setfillstyle(SOLID_FILL, HL_MENU_PHU);									//do mau nen cho nut
				bar (L+15, ViTriKhung[3]-10,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
				setfillstyle(SOLID_FILL, TEXTBOX);
				bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				Nhap(L+30+2*textwidth(khungNoiDung[0]),ViTriKhung[3],-1,keyR,findID,10);
			}
			else
			{
				// material list
				setbkcolor(NEN_KHUNG);
				bar (L+15, ViTriKhung[3]-10,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
				setfillstyle(SOLID_FILL, TEXTBOX);
				bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				setbkcolor(HL_MENU_PHU);
				setfillstyle(SOLID_FILL, HL_MENU_PHU);
				bar(WD_WIDTH/2, ViTriKhung[3]-10, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[1]);
			}
				setcolor(BLACK);
				setfillstyle(SOLID_FILL, NEN_KHUNG);
				bar (L, D-kichThuocNut, WD_WIDTH/2, D);
				bar (WD_WIDTH/2, D-kichThuocNut, R, D);				
				setbkcolor(NEN_KHUNG);
				line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
				line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
				setcolor(WHITE);
				outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
				outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
		}
		else if(posR==2 || posR==3)
			 {
				setcolor(WHITE);
				setfillstyle(SOLID_FILL, NEN_KHUNG);	
				if(choiceN)
				{	
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setbkcolor(HL_MENU_PHU);
					outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
					setbkcolor(NEN_KHUNG);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
				}
				else	
				{
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setbkcolor(HL_MENU_PHU);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
					setbkcolor(NEN_KHUNG);
					outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
				}
				setcolor(BLACK);
				line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
				line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
			 }		
		}
	} // while
}

void danhSachRoAMat(NODEPTR &tree, int &CountM, bool RoA) //1: Remove 2: Adjust
{
	//tao mang 1 chieu
	Name_Mat* arrM = new Name_Mat[CountM];
	index = 0;
	taoMangMat(tree, arrM);
	Qsort(arrM,0,CountM);
	int removePos = 0;
	int page = 1;
	bool select;
	while(1)
	{
		chonTuDanhSachMat(tree, arrM, CountM, removePos, page, select);
		if(select)
		{
			if(RoA)
			{
				--CountM;
				tree = deleteNode(tree, arrM[removePos].code);
				for (int i = removePos; i < CountM; arrM[i]=arrM[++i]);
			}
			else
			{
				NODEPTR findM = Search(tree,arrM[removePos].code);
				--CountM;
				Material CurrentM;
				CurrentM = findM->info;
				tree = deleteNode(tree, findM->key);
				VeMenu();
				return VeKhungAddMat(tree, khungMat, 450, 600,0,CurrentM);
			}
		}
		else
		{
			break;
		}
	}
	saveFile(tree, CountM);
	delete (arrM);
	VeMenu();
}



void chonTuDanhSachMat(NODEPTR &tree, Name_Mat *arrM, int CountM, int &stt, int &startPage, bool &selected)
{	
	//in danh sach
	//int startPage = 1;
	selected = false;
	int limitPage = ceil(CountM*1.0/OBJ_PER_PAGE);
	if (limitPage == 0)
	{
		noti(thongBao[0]);
	}
	else
	{
		// tinh thong so
		int kichThuocSTT = 30;
		int h = textheight(danhSachMat[0]) + 5*2;
		int H = (h)*OBJ_PER_PAGE + kichThuocSTT;
		int W = 0;
		for (int i = 0; i < 5; i++)
		{
			W += textwidth(danhSachMat[i]) + sizeDanhSachMat[i]*2;
		}
		int U = WD_HEIGHT/2 - H/2;
		int L =	WD_WIDTH/2 - W/2;
		
		int x = L, y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
		int yOld = y;
				
		inTrangMat(tree, danhSachMat, sizeDanhSachMat, arrM, 0);
		showPage(830, 650, startPage, limitPage);
		
		setcolor(GREEN);
		rectangle(x, y, x+W, y+h);
		while(1)
		{
			if(kbhit())
			{
				char key = getch();
				if (key == 0)
				{
					char nextK = getch();
					switch(nextK)
					{
						case KEY_PGUP:
							{
								startPage--;
								if (startPage < 1)
									startPage = limitPage;
								inTrangMat(tree, danhSachMat, sizeDanhSachMat, arrM, (startPage-1)*OBJ_PER_PAGE);
								showPage(830, 650, startPage, limitPage);
								stt = (startPage-1)*OBJ_PER_PAGE;
								break;
							}
						case KEY_PGDN:
							{
								startPage++;
								if (startPage > limitPage)
									startPage = 1;
								inTrangMat(tree, danhSachMat, sizeDanhSachMat, arrM, (startPage-1)*OBJ_PER_PAGE);
								showPage(830, 650, startPage, limitPage);
								stt = (startPage-1)*OBJ_PER_PAGE;
								break;
							}
						case KEY_UP:
							{
								stt--;
								break;
							}
						case KEY_DOWN:
							{
								stt++;
								break;
							}
					}
					if (stt < (startPage-1)*OBJ_PER_PAGE)
						stt = min((startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1), CountM-1);
					else if (stt > (startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1) || stt > CountM-1)
						stt = (startPage-1)*OBJ_PER_PAGE;
						
					y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
					// to den hinh chu nhat cu
					setcolor(BLACK);
					rectangle(x, yOld, x+W, yOld+h);
					// ve hinh chu nhat moi
					setcolor(GREEN);
					rectangle(x, y, x+W, y+h);
					yOld = y;
				}
				else if (key == 27) //exit
				{
					VeMenu();
					return;
				}
				else if (key == '\r')
				{
					selected = true;
					return;
				}
			}
		}
	}
}

//====================Material List==========================

void inTrangMat(NODEPTR &tree, char khungNoiDung[][30], int sizeKhungNoiDung[], Name_Mat arr[], int start)
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
	
	// in thong tin
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	int Size = CountM;
	NODEPTR p; 
	for (int i = start; i < min(start+OBJ_PER_PAGE, Size); i++)
	{
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i+1);
		outtextxy(disW + canLeGiua(d, textwidth(khungNoiDung[0])+sizeKhungNoiDung[0]*2), dis, d);
		disW += textwidth(khungNoiDung[0]) + sizeKhungNoiDung[0]*2;
		p = Search(tree, arr[i].code);
		if(p != NULL)
		{
			inVatTu(p->info, disW, dis);
		}
		dis += h+5;
	}
}

void inVatTu(Material VT, int posX, int posY)
{
	// in ID
	outtextxy(posX + canLeGiua(VT.code, textwidth(danhSachMat[1])+sizeDanhSachMat[1]*2), posY, VT.code);
	posX += textwidth(danhSachMat[1]) + sizeDanhSachMat[1]*2;
	
	// in Name
	outtextxy(posX + 10, posY, VT.name);
	posX += textwidth(danhSachMat[2]) + sizeDanhSachMat[2]*2;
	
	// in type
	outtextxy(posX + canLeGiua(VT.type , textwidth(danhSachMat[3])+sizeDanhSachMat[3]*2), posY, VT.type);
	posX += textwidth(danhSachMat[3]) + sizeDanhSachMat[3]*2;
	
	// in Amount
	outtextxy(posX + canLeGiua(VT.amount , textwidth(danhSachMat[4])+sizeDanhSachMat[4]*2), posY, VT.amount);		
	posX += textwidth(danhSachMat[4]) + sizeDanhSachMat[4]*2;
}

void taoMangMat(NODEPTR &tree, Name_Mat arrM[])
{
	if(tree != NULL)
	{
		taoMangMat(tree->left,arrM);
		get_chuoi(arrM[index].name, tree->info.name);
		strcpy(arrM[index++].code, tree->info.code);
		taoMangMat(tree->right,arrM);
	}
	else
		return;
}
void inDanhSachMat(NODEPTR &tree)
{
	Name_Mat* arrM = new Name_Mat[CountM];
	index = 0;
	taoMangMat(tree,arrM);
	Qsort(arrM,0,CountM);
	//in danh sach
	// chuyen trang bla bla
	int startPage = 1;
	int limitPage = ceil(CountM*1.0/OBJ_PER_PAGE);
	if (limitPage == 0)
	{
		VeMenu();
		noti(thongBao[0]);
	}
	else
	{
		inTrangMat(tree, danhSachMat, sizeDanhSachMat, arrM, 0);
		showPage(830, 650, startPage, limitPage);
		while(1)
		{
			if(kbhit())
			{
				char key = getch();
				if (key == 0)
				{
					char nextK = getch();
					switch(nextK)
					{
						case KEY_PGUP:
							{
								startPage--;
								if (startPage < 1)
									startPage = limitPage;
								inTrangMat(tree, danhSachMat, sizeDanhSachMat, arrM, (startPage-1)*OBJ_PER_PAGE);	
								showPage(830, 650, startPage, limitPage);
								break;
							}
						case KEY_PGDN:
							{
								startPage++;
								if (startPage > limitPage)
									startPage = 1;
								inTrangMat(tree, danhSachMat, sizeDanhSachMat, arrM, (startPage-1)*OBJ_PER_PAGE);
								showPage(830, 650, startPage, limitPage);
								break;
							}
					}
				}
				else if(key == 27) //exit
				{
					VeMenu();
					return;
				}
			}
		}
	}
	delete[] (arrM);
}

//===================================================endDUCKHAI=========================================//



//===================================================CHINHAN===========================================//

void VeKhungAddEmp(struct listEmp &ListEmployees, char khungNoiDung[][30], int H, int W)
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
						veKhungNut(H, W, khungNoiDung, buttonL, 0,1);
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
												veKhungNut(H, W, khungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_DOWN:
											{
												pos++;
												veKhungNut(H, W, khungNoiDung, buttonL, 1,1);
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
											return VeKhungAddEmp(ListEmployees, khungEmp, 450, 600);
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
								veKhungNut(H, W, khungNoiDung, buttonL, 0,1);
							}
						}
					}
			}
		}
	}
}


void inTrangEmp(struct listEmp &list, char khungNoiDung[][30], int sizeKhungNoiDung[], struct NamesInfoEmp arr[], int start)
{
	int kichThuocSTT = 30;
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
	
	// in thong tin
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	int Size = list.n;
	for (int i = start; i < min(start+OBJ_PER_PAGE, Size); i++)
	{
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i+1);
		outtextxy(disW + canLeGiua(d, textwidth(khungNoiDung[0])+sizeKhungNoiDung[0]*2), dis, d);
		disW += textwidth(khungNoiDung[0]) + sizeKhungNoiDung[0]*2;
		
		inNhanVien(list.Search_ID(arr[i].ID), disW, dis);
		
		dis += h+5;
	}
	
	setbkcolor(MAU_NEN);
}

void inNhanVien(struct Employee *NV, int posX, int posY)
{
	// in ID
	outtextxy(posX + canLeGiua(NV->ID, textwidth(danhSachEmp[1])+sizeDanhSachEmp[1]*2), posY, NV->ID);
	posX += textwidth(danhSachEmp[1]) + sizeDanhSachEmp[1]*2;
	
	// in Last Name
	outtextxy(posX + 10, posY, NV->lastName);
	posX += textwidth(danhSachEmp[2]) + sizeDanhSachEmp[2]*2;
	
	// in First Name
	outtextxy(posX + 10, posY, NV->firstName);
	posX += textwidth(danhSachEmp[3]) + sizeDanhSachEmp[3]*2;
	
	// in Sex
	if (NV->sex) // is Male
		outtextxy(posX + canLeGiua(danhSachEmp[5] , textwidth(danhSachEmp[4])+sizeDanhSachEmp[4]*2), posY, danhSachEmp[5]);
	else
		outtextxy(posX + canLeGiua(danhSachEmp[6] , textwidth(danhSachEmp[4])+sizeDanhSachEmp[4]*2), posY, danhSachEmp[6]);
		
	posX += textwidth(danhSachEmp[4]) + sizeDanhSachEmp[4]*2;
}

void taoMangEmp(struct listEmp &ListEmployees, struct NamesInfoEmp *arr)
{
	for (int i = 0; i < ListEmployees.n; i++)
	{
		strcpy(arr[i].fName, ListEmployees.nodeListEmp[i]->firstName);
		delBlank(arr[i].fName);
		strcpy(arr[i].lName, ListEmployees.nodeListEmp[i]->lastName);
		delBlank(arr[i].lName);
		strcpy(arr[i].ID, ListEmployees.nodeListEmp[i]->ID);
	}
}

void inDanhSachEmp(struct listEmp &ListEmployees)
{
	NamesInfoEmp *arrEmp = new NamesInfoEmp[ListEmployees.n];
	
	taoMangEmp(ListEmployees, arrEmp);
	// sort bla bla;
	sortEmp(arrEmp, 0, ListEmployees.n-1);
	
	//in danh sach
	int startPage = 1;
	int limitPage = ceil(ListEmployees.n*1.0/OBJ_PER_PAGE);
	if (limitPage == 0)
	{
		noti(thongBao[0]);
	}
	else
	{
		inTrangEmp(ListEmployees, danhSachEmp, sizeDanhSachEmp, arrEmp, 0);
		showPage(830, 650, startPage, limitPage);
		while(1)
		{
			if(kbhit())
			{
				char key = getch();
				if (key == 0)
				{
					char nextK = getch();
					switch(nextK)
					{
						case KEY_PGUP:
							{
								startPage--;
								if (startPage < 1)
									startPage = limitPage;
								inTrangEmp(ListEmployees, danhSachEmp, sizeDanhSachEmp, arrEmp, (startPage-1)*OBJ_PER_PAGE);
								showPage(830, 650, startPage, limitPage);
								break;
							}
						case KEY_PGDN:
							{
								startPage++;
								if (startPage > limitPage)
									startPage = 1;
								inTrangEmp(ListEmployees, danhSachEmp, sizeDanhSachEmp, arrEmp, (startPage-1)*OBJ_PER_PAGE);
								showPage(830, 650, startPage, limitPage);
								break;
							}
					}
				}
				else if(key == 27) //exit
				{
					VeMenu();
					return;
				}
			}
		}
	}
	delete (arrEmp);
}

void chonTuDanhSach(struct listEmp &ListEmployees, NamesInfoEmp *arrEmp, int &stt, int &startPage, bool &selected)
{	
	//in danh sach
	//int startPage = 1;
	selected = false;
	int limitPage = ceil(ListEmployees.n*1.0/OBJ_PER_PAGE);
	if (limitPage == 0)
	{
		noti(thongBao[0]);
	}
	else
	{
		// tinh thong so
		int kichThuocSTT = 30;
		int h = textheight(danhSachEmp[0]) + 5*2;
		int H = (h)*OBJ_PER_PAGE + kichThuocSTT;
		int W = 0;
		for (int i = 0; i < 5; i++)
		{
			W += textwidth(danhSachEmp[i]) + sizeDanhSachEmp[i]*2;
		}
		int U = WD_HEIGHT/2 - H/2;
		int L =	WD_WIDTH/2 - W/2;
		
		int x = L, y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
		int yOld = y;
				
		inTrangEmp(ListEmployees, danhSachEmp, sizeDanhSachEmp, arrEmp, 0);
		showPage(830, 650, startPage, limitPage);
		
		setcolor(GREEN);
		rectangle(x, y, x+W, y+h);
		while(1)
		{
			if(kbhit())
			{
				char key = getch();
				if (key == 0)
				{
					char nextK = getch();
					switch(nextK)
					{
						case KEY_PGUP:
							{
								startPage--;
								if (startPage < 1)
									startPage = limitPage;
								inTrangEmp(ListEmployees, danhSachEmp, sizeDanhSachEmp, arrEmp, (startPage-1)*OBJ_PER_PAGE);
								showPage(830, 650, startPage, limitPage);
								stt = (startPage-1)*OBJ_PER_PAGE;
								break;
							}
						case KEY_PGDN:
							{
								startPage++;
								if (startPage > limitPage)
									startPage = 1;
								inTrangEmp(ListEmployees, danhSachEmp, sizeDanhSachEmp, arrEmp, (startPage-1)*OBJ_PER_PAGE);
								showPage(830, 650, startPage, limitPage);
								stt = (startPage-1)*OBJ_PER_PAGE;
								break;
							}
						case KEY_UP:
							{
								stt--;
								break;
							}
						case KEY_DOWN:
							{
								stt++;
								break;
							}
					}
					if (stt < (startPage-1)*OBJ_PER_PAGE)
						stt = min((startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1), ListEmployees.n-1);
					else if (stt > (startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1) || stt > ListEmployees.n-1)
						stt = (startPage-1)*OBJ_PER_PAGE;
						
					y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
					// to den hinh chu nhat cu
					setcolor(BLACK);
					rectangle(x, yOld, x+W, yOld+h);
					// ve hinh chu nhat moi
					setcolor(GREEN);
					rectangle(x, y, x+W, y+h);
					yOld = y;
				}
				else if (key == 27) //exit
				{
					VeMenu();
					return;
				}
				else if (key == '\r')
				{
					selected = true;
					return;
				}
			}
		}
	}
}

void danhSachRemoveEmp(struct listEmp &ListEmployees)
{
	//tao mang 1 chieu
	NamesInfoEmp *arrEmp = new NamesInfoEmp[ListEmployees.n];
	taoMangEmp(ListEmployees, arrEmp);
	sortEmp(arrEmp, 0, ListEmployees.n-1);
	
	int removePos = 0;
	int page = 1;
	bool select;
	while(1)
	{
		chonTuDanhSach(ListEmployees, arrEmp, removePos, page, select);
		if(select)
		{
			ListEmployees.DeteleID(arrEmp[removePos].ID);
			for (int i = removePos; i < ListEmployees.n; arrEmp[i]=arrEmp[++i]);
		}
		else
		{
			break;
		}
	}
	delete (arrEmp);
	VeMenu();
}

void inRemoveEmp(char khungNoiDung[][30], struct listEmp &ListEmployees)
{
	bool choice = 1;
	bool choiceN = 1; 
	int posR = 0;
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
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[3]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[4]))/2;
	int midText3 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(WHITE);
	// ve khung chon id
	rectangle(L+14, ViTriKhung[3]-11,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	setbkcolor(HL_MENU_PHU);
	setfillstyle(SOLID_FILL, HL_MENU_PHU);
	bar (L+15, ViTriKhung[3]-10,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
	setfillstyle(SOLID_FILL, TEXTBOX);
	bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
	rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
	//nhap o day
	// ve khung chon materials list 
	rectangle(WD_WIDTH/2-1, ViTriKhung[3]-11, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	setbkcolor(NEN_KHUNG);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(WD_WIDTH/2, ViTriKhung[3]-10, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[1]);	
	setfillstyle(SOLID_FILL, HL_MENU_PHU);	
	// 2 nut check and exit
	outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
	//make ur choice
	char findID[11];
	findID[0] = '\0';
	while(1)
	{
		InThongTin(L+30+2*textwidth(khungNoiDung[0]),ViTriKhung[3],findID);
		if(kbhit())
		{
			char keyR = getch();
			if(keyR==0)
			{
				char ckeyR = getch();
				switch(ckeyR)
				{
					case KEY_LEFT:
					{
						if(posR==1 || posR==0)
							choice ^= 1; // 1: trai 0: phai
						if(posR==2 || posR==3)
							choiceN ^= 1;	
						break;
					}
					case KEY_RIGHT:
					{
						if(posR==1 || posR==0)
							choice ^= 1; // 1: trai 0: phai
						if(posR==2 || posR==3)
							choiceN ^= 1;	
						break;
					}
					case KEY_UP:
					{
						if(posR == 0 || posR == 1)
						{
							posR = 2;
							break;
						}
						else if(posR == 2 || posR == 3)
						{
							posR =0;
							break;
						}		
					}
					case KEY_DOWN:
					{
						if(posR == 0 || posR == 1)
						{
							posR = 2;
							break;
						}
						else if(posR == 2 || posR == 3)
						{
							posR =0;
							break;
						}	
					}	
				}
			}
			if(keyR == '\r')
			{
				if(posR == 0 || posR == 1)
				{
					posR = 2;
				}
				else
				{
					if(posR == 2)
					{
						if(choice == 1)
						{
							struct Employee *tmp = new Employee;
							tmp = ListEmployees.Search_ID(findID);
							if(tmp == NULL)
							{
								//loi ko ton tai
								ThongBao(740, 255, Fail[1], LIGHTRED, MAU_MENU);
							}
							else
							{	
								return hienThiInfoEmp(checkMat, 450, 600, tmp); // den khung check info 1 Mats
							}
							delete(tmp);
						}
						else
						{
							return danhSachRemoveEmp(ListEmployees);
						}	
					}
					if(posR == 3)
					{
						return;
					}
				}
			}
			if(keyR == 27)
			{
				return;
			}
		// hien thi
		 if(posR==0 || posR == 1)
		{
			setcolor(WHITE);
			setfillstyle(SOLID_FILL, NEN_KHUNG);
			if(choice)
			{
				// ID
				setbkcolor(NEN_KHUNG);
				bar(WD_WIDTH/2, ViTriKhung[3]-10, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[1]);
				setbkcolor(HL_MENU_PHU);
				setfillstyle(SOLID_FILL, HL_MENU_PHU);									//do mau nen cho nut
				bar (L+15, ViTriKhung[3]-10,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
				setfillstyle(SOLID_FILL, TEXTBOX);
				bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				Nhap(L+30+2*textwidth(khungNoiDung[0]),ViTriKhung[3],-1,keyR,findID,10);
			}
			else
			{
				// material list
				setbkcolor(NEN_KHUNG);
				bar (L+15, ViTriKhung[3]-10,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
				setfillstyle(SOLID_FILL, TEXTBOX);
				bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				setbkcolor(HL_MENU_PHU);
				setfillstyle(SOLID_FILL, HL_MENU_PHU);
				bar(WD_WIDTH/2, ViTriKhung[3]-10, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[1]);
			}
				setcolor(BLACK);
				setfillstyle(SOLID_FILL, NEN_KHUNG);
				bar (L, D-kichThuocNut, WD_WIDTH/2, D);
				bar (WD_WIDTH/2, D-kichThuocNut, R, D);				
				setbkcolor(NEN_KHUNG);
				line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
				line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
				setcolor(WHITE);
				outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
				outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
		}
		else if(posR==2 || posR==3)
			 {
				setcolor(WHITE);
				setfillstyle(SOLID_FILL, NEN_KHUNG);	
				if(choiceN)
				{	
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setbkcolor(HL_MENU_PHU);
					outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
					setbkcolor(NEN_KHUNG);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
				}
				else	
				{
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setbkcolor(HL_MENU_PHU);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
					setbkcolor(NEN_KHUNG);
					outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
				}
				setcolor(BLACK);
				line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
				line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
			 }		
		}
	} // while
}

void hienThiInfoEmp(char khungNoiDung[][30], int H, int W, struct Employee *Info)
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
	
	
	//info
	infoText(380, ViTriKhung[1], khungNoiDung[1+2], Info->ID);
	infoText(380, ViTriKhung[2], khungNoiDung[2+2], Info->firstName);
	infoText(380, ViTriKhung[3], khungNoiDung[3+2], Info->lastName);
	veMuc2Chon(380, ViTriKhung[4], khungNoiDung[4+2], Sex, Info->sex, NEN_KHUNG, WHITE);
	bool buttonL = 1;
	while(1)
	{
		if(kbhit())
		{
			veKhungNut(H, W, khungNoiDung, buttonL, 0,1);
			char key = getch();
			char ckey = getch();
			if(key==0)
			{
				switch(ckey)
				{
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
			else if(key == '\r')
				 {
				 	if(buttonL)
				 	{
				 		ThongBao(720, 130, Success[1], GREEN, MAU_MENU);
				 		VeMenu();
				 		return ;
					}
					else
					{
						VeMenu();
						return;
					}
				 }
				 if(key==27)
				 {
				 	VeMenu();
				 	return;
				 }
		}
	}
}


void inTrangBill(struct listEmp &list, struct listBillDate *arr, int start)
{
	int kichThuocSTT = 30;
	int h = textheight(trangBill[0]);
	int H = (h+5*2)*OBJ_PER_PAGE + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 7; i++)
	{
		W += textwidth(trangBill[i]) + sizeTrangBill[i]*2;
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
	for (int i = 0; i < 7; i++)
	{
		dis += sizeTrangBill[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, trangBill[i]);
		dis += textwidth(trangBill[i]) + sizeTrangBill[i];
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
	
	// in thong tin
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	int Size = arr->Size;
	for (int i = start; i < min(start+OBJ_PER_PAGE, Size); i++)
	{
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i+1);
		outtextxy(disW + canLeGiua(d, textwidth(trangBill[0])+sizeTrangBill[0]*2), dis, d);
		disW += textwidth(trangBill[0]) + sizeTrangBill[0]*2;
		
		//inNhanVien(list.Search_ID(arr[i].ID), disW, dis);
		
		dis += h+5;
	}
	
	setbkcolor(MAU_NEN);
}


void taoMangBillDate(struct listEmp &List, struct listBillDate *arr, struct Dates dayBegin, struct Dates dayEnd)
{
	for (int i = 0; i < List.n; i++)
	{
		NODE_LB p;
		for (p = List.nodeListEmp[i]->listBill.firstNode; p != NULL; p = p->next)
		{
			struct Dates curDate = p->info.date;
			if ((curDate < dayEnd || curDate == dayEnd) && (curDate > dayBegin || curDate == dayBegin))
				arr->insert(p->info);
		}
	}
}

void thongKeBill(struct listEmp &ListEmployees)
{
	struct listBillDate *arrBill = new listBillDate;
	Dates dayBegin, dayEnd;
	
	//get day
	//bla bla
	
	taoMangBillDate(ListEmployees, arrBill, dayBegin, dayEnd);
	
	//in danh sach
	int startPage = 1;
	int limitPage = ceil(arrBill->Size*1.0/OBJ_PER_PAGE);
	//fix here first
	if (limitPage != 0)
	{
		noti(Fail[2]);
	}
	else
	{
		inTrangBill(ListEmployees, arrBill, 0);
		showPage(830, 650, startPage, limitPage);
		while(1)
		{
			if(kbhit())
			{
				char key = getch();
				if (key == 0)
				{
					char nextK = getch();
					switch(nextK)
					{
						case KEY_PGUP:
							{
								startPage--;
								if (startPage < 1)
									startPage = limitPage;
								inTrangBill(ListEmployees, arrBill, (startPage-1)*OBJ_PER_PAGE);
								showPage(830, 650, startPage, limitPage);
								break;
							}
						case KEY_PGDN:
							{
								startPage++;
								if (startPage > limitPage)
									startPage = 1;
								inTrangBill(ListEmployees, arrBill, (startPage-1)*OBJ_PER_PAGE);
								showPage(830, 650, startPage, limitPage);
								break;
							}
					}
				}
				else if(key == 27) //exit
				{
					VeMenu();
					return;
				}
			}
		}
	}
	delete (arrBill);
}

//==========endCHINHAN========




void VeKhungAddBill(NODEPTR &tree, char khungNoiDung[][30], int H, int W)
{
	int soLuongKhung = 5;
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
			{
				if(i==2)
					VeMucChonNgay(380, ViTriKhung[i], khungNoiDung, 0, NEN_KHUNG, WHITE);
				else
					veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, WHITE);
			}
		}
		else
		{
			veMuc2Chon(380, ViTriKhung[i], khungNoiDung[i+2], type, 1, NEN_KHUNG, WHITE);
		}
	}
	int pos = 1;
	int fst = 1;
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
					pos = 6;
				if (pos > 6)
					pos = 1;
			}
			else if (key == '\r')
			{
				if (pos <= 5)
					pos++;
			}
			else if (key == 27)
			{
				//VeMenu();
				return;
			}
			
			setbkcolor(NEN_TEXT);	
			for (int i = 1; i <= 5; i++)
			{
				if (i != 5)
				{
					if (i == 1)
						veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 1, NEN_KHUNG, WHITE);
					if(i==2)
						VeMucChonNgay(380, ViTriKhung[i], khungNoiDung, 0, NEN_KHUNG, WHITE);
					else
					{
						veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, WHITE);
					}
				}
				else
				{
					veMuc2Chon(380, ViTriKhung[i], khungNoiDung[i+2], type, 1, NEN_KHUNG, WHITE);
				}
			}
			setbkcolor(NEN_TEXT);
//			InThongTin(560, ViTriKhung[1], tmpE->ID);
//			InThongTin(560, ViTriKhung[2], tmpE->firstName);
//			InThongTin(560, ViTriKhung[3], tmpE->lastName);
			switch(pos)
			{
				case 1:
					{
						veKhung(380, 200, khungNoiDung[3], 1, NEN_KHUNG, WHITE);
//						Nhap(560, 200, -1, key, tmpE->ID, 10);
						break;
					}
				case 2:
					{
						int ViTri = 1 ;
						VeMucChonNgay(380, ViTriKhung[2], khungNoiDung, ViTri, NEN_KHUNG, WHITE);
						while(1)
						{
							if (kbhit())
							{
								char key2 = getch();
								if (key2 == 0)
								{
									char c2Next = getch();
									switch(c2Next)
									{
										case KEY_LEFT:
										{
											ViTri--;
											break;
										}
										case KEY_RIGHT:
										{
											ViTri++;
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
								else if (key2 == '\r')
								{
									pos++;
									goto cpos;
								}
								else if (key2 == 27)
								{
									VeMenu();
									return;
								}
								if (ViTri == 0)
									ViTri = 3;
								if (ViTri > 3)
									ViTri = 1;								
								VeMucChonNgay(380, ViTriKhung[2], khungNoiDung, ViTri, NEN_KHUNG, WHITE);
							}
						}
//						Nhap(560, 260, 1, key, tmpE->firstName, 25);
						break;
					}
				case 3:
					{
						veKhung(380, 320, khungNoiDung[5], 1, NEN_KHUNG, WHITE);
//						Nhap(560, 320, 1, key, tmpE->lastName, 25);
						break;
					}
				case 4:
					{
						veKhung(380, 380, khungNoiDung[6], 1, NEN_KHUNG, WHITE);
//								tmpE->sex = fst;
						break;
					}
				case 5:
					{
						veMuc2Chon(380, 440, khungNoiDung[7], type, fst, NEN_KHUNG, WHITE);
						while(1)
						{
							if (kbhit())
							{
								char key5 = getch();
								if (key5 == 0)
								{
									char c5Next = getch();
									switch(c5Next)
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
								else if (key5 == '\r')
								{
									pos++;
									goto cpos;
									break;
								}
								else if (key5 == 27)
								{
									return;
								}
								if (fst == -1)
									fst = 1;
								if (fst > 1)
									fst = 0;								
								veMuc2Chon(380, 440, khungNoiDung[7], type, fst, NEN_KHUNG, WHITE);
							}
						}
					}	
				case 6:
					{
						bool buttonL = 1;
						veKhungNut(H, W, khungNoiDung, buttonL, 0,1);
						while(1)
						{
							if(kbhit())
							{
								char key6 = getch();
								char c6Next;
								if (key6 == 0)
								{
									c6Next = getch();
									switch(c6Next)
									{
										case KEY_UP:
											{
												pos--;
												veKhungNut(H, W, khungNoiDung, buttonL, 1,1);
												goto cpos;
											}
										case KEY_DOWN:
											{
												pos++;
												veKhungNut(H, W, khungNoiDung, buttonL, 1,1);
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
								else if (key6 == '\r')
								{
									//return;
									if (buttonL == 1)
									{
										// den material list
										danhSachBill(tree,CountM,1);
									}
									else
									{
										VeMenu();
										return;
									}
								}
								else if (key6 == 27)
								{
									VeMenu();
									return;
								}
								veKhungNut(H, W, khungNoiDung, buttonL, 0,1);
							}
						}
					}
			}
		}
	}
}

void danhSachBill(NODEPTR &tree, int &CountM, bool choice)
{
	//tao mang 1 chieu
	Name_Mat* arrM = new Name_Mat[20];
	index = 0;
//	taoMangMat(tree, arrM);
//	Qsort(arrM,0,CountM);
	int removePos = 0;
	bool select;
	int choose = 1;
	Material tmp;
	while(1)
	{
		chonTuDanhSachBill(tree, arrM, CountM, removePos, select);
		if(select)
		{
			return VeKhungChooseBill(tree, khungMat, 450, 600,tmp);
		}
		else
		{
			break;
		}
	}
	saveFile(tree, CountM);
	delete (arrM);
	VeMenu();
}

void chonTuDanhSachBill(NODEPTR &tree, Name_Mat *arrM, int CountM, int &stt, bool &selected)
{	
	//in danh sach
	//int startPage = 1;
	selected = false; 
		// tinh thong so
		int kichThuocSTT = 30;
		int h = textheight(danhSachMat[0]) + 5*2;
		int H = (h)*20 + kichThuocSTT;
		int W = 0;
		for (int i = 0; i < 5; i++)
		{
			W += textwidth(danhSachMat[i]) + sizeDanhSachMat[i]*2;
		}
		int U = WD_HEIGHT/2 - H/2;
		int L =	WD_WIDTH/2 - W/2;
		
		int x = L, y = U+kichThuocSTT+(stt%20)*h;
		int yOld = y;
				
		inTrangBill(tree, danhSachMat, sizeDanhSachMat, arrM, 0);
		
		setcolor(GREEN);
		rectangle(x, y, x+W, y+h);
		int choose = 1;
		veMuc3Chon(673,635,khungListBill,choose, 1, stt);
		while(1)
		{
			if(kbhit())
			{
				char key = getch();
				if (key == 0)
				{
					char nextK = getch();
					switch(nextK)
					{
						case KEY_UP:
							{
								stt--;
								break;
							}
						case KEY_DOWN:
							{
								stt++;
								break;
							}
						case KEY_LEFT:
							{
								if(stt == 20)
								{
									choose--;
								}
								break;
							}
						case KEY_RIGHT:
							{
								if(stt == 20)
								{
									choose++;
								}
								break;
							}				
					}
					if (stt == -1)
						stt = 20;
					else if (stt > 20)
						stt = 0;
					if(choose == 0)
					{
						choose = 3;
					}
					else if(choose > 3)
							choose = 1;
					if(stt >= 0 && stt <= 19)
					{
						y = U+kichThuocSTT+(stt%20)*h;
						// to den hinh chu nhat cu
						setcolor(BLACK);
						rectangle(x, yOld, x+W, yOld+h);
						// ve hinh chu nhat moi
						setcolor(GREEN);
						rectangle(x, y, x+W, y+h);
						yOld = y;
					}
					if(stt == 20)
					{
						
						setcolor(BLACK);
						rectangle(x, yOld, x+W, yOld+h);
						veMuc3Chon(673,635,khungListBill,choose, 0, stt);
					}
					else
					{
						choose = 1;
						veMuc3Chon(673,635,khungListBill,choose, 1, stt);
					}
				}
				else if (key == 27) //exit
				{
					// neu list rong thi thong bao
					VeMenu();
					return;
				}
				else if (key == '\r')
				{
					if(stt >= 0 && stt <= 19) //chon tung phan tu
					{
						selected = true;
						
					}
					if(stt == 20)
					{
						if(choose == 1)
						{
							//add material
							VeMenu();
							return inChoiceBill(tree,choiceObject,1); // NoX = 1  nhap, RoA = 0 xuat
						}
						else if(choose == 2)
							{
								//confirm
								// neu list rong thi bao loi
							}
							else
							{
								// exit
							}
					}
				}
			}
		}
}

void inTrangBill(NODEPTR &tree, char khungNoiDung[][30], int sizeKhungNoiDung[], Name_Mat arr[], int start)
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
	
	// in thong tin
	setcolor(WHITE);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	int Size = 20;
	for (int i = start; i < 20; i++)
	{
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i+1);
		outtextxy(disW + canLeGiua(d, textwidth(khungNoiDung[0])+sizeKhungNoiDung[0]*2), dis, d);
		disW += textwidth(khungNoiDung[0]) + sizeKhungNoiDung[0]*2;
//		p = Search(tree, arr[i].code);
//		if(p != NULL)
//		{
//			inVatTu(p->info, disW, dis);
//		}
		dis += h+5;
	}
}

void inChoiceBill(NODEPTR &tree, char khungNoiDung[][30],bool NoX) // NoX = 1  nhap, RoA = 0 xuat
{
	bool choice = 1;
	bool choiceN = 1; 
	int posR = 0;
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
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[3]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[4]))/2;
	int midText3 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(WHITE);
	// ve khung chon id
	rectangle(L+14, ViTriKhung[3]-11,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	setbkcolor(HL_MENU_PHU);
	setfillstyle(SOLID_FILL, HL_MENU_PHU);
	bar (L+15, ViTriKhung[3]-10,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
	setfillstyle(SOLID_FILL, TEXTBOX);
	bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
	rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
	//nhap o day
	// ve khung chon materials list 
	rectangle(WD_WIDTH/2-1, ViTriKhung[3]-11, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	setbkcolor(NEN_KHUNG);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(WD_WIDTH/2, ViTriKhung[3]-10, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[1]);	
	setfillstyle(SOLID_FILL, HL_MENU_PHU);	
	// 2 nut check and exit
	outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
	//make ur choice
	char findID[11];
	findID[0] = '\0';
	while(1)
	{
		InThongTin(L+30+2*textwidth(khungNoiDung[0]),ViTriKhung[3],findID);
		if(kbhit())
		{
			char keyR = getch();
				char ckeyR;
				if(keyR==0)
				{
					ckeyR = getch();
					switch(ckeyR)
					{
						case KEY_LEFT:
						{
							if(posR==1 || posR==0)
								choice ^= 1; // 1: trai 0: phai
							if(posR==2 || posR==3)
								choiceN ^= 1;	
							break;
						}
						case KEY_RIGHT:
						{
							if(posR==1 || posR==0)
								choice ^= 1; // 1: trai 0: phai
							if(posR==2 || posR==3)
								choiceN ^= 1;	
							break;
						}
						case KEY_UP:
						{
							if(posR == 0 || posR == 1)
							{
								posR = 2;
								break;
							}
							else if(posR == 2 || posR == 3)
								 {
								 	posR =0;
								 	choiceN = 1;
								 	break;
								 }		
						}
						case KEY_DOWN:
						{
							if(posR == 0 || posR == 1)
							{
								posR = 2;
								break;
							}
							else if(posR == 2 || posR == 3)
								 {
								 	posR =0;
								 	choiceN = 1;
								 	break;
								 }	
						}	
					}
				}
				if(keyR == '\r')
				{
					if(posR == 0 || posR == 1)
					{
						posR = 2;
					}
					else
					{
						if(choiceN)
						{
							if(choice == 1)
							{
								if(strlen(findID) != 0)
								{
									if(Search(tree,findID)==NULL)
									{
										//loi ko ton tai
										ThongBao(740, 255, Fail[1], LIGHTRED, MAU_MENU);
									}
									else
									{
										NODEPTR tmp = Search(tree,findID);	
										return hienThiInfoBill(tree, checkMat, 450, 600, findID); // den khung add Mats	
//										return VeKhungChooseBill(tree, khungMat, 450, 600,tmp->info);
									}
								}
								else
								{
									ThongBao(720, 255, Fail[0], LIGHTRED, MAU_MENU);
									posR = 0;
								}
							}
							else
							{
								return danhSachBill(tree, CountM,1); //den khung danh sach
							}	
						}
						else
						{
//							saveFile(tree, CountM);
							VeMenu();
							return;
						}
					}
				}
				if(keyR == 27)
				{
//					saveFile(tree, CountM);
					VeMenu();
					return;
				}
		// hien thi
		 if(posR==0 || posR == 1)
		{
			setcolor(WHITE);
			setfillstyle(SOLID_FILL, NEN_KHUNG);
			if(choice)
			{
				// ID
				setbkcolor(NEN_KHUNG);
				bar(WD_WIDTH/2, ViTriKhung[3]-10, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[1]);
				setbkcolor(HL_MENU_PHU);
				setfillstyle(SOLID_FILL, HL_MENU_PHU);									//do mau nen cho nut
				bar (L+15, ViTriKhung[3]-10,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
				setfillstyle(SOLID_FILL, TEXTBOX);
				bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				Nhap(L+30+2*textwidth(khungNoiDung[0]),ViTriKhung[3],-1,keyR,findID,10);
			}
			else
			{
				// material list
				setbkcolor(NEN_KHUNG);
				bar (L+15, ViTriKhung[3]-10,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
				setfillstyle(SOLID_FILL, TEXTBOX);
				bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				setbkcolor(HL_MENU_PHU);
				setfillstyle(SOLID_FILL, HL_MENU_PHU);
				bar(WD_WIDTH/2, ViTriKhung[3]-10, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[1]);
			}
				setcolor(BLACK);
				setfillstyle(SOLID_FILL, NEN_KHUNG);
				bar (L, D-kichThuocNut, WD_WIDTH/2, D);
				bar (WD_WIDTH/2, D-kichThuocNut, R, D);				
				setbkcolor(NEN_KHUNG);
				line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
				line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
				setcolor(WHITE);
				outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
				outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
		}
		else if(posR==2 || posR==3)
			 {
				setcolor(WHITE);
				setfillstyle(SOLID_FILL, NEN_KHUNG);	
				if(choiceN)
				{	
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setbkcolor(HL_MENU_PHU);
					outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
					setbkcolor(NEN_KHUNG);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
				}
				else	
				{
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setbkcolor(HL_MENU_PHU);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
					setbkcolor(NEN_KHUNG);
					outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
				}
				setcolor(BLACK);
				line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
				line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
			 }		
		}
	} // while
}

void hienThiInfoBill(NODEPTR &tree, char khungNoiDung[][30], int H, int W, char keyword[])
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
	//info
	NODEPTR tmp;
	tmp = Search(tree,keyword);
	infoText(380, ViTriKhung[1], khungNoiDung[1+2],tmp->info.code);
	infoText(380, ViTriKhung[2], khungNoiDung[2+2],tmp->info.name);
	infoText(380, ViTriKhung[3], khungNoiDung[3+2],tmp->info.type);
	// ve khung amount
	bool button = 1;
	int pos = 0;
	char tmpAmount[18];
	tmpAmount[0] = '\0';
	veKhung(380,ViTriKhung[4],khungNoiDung[4+2],1,NEN_KHUNG,WHITE);
	veKhungNut(H, W, khungNoiDung, button, 1,1);
	while(1)
	{
		if(kbhit())
		{
			char key = getch();
			char ckey; 
			if(key == 0)
			{
				ckey = getch();
				switch(ckey)
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
					case KEY_LEFT:
					{
						if(pos==1)
							button ^= 1;
						break;
					}
					case KEY_RIGHT:
					{
						if(pos==1)
							button ^= 1;
						break;
					}
				}
			}
			cpos:
			if(pos==-1)
			{
				button = 1;
				pos = 1;
			}
			else if(pos>1)
					pos = 0;
			if(key == '\r')
			{
			 	if(pos==0)
			 	{
			 		pos++;
			 		goto cpos;
				}
				else
				{
				 	if(button == 1)
				 	{
				 		ThongBao(720, 130, Success[1], GREEN, MAU_MENU);
	//				 		--CountM;
	//				 		tree = deleteNode(tree,tmp->key);
	//						saveFile(tree, CountM);
				 		VeMenu();
				 		return inChoiceBill(tree, choiceObject,1);
					}
					else
					{
						VeMenu();
						return inChoiceBill(tree, choiceObject,1);
	//						return; 
					}
				}
			}
			if(key==27)
			{
			 	VeMenu();
				return inChoiceMat(tree, choiceObject,1);
	//				 	return; 
			}
			// nhap
			if(pos == 0)
			{
				veKhung(380,ViTriKhung[4],khungNoiDung[4+2],1,NEN_KHUNG,WHITE);
				Nhap(560,ViTriKhung[4],0,key,tmpAmount,18);
				veKhungNut(H, W, khungNoiDung, button, 1,1);
			}
			else
			{
				veKhung(380,ViTriKhung[4],khungNoiDung[4+2],0,NEN_KHUNG,WHITE);
				veKhungNut(H, W, khungNoiDung, button, 0,1);				
			}
			InThongTin(560, ViTriKhung[4], tmpAmount);
		}
	}
}
	
void VeKhungChooseBill(NODEPTR &tree, char khungNoiDung[][30], int H, int W, Material tmp)
{
//	Material tmp;
	int cases = 1;
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
	bar (L, U, R, D-10);
			
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
//	setfillstyle(SOLID_FILL, mauNut);
//	bar (L, D-kichThuocNut, R, D-10);
//	setcolor(BLACK);
//	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
//	setbkcolor(NEN_KHUNG);

	
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
	veMuc3Chon(H, W, khungchooseBill, 1, 1,pos);
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
			
			
			for (int i = 1; i <= SoLuongKhung; i++)
			{
				veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, WHITE);
			}
			setbkcolor(NEN_TEXT);
			InThongTin(560, ViTriKhung[1], tmp.code);
			InThongTin(560, ViTriKhung[2], tmp.name);
			InThongTin(560, ViTriKhung[3], tmp.type);
			InThongTin(560, ViTriKhung[4], tmp.amount);
			veMuc3Chon(H, W, khungchooseBill, 1, 1,pos);
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
						int buttonL = 1;
							veMuc3Chon(H, W, khungchooseBill, buttonL, 0,pos);		
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
												veMuc3Chon(H, W,khungchooseBill, buttonL, 1,pos);
												goto cpos;
											}
										case KEY_DOWN:
											{
												pos++;
												veMuc3Chon(H, W, khungchooseBill, buttonL, 1,pos);
												goto cpos;
											}
										case KEY_LEFT:
											{
												buttonL--;
												break;
											}
										case KEY_RIGHT:
											{
												buttonL++;
												break;
											}
									}
								}
								if(buttonL==0)
								{
									buttonL = 3;
								}
								else if(buttonL >3)
									{
										buttonL = 1;
									}
								if (key5 == '\r')
								{
									//return;
									if (buttonL == 1||buttonL == 2)
									{
										//===thong bao loi===//
										if(strlen(tmp.code) != 0 && strlen(tmp.name) != 0 && strlen(tmp.type) != 0 && strlen(tmp.amount) != 0)
										{
//											if(buttonL==1)
												//remove
//											if(buttonL==2)
												//adjust	
										}
										else
										{
											ThongBao(780, 130, Fail[0], LIGHTRED, MAU_MENU);
											goto NotiN;
										}
									}
									else if(buttonL == 3)
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
								veMuc3Chon(H, W, khungchooseBill, buttonL, 0,pos);
							}
						}
					}
			}
		}
	}
}
