#include <iostream>
//#include<stdio.h>
#include <ctype.h>
#include <conio.h>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

#define SIZE_OF_WINDOW 720 //Размер окна

using namespace std;

int main(void)
{
	initwindow(SIZE_OF_WINDOW, SIZE_OF_WINDOW);

	
	while (1)
	{
		float SHIFT = 5;// Коэффициент сдвиг
		float Scaling = 1.015;	// Коэффициент маштабирования
		float Turn = 0.025;	// Угол в радианах на который вращаем
		float xc, yc;	// средний х, y

		//float Xc, Yc;	// средний y


		float x1 = 260, x2 = 460, x3 = 260;
		float y1 = 240, y2 = 240, y3 = 570;

		/*float FIG[3][3] = { {x1, y1, 1}, {x2, y2, 1}, {x3, y3, 1} };

		float FIG[3][3] = { {1, 0, 0}, {0, 1, 0}, {x1, y1, 1} };

		float FIG[1][3] = { {x1, y1, 1} };
		float SDVIG[3][3] = { {1, 0, 0}, {0, 1, 0}, {SHIFT, SHIFT, 1} };*/

		int i, j;
		char BUTTON;

		setcolor(RGB(100, 100, 255));
		line(x1, y1, x2, y2);
		setcolor(RGB(0, 255, 0));
		line(x3, y3, x2, y2);
		setcolor(RGB(255, 200, 0));
		line(x1, y1, x3, y3);
		while (BUTTON = _getch())
		{

			switch (BUTTON)
			{
			//case -32:	// сдвиг
			{
					//BUTTON = _getch();
					//case 72 80 75 77

					//switch (BUTTON) {
			case 'w':	// вверх
				y1 -= 5;
				y2 -= 5;
				y3 -= 5;
				break;

			case 's':	// вниз
				y1 += 5;
				y2 += 5;
				y3 += 5;
				break;

			case 'a':	// влево
				x1 -= 5;
				x2 -= 5;
				x3 -= 5;
				break;

			case 'd':	// вправо
				x1 += 5;
				x2 += 5;
				x3 += 5;
				break;
				//}
				//break;
				}

			// поворот
			{
			case 'q':
				xc = (x1 + x2 + x3) / 3;
				yc = (y1 + y2 + y3) / 3;
				x1 -= xc;
				y1 -= yc;
				x2 -= xc;
				y2 -= yc;
				x3 -= xc;
				y3 -= yc;

				x1 = ((x1 * cos(-Turn)) - (y1 * sin(-Turn))) * 1.0003125;
				y1 = ((x1 * sin(-Turn)) + (y1 * cos(-Turn))) * 1.0003125;
				x2 = ((x2 * cos(-Turn)) - (y2 * sin(-Turn))) * 1.0003125;
				y2 = ((x2 * sin(-Turn)) + (y2 * cos(-Turn))) * 1.0003125;
				x3 = ((x3 * cos(-Turn)) - (y3 * sin(-Turn))) * 1.0003125;
				y3 = ((x3 * sin(-Turn)) + (y3 * cos(-Turn))) * 1.0003125;

				x1 += xc;
				y1 += yc;
				x2 += xc;
				y2 += yc;
				x3 += xc;
				y3 += yc;

				break;

			case 'e':
				xc = (x1 + x2 + x3) / 3;
				yc = (y1 + y2 + y3) / 3;
				x1 -= xc;
				y1 -= yc;
				x2 -= xc;
				y2 -= yc;
				x3 -= xc;
				y3 -= yc;

				x1 = ((x1 * cos(Turn)) - (y1 * sin(Turn))) * 1.0003125;
				y1 = ((x1 * sin(Turn)) + (y1 * cos(Turn))) * 1.0003125;
				x2 = ((x2 * cos(Turn)) - (y2 * sin(Turn))) * 1.0003125;
				y2 = ((x2 * sin(Turn)) + (y2 * cos(Turn))) * 1.0003125;
				x3 = ((x3 * cos(Turn)) - (y3 * sin(Turn))) * 1.0003125;
				y3 = ((x3 * sin(Turn)) + (y3 * cos(Turn))) * 1.0003125;

				x1 += xc;
				y1 += yc;
				x2 += xc;
				y2 += yc;
				x3 += xc;
				y3 += yc;

				break;
			}

			// масштабирование
			{
			case '+':	// увеличение

				xc = (x1 + x2 + x3) / 3;
				yc = (y1 + y2 + y3) / 3;
				x1 -= xc;
				y1 -= yc;
				x2 -= xc;
				y2 -= yc;
				x3 -= xc;
				y3 -= yc;

				//putpixel(xc, yc, RGB(0, 255, 0));

				x1 *= Scaling;
				y1 *= Scaling;
				x2 *= Scaling;
				y2 *= Scaling;
				x3 *= Scaling;
				y3 *= Scaling;

				x1 += xc;
				y1 += yc;
				x2 += xc;
				y2 += yc;
				x3 += xc;
				y3 += yc;

				break;

			case '-':	// масштабирование

				xc = (x1 + x2 + x3) / 3;
				yc = (y1 + y2 + y3) / 3;
				x1 -= xc;
				y1 -= yc;
				x2 -= xc;
				y2 -= yc;
				x3 -= xc;
				y3 -= yc;

				x1 /= Scaling;
				y1 /= Scaling;
				x2 /= Scaling;
				y2 /= Scaling;
				x3 /= Scaling;
				y3 /= Scaling;

				x1 += xc;
				y1 += yc;
				x2 += xc;
				y2 += yc;
				x3 += xc;
				y3 += yc;

				break;
			}
			}

			//FOO(x1, x2, x3, y1, y2, y3);
			
			// закраска
			float Max_x = x1;
			if (Max_x < x2) Max_x = x2;
			if (Max_x < x3) Max_x = x3;

			float Max_y = y1;
			if (Max_y < y2) Max_y = y2;
			if (Max_y < y3) Max_y = y3;

			float Min_x = x1;
			if (Min_x > x2) Min_x = x2;
			if (Min_x > x3) Min_x = x3;

			float Min_y = y1;
			if (Min_y > y2) Min_y = y2;
			if (Min_y > y3) Min_y = y3;

			float Kab;
			float Bab;

			float Kac;
			float Bac;

			float Kbc;
			float Bbc;

			int index = 1;

			if (x1 != x2)
			{
				if ((y1 - y2 < 0 && x1 - x2 > 0) || (y1 - y2 > 0 && x1 - x2 < 0)) index = -1;
				Kab = (abs(y1 - y2) / abs(x1 - x2)) * index;
				Bab = y1 - Kab * x1;
			}

			if (x1 != x3)
			{
				index = 1;
				if ((y1 - y3 < 0 && x1 - x3 > 0) || (y1 - y3 > 0 && x1 - x3 < 0)) index = -1;
				Kac = (abs(y1 - y3) / abs(x1 - x3)) * index;
				Bac = y1 - Kac * x1;
			}

			if (x3 != x2)
			{
				index = 1;
				if ((y3 - y2 < 0 && x3 - x2 > 0) || (y3 - y2 > 0 && x3 - x2 < 0)) index = -1;
				Kbc = (abs(y3 - y2) / abs(x3 - x2)) * index;
				Bbc = y2 - Kbc * x2;
			}

			float X1;
			float X2;
			float y;

			cleardevice();

			for (y = Min_y + 1; y < Max_y; y++)
			{
				if (x1 != x2) X1 = (y - Bab) / Kab;
				else X1 = x1;

				if (X1 < Min_x || X1 > Max_x)
				{
					if (x1 != x3) X1 = (y - Bac) / Kac;
					else X1 = x1;
					if (x3 != x2) X2 = (y - Bbc) / Kbc;
					else X2 = x2;
				}
				else
				{
					if (x1 != x3) X2 = (y - Bac) / Kac;
					else X2 = x1;

					if (X2 < Min_x || X2 > Max_x)
						if (x3 != x2)
							X2 = (y - Bbc) / Kbc;
						else X2 = x2;
				}

				if (y1 == y2)
				{
					X1 = x1;
					X2 = x2;
				}
				if (y1 == y3)
				{
					X1 = x1;
					X2 = x3;
				}
				if (y3 == y2)
				{
					X1 = x3;
					X2 = x2;
				}

				setcolor(RGB(255, 255, 255));
				line(round(X1), round(y), round(X2), round(y));
			}
			

			setcolor(RGB(100, 100, 255));
			line(round(x1), round(y1), round(x2), round(y2));
			setcolor(RGB(0, 255, 0));
			line(round(x3), round(y3), round(x2), round(y2));
			setcolor(RGB(255, 200, 0));
			line(round(x1), round(y1), round(x3), round(y3));
		}
	}
	return 0;
}
