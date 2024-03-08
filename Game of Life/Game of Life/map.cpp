#include <iostream>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std;

#include "value.h"

void live(int x, int y, int s)
{
	setfillcolor(WHITE);
	setlinecolor(0);
	fillrectangle(x * s, y * s, (x + 1) * s, (y + 1) * s);
}

void die(int x, int y, int s)
{
	setfillcolor(0);
	setlinecolor(WHITE);
	fillrectangle(x * s, y * s, (x + 1) * s, (y + 1) * s);
}

void live_after(int x, int y, int s)
{
	setfillcolor(GREEN);
	setlinecolor(0);
	fillrectangle(x * s, y * s, (x + 1) * s, (y + 1) * s);
}

void die_befor(int x, int y, int s)
{
	setfillcolor(RED);
	setlinecolor(0);
	fillrectangle(x * s, y * s, (x + 1) * s, (y + 1) * s);
}


void map(int life[ROW][COL])
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			if (life[row][col] == 1)
			{
				live(row, col, SIZE);

			}
			else if (life[row][col] == 0)
			{
				die(row, col, SIZE);

			}
			else if (life[row][col] == 2)
			{
				live_after(row, col, SIZE);
			}
			else if (life[row][col] == 3)
			{
				die_befor(row, col, SIZE);
			}
		}
	}
}