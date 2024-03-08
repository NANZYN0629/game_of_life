
#include <iostream>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;

#include "map.h"
#include "check.h"








int main() {


	initgraph(ROW * SIZE, COL * SIZE);        //创建窗口




	//绘制界面
	//map(ROW, COL, SIZE);

A:

	int life[ROW][COL] = { 0 };       //声明二维数组来表示生命状态
	int count[ROW][COL] = { 0 };


	int key = 0;        //判断Start状况
	int temp_map[ROW][COL];
	int sleep_time = 500;

	ExMessage msg;

	while (1)
	{
		BeginBatchDraw();


		if (key == 1)
		{
			check(life, count);
			cleardevice();
			map(life);
			Sleep(sleep_time);

		}
		else if (key == 0)
		{
			cleardevice();
			map(life);
		}
		else if (key == 2)
		{
			key = 0;
			check(life, count);
			cleardevice();
			map(life);
			Sleep(200);
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
				}
				break;

			case WM_RBUTTONDOWN:
				if (msg.x >= 0 && msg.x <= ROW * SIZE && msg.y >= 0 && msg.y <= COL * SIZE)
				{

					cout << "哼哼,被右键点击了" << endl;
					int temp_x = msg.x / SIZE;
					int temp_y = msg.y / SIZE;
					life[temp_x][temp_y] = 0;
				}
				break;

			default:
				break;
			}
		}


		if (GetAsyncKeyState(VK_SPACE))
		{
			cout << "空格键点击" << endl;
			key++;
			key %= 2;
		}

		if (GetAsyncKeyState(VK_UP))
		{
			cout << "上方向键点击" << endl;
			sleep_time -= 100;
			if (sleep_time <= 100)
			{
				sleep_time = 100;
			}
			cout << sleep_time << endl;
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			cout << "下方向键点击" << endl;
			sleep_time += 100;

			cout << sleep_time << endl;
		}

		if (GetAsyncKeyState(VK_RIGHT))
		{
			cout << "右方向键点击" << endl;
			sleep_time += 100;
			key = 2;
		}

		if (GetAsyncKeyState(VK_LEFT))
		{
			cout << "左方向键点击" << endl;
			sleep_time += 100;
			map(temp_map);
		}

		if (GetAsyncKeyState(VK_F9))
		{
			goto A;
		}



		
		for (int row = 0; row <= ROW; row++)
		{
			for (int col = 0; row <= COL; col++)
			{
				temp_map[row][col] = life[row][col];
			}
		}

		EndBatchDraw();
	}




	getchar();

	closegraph();
	return 0;


}