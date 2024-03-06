#include "main.h"

int main() {

	//创建窗口
	initgraph(ROW * SIZE, COL * (SIZE + 2));

	//绘制界面
	map(ROW, COL, SIZE);
	//声明二维数组来表示生命状态
	int life[ROW][COL] = { 0 };
	int count[ROW][COL] = { 0 };

	//判断Start状况
	int key = 0;
	//鼠标控制
	ExMessage msg;

	while (1) {
		//开始键设置
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

		//有鼠标消息返回真，没有返回假
		if (peekmessage(&msg, EM_MOUSE))
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
		//检查生命的死亡和诞生
		checklife(life, count);
		//刷新界面
		cleardevice();
		//重新绘制新的生命
		againdraw(life);
		//延迟时间,以便观察动态演变
		Sleep(500);

	}
	//关闭界面
	closegraph();
	return 0;
}