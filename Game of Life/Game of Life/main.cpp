
#include <iostream>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include"ruler.h"
#include <string>
using namespace std;


#define ROW  50
#define COL 50
#define SIZE 15
class bean
{
public:
	int x;
	int y;




};







int main() {


	initgraph(ROW * SIZE, COL * (SIZE + 2));        //��������


	//���ƽ���
	map(ROW, COL, SIZE);

	int life[ROW][COL] = { 0 };       //������ά��������ʾ����״̬
	int count[ROW][COL] = { 0 };


	int key = 0;        //�ж�Start״��
	int *key2 = &key;

	int sleep_time = 500;

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



		if (peekmessage(&msg, EM_MOUSE))        //�������Ϣ�����棬û�з��ؼ�
		{
			touch(msg, key2, life);
		}
	}



	while (1)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			cout << "�Ϸ�������" << endl;
			sleep_time -= 100;
			cout << sleep_time << endl;
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			cout << "�·�������" << endl;
			sleep_time += 100;

			cout << sleep_time << endl;
		}

		if (GetAsyncKeyState(VK_SPACE))
		{
			key = 0;
		}
		counter(life, count);


		cheak(life, count);
		
		while (key==0)
		{
			if (key == 0)
			{
				rectangle(360, 810, 440, 840);
				outtextxy(378, 818, _T("continue"));
			}
			else
			{
				setlinecolor(RED);
				rectangle(360, 810, 440, 840);
				outtextxy(378, 818, _T("continue"));
				break;
			}
			if (peekmessage(&msg, EM_MOUSE))        //�������Ϣ�����棬û�з��ؼ�
			{
				touch(msg, key2, life);

			}
		}
		cleardevice();

		show(life, count);


		Sleep(sleep_time);

	}



	getchar();

	closegraph();
	return 0;


}
