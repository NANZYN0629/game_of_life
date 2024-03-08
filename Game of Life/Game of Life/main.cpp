
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

cell cell::cells[ROW][COL];
int main() {
	initgraph(ROW * SIZE, COL * (SIZE + 2));        //创建窗口
	map(ROW, COL, SIZE);
	int key = 0;     
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
			cell::touch(msg, key2);
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
		while (key == 0)
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
				cell::touch(msg, key2);

			}
			if (GetAsyncKeyState(VK_TAB))
			{
						cell::swapb();
						cell::showbefore();
			}

		}
		cell::dosomething( );
		Sleep(sleep_time);
	}
	getchar();

	closegraph();
	return 0;
}
