#include<iostream>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
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



void counter(int life[][COL], int count[][COL])
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
						temp += life[temp_x][temp_y];
					}
				}
			}
			count[row][col] = temp;
		}
	}
}
void cheak(int life[][COL], int count[][COL])
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
void show(int life[][COL], int count[][COL])
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
		}
	}
}
void touch(ExMessage msg,int* key,int life[][COL])
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
			life[temp_x][temp_y] = 1;

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
			life[temp_x][temp_y] = 0;

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