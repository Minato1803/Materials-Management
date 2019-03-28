#include <iostream>
#include "graphics.h"
#define COLOR(r,g,b) (0x04000000 | RGB(r,g,b))
using namespace std;

int main()
{
	initwindow(100, 100);
	setbkcolor(COLOR(36, 41, 46));
	cleardevice();
	int i = 1;
	while(!kbhit())
	{
		outtextxy(50, 50, "test");
		//setcolor(COLOR(255, 255, 255));
	}
	return 0;
}
