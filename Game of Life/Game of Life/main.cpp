
#include <iostream>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std;


#define ROW  50
#define COL 50
#define SIZE 15


void map(int R,int C,int S)
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





int main() {


	initgraph(ROW * SIZE, COL * (SIZE + 2));        //创建窗口


	//绘制界面
	map(ROW, COL, SIZE);

	int life[ROW][COL] = { 0 };       //声明二维数组来表示生命状态
	int count[ROW][COL] = { 0 };


	int key = 0;        //判断Start状况





	ExMessage msg;

	while (1) {

		if (key == 0)
		{
			rectangle(360, 810, 440, 840);
			outtextxy(378, 818, _T("START"));
		}
		else
		{
			setlinecolor(RED);
			rectangle(360, 810, 440, 840);
			outtextxy(378, 818, _T("START"));
			break;
		}



		if (peekmessage(&msg, EM_MOUSE))        //有鼠标消息返回真，没有返回假
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 0 && msg.x <= ROW * SIZE && msg.y >= 0 && msg.y <= COL * SIZE)
				{
					cout << "哼哼,被左键点击了" << endl;
					int temp_x = msg.x / SIZE;
					int temp_y = msg.y / SIZE;
					life[temp_x][temp_y] = 1;

					live(temp_x, temp_y, SIZE);

				}
				else if (msg.x >= 360 && msg.x <= 810 && msg.y >= 440 && msg.y <= 840)
				{
					key += 1;
					key %= 2;
					//cout << key;
				}
				break;
			case WM_RBUTTONDOWN:
				if (msg.x >= 0 && msg.x <= ROW * SIZE && msg.y >= 0 && msg.y <= COL * SIZE)
				{

					cout << "哼哼,被右键点击了" << endl;
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
		}
	}



	while (1)
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



		cleardevice();

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


		Sleep(500);

	}



	getchar();

	closegraph();
	return 0;


}