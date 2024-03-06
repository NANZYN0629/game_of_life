
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


	initgraph(ROW * SIZE, COL * (SIZE + 2));        //创建窗口


	//绘制界面
	map(ROW, COL, SIZE);

	int life[ROW][COL] = { 0 };       //声明二维数组来表示生命状态
	int count[ROW][COL] = { 0 };


	int key = 0;        //判断Start状况
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



		if (peekmessage(&msg, EM_MOUSE))        //有鼠标消息返回真，没有返回假
		{
			touch(msg, key2, life);
		}
	}



	while (1)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			cout << "上方向键点击" << endl;
			sleep_time -= 100;
			cout << sleep_time << endl;
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			cout << "下方向键点击" << endl;
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
			if (peekmessage(&msg, EM_MOUSE))        //有鼠标消息返回真，没有返回假
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
