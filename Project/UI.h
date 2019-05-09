#define WD_WIDTH 1024
#define WD_HEIGHT 600
#define MAX_MENU 5
#define DIS_MENUX 20 //khoang cach giua 2 muc menu
#define DIS_MENUY 20

char MenuChinh[MAX_MENU+1][30] = {"Materials", "Employees", "Show", "Statistics", "Help"};
char MenuMater[][30] = {"Add", "Remove", "Adjust"};
char MenuEmp[][30] = {"Add", "Remove", "Adjust"};
char MenuShow[][30] = {"Materials List", "Employees List", "Bills"};
char MenuStat[][30] = {"Bills", "Top Materials"};
char MenuHelp[][30] = {"Dell co gi ca!"};
int ViTriMucMenu[MAX_MENU+1] = {10};
int ViTriMucMenuPhu[5] = {0, 30, 60, 90, 120};
int KichThuocMenuPhu[MAX_MENU+1] = {120, 120, 200, 180, 190};
