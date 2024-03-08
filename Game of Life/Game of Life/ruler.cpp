#include<iostream>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include "ruler.h"
using namespace std;
#define ROW  50
#define COL 50
#define SIZE 15

void map(int R, int C, int S)
{
	for (int row = 0; row <= R; row++)
	{
		for (int col = 0; col <= R; col++)
		{
			line(0, row * S, R * S, row * S);
			line(col * S, 0, col * S, C * S);
		}
	}
}
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




void cell::touch(ExMessage msg, int* key)
{
	int key2 = *key;
	switch (msg.message)
	{
	case WM_LBUTTONDOWN:
		if (msg.x >= 0 && msg.x <= ROW * SIZE && msg.y >= 0 && msg.y <= COL * SIZE)
		{
			cout << "ºßºß,±»×ó¼üµã»÷ÁË" << endl;
			int temp_x = msg.x / SIZE;
			int temp_y = msg.y / SIZE;
			cells[temp_x][temp_y].life = true;

			live(temp_x, temp_y, SIZE);

		}
		else if (msg.x >= 360 && msg.x <= 810 && msg.y >= 440 && msg.y <= 840)
		{
			key2 += 1;
			key2 %= 2;
			//cout << key;
		}
		break;
	case WM_RBUTTONDOWN:
		if (msg.x >= 0 && msg.x <= ROW * SIZE && msg.y >= 0 && msg.y <= COL * SIZE)
		{

			cout << "ºßºß,±»ÓÒ¼üµã»÷ÁË" << endl;
			int temp_x = msg.x / SIZE;
			int temp_y = msg.y / SIZE;
			cells[temp_x][temp_y].life = 0;

			die(temp_x, temp_y, SIZE);
		}
		break;

		if (msg.x >= 360 && msg.x <= 810 && msg.y >= 440 && msg.y <= 840)
		{
			setlinecolor(WHITE);
			fillrectangle(360, 810, 440, 840);
		}
	default:
		break;
	}
	*key = key2;
}

void cell::counter()
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			int temp = 0;

			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					if (i == 0 && j == 0)	continue;

					int temp_x = row + i;
					int temp_y = col + j;

					if (temp_x >= 0 && temp_x <= ROW && temp_y >= 0 && temp_y <= COL)
					{
						temp += cells[temp_x][temp_y].life;
					}
				}
			}
			cells[row][col].count = temp;
		}
	}
}
void cell::cellcheak()
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			if (cells[row][col].life)
			{
				if (cells[row][col].count > 3 || cells[row][col].count < 2)
				{
					cells[row][col].life = false;
				}

			}
			else
			{
				if (cells[row][col].count == 3)
				{
					cells[row][col].life = true;
				}
			}

		}
	}
	

}
void cell::cellshow()
{

	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			if (cells[row][col].life == 0)
			{
				die(row, col, SIZE);

			}
			if (cells[row][col].life ^ cells[row][col].lifebefore)
			{

				setfillcolor(RED);
				setlinecolor(0);
				fillrectangle(row * SIZE, col * SIZE, (row + 1) * SIZE, (col + 1) * SIZE);

			}
			if (cells[row][col].life == 1)
			{
				live(row, col, SIZE);

			}
			if (cells[row][col].lifebefore == 0 && cells[row][col].life == 1)
			{

				setfillcolor(BLUE);
				setlinecolor(0);
				fillrectangle(row * SIZE, col * SIZE, (row + 1) * SIZE, (col + 1) * SIZE);

			}

		}
	}

	


}
void cell::showbefore()
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			if (cells[row][col].life == 0)
			{
				die(row, col, SIZE);

			}

			if (cells[row][col].life == 1)
			{
				live(row, col, SIZE);

			}
		}
	}

	
}
void cell::swapn()
{

	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			cells[row][col].lifebefore = cells[row][col].life;
		}
	}

}
void cell::swapb()
{

	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			cells[row][col].life = cells[row][col].lifebefore;
		}
	}


}
void cell::dosomething()
{
	
		cell::swapn();
		cell::counter();
		cell::cellcheak();
		cleardevice();
		cell::cellshow();
		
	
}
/*
void swap(bool life[][COL], bool lifebefore[][COL])
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			lifebefore[row][col] = life[row][col];


		}
	}
}

void cheak(bool life[][COL], int count[][COL])
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			if (life[row][col] == 1)
			{
				if (count[row][col] > 3 || count[row][col] < 2)
				{
					life[row][col] = 0;
				}

			}
			else
			{
				if (count[row][col] == 3)
				{
					life[row][col] = 1;
				}
			}
		}
	}
}
void show(bool life[][COL], bool lifebefore[][COL])
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{


			if (life[row][col] == 0)
			{
				die(row, col, SIZE);

			}
			if (life[row][col] ^ lifebefore[row][col])
			{

				setfillcolor(RED);
				setlinecolor(0);
				fillrectangle(row * SIZE, col * SIZE, (row + 1) * SIZE, (col + 1) * SIZE);

			}
			if (life[row][col] == 1)
			{
				live(row, col, SIZE);

			}
			if (lifebefore[row][col] == 0 && life[row][col] == 1)
			{

				setfillcolor(BLUE);
				setlinecolor(0);
				fillrectangle(row * SIZE, col * SIZE, (row + 1) * SIZE, (col + 1) * SIZE);

			}

		}
	}
}
void showbefore(bool life[][COL])
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{


			if (life[row][col] == 0)
			{
				die(row, col, SIZE);

			}

			if (life[row][col] == 1)
			{
				live(row, col, SIZE);

			}


		}
	}
}
*/