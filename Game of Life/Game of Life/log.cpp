#include "main.h"

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

void backlife(int x, int y, int s)
{
	setfillcolor(GREEN);
	setlinecolor(0);
	fillrectangle(x * s, y * s, (x + 1) * s, (y + 1) * s);
}

void backdie(int x, int y, int s)
{
	setfillcolor(RED);
	setlinecolor(0);
	fillrectangle(x * s, y * s, (x + 1) * s, (y + 1) * s);
}

void checklife(int life[ROW][COL], int count[ROW][COL]) {
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


	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			if (life[row][col] == 1)
			{
				if (count[row][col] > 3 || count[row][col] < 2)
				{
					life[row][col] = -1;

				}else{


				}

			}else
			{
				if (count[row][col] == 3)
				{
					life[row][col] = 2;

				}else{

				}
			}
		}
	}
}

void backrecord(int life[ROW][COL],int back[ROW][COL]) {

	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			back[row][col] = life[row][col];
		}
	}
}
void backwhite(int life[ROW][COL]) {

	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			life[row][col] = 0;
		}
	}
}

void againdraw(int life[ROW][COL]) {
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
			else if (life[row][col] == 2) {

				backlife(row, col, SIZE);
				life[row][col] = 1;
			}
			else if (life[row][col] == -1) {

                backdie(row, col, SIZE);
				life[row][col] = 0;
			}

				
		}
	}
}
int control(int sleep_time) {
	if (GetAsyncKeyState(VK_UP)) {
		cout << "上方向键点击" << endl;
		sleep_time -= 50;
		cout << sleep_time << endl;
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		cout << "下方向键点击" << endl;
		sleep_time += 50;
		cout << sleep_time << endl;
	}
	return sleep_time;
}

