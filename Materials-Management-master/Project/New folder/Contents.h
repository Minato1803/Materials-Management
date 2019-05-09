#define WD_WIDTH 1200
#define WD_HEIGHT 700
#define MAX_MENU 5
#define DIS_MENUX 20 //khoang cach giua 2 muc menu
#define DIS_MENUY 20


char MenuChinh[MAX_MENU+1][30] = {"Materials", "Employees", "Show", "Statistics", "Help"};
char MenuMater[][30] = {"Add", "Remove", "Adjust"};
char MenuEmp[][30] = {"Add", "Remove", "Adjust"};
char MenuShow[][30] = {"Materials List", "Employees List", "Bills List"};
char MenuStat[][30] = {"Bills", "Top Materials"};
char MenuHelp[][30] = {"Guild", "About"};

//thong so
int ViTriMucMenu[MAX_MENU+1] = {10};
int ViTriMucMenuPhu[5] = {0, 42, 84, 126, 168};
int ViTriKhung[] = {0, 200, 260, 320, 380};
int KichThuocMenuPhu[MAX_MENU+1] = {120, 120, 200, 180, 120};

//noi dung khung 
char khungMat[][30] = {"Material's Informations", "Add Material", "Exit", "ID", "Name", "Unit", "Amount"};
char khungEmp[][30] = {"Employee's Informations", "Add Employee", "Exit", "ID", "Last Name", "First Name", "Sex"};
char Sex[][30] = {"Male", "Female"};
