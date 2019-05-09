//#include "create_structure.h"

//Cac ham ve
void KhoiTaoChuongTrinh();
void TaoManHinhLamViec();
void VeMenu();
void VeMenuPhu(int x, char menu[][30]);
void NoiBatMuc(int x, int y, char menu[][30], int HL_COLOR, int C_SIZE);

// Cac ham Menu
void Menu();
void MenuPhu(int viTriMenuPhu, char menu[][30], int MAXMENU, int &chonMuc);
void ChonMenuPhu(int x);
void Materials();
void Employees();
void Show();
void Statistics();
void Help();
void About();
void Guild();

// Ham Vat Tu
//void AddMat(NODEPTR &cayVatTu);
void VeKhung2(char khungNoiDung[][30], int H, int W, int mucChon, int soLuongKhung);
void veNut2(char khungNoiDung[][30], int ViTriKhung[], int SoLuongKhung, int H, int W, int mauNut, int kichThuocNut, int mucChon);
void veKhung(int x, int y, char noiDung[], bool daChon, int mauNen, int mauChu);
void veMuc2Chon(int x, int y, char noiDung[], char noiDungMucChon[][30], bool chonTrai, int mauNen, int mauChu);

