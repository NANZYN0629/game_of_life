
#include <iostream>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;

#include "map.h"
#include "check.h"








int main() {


	initgraph(ROW * SIZE, COL * SIZE);        //��������




	//���ƽ���
	//map(ROW, COL, SIZE);

A:

	int life[ROW][COL] = { 0 };       //������ά��������ʾ����״̬
	int count[ROW][COL] = { 0 };


	int key = 0;        //�ж�Start״��
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
			if (sleep_time <= 100)
			{
				sleep_time = 100;
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
			cout << "�ҷ�������" << endl;
			sleep_time += 100;
			key = 2;
		}

		if (GetAsyncKeyState(VK_LEFT))
		{
			cout << "��������" << endl;
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