#include "main.h"

int main() {
	//创建窗口
	initgraph(ROW * SIZE, COL * (SIZE + 2));

	//绘制界面
	map(ROW, COL, SIZE);
	//声明二维数组来表示生命状态
	int life[ROW][COL] = { 0 };
	int count[ROW][COL] = { 0 };
	int back[ROW][COL] = { 0 };

	//设置最初的延迟时间
	int sleep_time = 500;
A:
	//设置开始键
	int key = 0;
	ExMessage msg;

	while (1) {

		//开始键设置,跳出循环
		if (key == 1)
		{
			key--;
			break;
		}
		//空格时,点击s键回到初始界面
		if (GetAsyncKeyState(0x53)) {
			//清空,重新开始
			backwhite(life);
			//刷新界面
			cleardevice();
			againdraw(life);
		}
        //空格时,点击w键回到上一个生命状态
		if (GetAsyncKeyState(0x57)) {
			cleardevice();
			againdraw(back);
		}
		//有鼠标消息返回真，没有返回假
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)//左键设置存活
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 0 && msg.x <= ROW * SIZE && msg.y >= 0 && msg.y <= COL * SIZE)
				{
					cout << "哼哼,被左键点击了" << endl;
					int temp_x = msg.x / SIZE;
					int temp_y = msg.y / SIZE;
					life[temp_x][temp_y] = 1;
					//给存活细胞赋值
					live(temp_x, temp_y, SIZE);

				}

				break;//右键取消
			case WM_RBUTTONDOWN:
				if (msg.x >= 0 && msg.x <= ROW * SIZE && msg.y >= 0 && msg.y <= COL * SIZE)
				{

					cout << "哼哼,被右键点击了" << endl;
					int temp_x = msg.x / SIZE;
					int temp_y = msg.y / SIZE;
					life[temp_x][temp_y] = 0;
					//给死亡细胞赋值
					die(temp_x, temp_y, SIZE);
				}
				break;

			default:
				break;
			}
			
		}
		//空格开始;
		if (GetAsyncKeyState(VK_SPACE))
		{
			cout << "空格键点击" << endl;
			key++;
			key %= 2;
		}
	}

	while (1)
	{   
		//双缓冲减少闪烁
		BeginBatchDraw();
		//记录上一次生命状态
	    backrecord(life,back);
		//检查生命的死亡和诞生
		checklife(life, count);
		//刷新界面
		cleardevice();
		//重新绘制新的生命
		againdraw(life);
		// 结束批量绘制
		EndBatchDraw();
		//延迟时间,以便观察动态演变
		Sleep(sleep_time);
        //鼠标控制
		sleep_time=control(sleep_time);
		if (GetAsyncKeyState(VK_SPACE)) {
			goto A;
		}

	}
	//关闭界面
	closegraph();
	return 0;
}