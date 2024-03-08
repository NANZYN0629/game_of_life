
#include <iostream>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;

#include "value.h"
#include "map.h"
#include "check.h"








int main() {


	initgraph(ROW * SIZE, (COL + 2) * SIZE);        //��������


	

	//���ƽ���
	//map(ROW, COL, SIZE);

A:

	int life[ROW][COL] = { 0 };       //������ά��������ʾ����״̬
	int count[ROW][COL] = { 0 };


	int key = 0;        //�ж�Start״��
	int temp_map[ROW][COL];
	int sleep_time = 500;
	
	int step = 0;

	


	ExMessage msg;

	while (1)
	{
		BeginBatchDraw();
		
		settextcolor(WHITE);
		outtextxy(770, 50, step);
		
		cout << step;
		

		temp_map[ROW][COL] = life[ROW][COL];
		

		if (key == 1)
		{
			step++;

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
			step++;

			key = 0;
			check(life, count);
			cleardevice();
			map(life);
			Sleep(200);
		}
		else if (key == 3)
		{
			key = 0;
			check(temp_map, count);
			cleardevice();
			map(temp_map);
			Sleep(200);
		}





		if (peekmessage(&msg, EM_MOUSE))        //�������Ϣ�����棬û�з��ؼ�
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 0 && msg.x <= ROW * SIZE && msg.y >= 0 && msg.y <= COL * SIZE)
				{
					cout << "�ߺ�,����������" << endl;
					int temp_x = msg.x / SIZE;
					int temp_y = msg.y / SIZE;
					life[temp_x][temp_y] = 1;
				}
				break;
			
			case WM_RBUTTONDOWN:
				if (msg.x >= 0 && msg.x <= ROW * SIZE && msg.y >= 0 && msg.y <= COL * SIZE)
				{

					cout << "�ߺ�,���Ҽ������" << endl;
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
			cout << "�ո�����" << endl;
			key++;
			key %= 2;
		}

		if (GetAsyncKeyState(VK_UP))
		{
			cout << "�Ϸ�������" << endl;
			sleep_time -= 100;
			if (sleep_time <= 0)
			{
				sleep_time = 0;
			}
			cout << sleep_time << endl;
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			cout << "�·�������" << endl;
			sleep_time += 100;

			cout << sleep_time << endl;
		}

		if (GetAsyncKeyState(VK_RIGHT))
		{
			key = 2;
		}

		if (GetAsyncKeyState(VK_LEFT))
		{
			key = 3;
		}

		if (GetAsyncKeyState(VK_F9))
		{
			goto A;
		}

		

		EndBatchDraw();
	}




	getchar();

	closegraph();
	return 0;


}