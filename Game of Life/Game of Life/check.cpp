#include <iostream>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std;

#include "value.h"



void num_check(int life[ROW][COL], int count[ROW][COL])
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

void live_check(int life[ROW][COL], int count[ROW][COL])
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			if (life[row][col] == 1)
			{
				if (count[row][col] > 3 || count[row][col] < 2)
				{
					life[row][col] = -1;
				}

			}
			else
			{
				if (count[row][col] == 3)
				{
					life[row][col] = 2;
				}
			}
		}
	}
}

void check(int life[ROW][COL], int count[ROW][COL])
{
	num_check(life, count);
	live_check(life, count);
}