//#include<stdio.h>
#include<math.h>
#include"acllib.h"
//#include <windows.h>
//#include <olectl.h>
const IID IID_IPicture = {0x7BF80980, 0xBF32, 0x101A, {0x8B, 0xBB, 0x00, 0xAA, 0x00, 0x30, 0x0C, 0xAB}};
//#pragma comment(lib, "Msimg32.lib")
//#pragma comment(lib, "Ole32.lib")
void TimerListener(int id);
void Star(void);
#define starnum 80
#define starspeed 1000//以毫秒为单位
int Setup()//主函数
{
	initWindow("Starry", DEFAULT, DEFAULT, 1000, 600);
	Star();
	registerTimerEvent(TimerListener);
	startTimer(0,starspeed);
	return 0;
}
void TimerListener(int id)//计时器
{

	beginPaint();
	Star();
	int cnt0 = 0;
	if (id == 0)
	{
		cnt0++;
		if (cnt0 == 1000)
		{
			cancelTimer(0);
		}
	}
	endPaint();
}
void Star(void)//繁星点点
{	
	rectangle(0, 0, 1000, 600);//, BLACK);
	static int i = 64641;
	i =i*i;
	srand(i);
	int b;
	double a;
	static int m;
	for (m = 0;m<starnum; m++)
	{
		b = rand();
		//printf("%d\n", b);
		double xa, xb, xc, xd, xe;
		double ya, yb, yc, yd, ye;
		a = b % 35 + 5.0;
		xa = (double)(rand() % 1000) ;
		ya = (double)(rand() % 600) ;
		xb = xa + a * cos(3.1415926 / 5);
		yb = ya - a * sin(3.1415926 / 5);
		xc = xa + a * sin(3 * 3.1415926 / 5) * cos(2 * 3.1415926 / 5) / sin(3.1415926 / 5);
		yc = ya - 2 * a * sin(3 * 3.1415926 / 5) * cos(3.1415926 / 5);
		xd = xa - a * sin(3 * 3.1415926 / 5) * cos(2 * 3.1415926 / 5) / sin(3.1415926 / 5);
		yd = yc;
		xe = xa - a * cos(3.1415926 / 5);
		ye = yb;
		int x, y, z;
		x = rand() % 255;
		y = rand() % 255;
		z = rand() % 255;
		setPenColor(RGB(x, y, z));
		putPixel(xa, ya, RGB(x, y, z));
		putPixel(xb, yb, RGB(x, z, y));
		putPixel(xc, yc, RGB(y, z, x));
		putPixel(xd, yd, RGB(y, x, z));
		putPixel(xe, ye, RGB(x, x, x));
		line(xa, ya, xc, yc);
		line(xa, ya, xd, yd);
		line(xb, yb, xe, ye);
		line(xb, yb, xd, yd);
		line(xc, yc, xe, ye);
	}
}
