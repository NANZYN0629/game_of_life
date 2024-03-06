#include "main.h"

int main() {

	//��������
	initgraph(ROW * SIZE, COL * (SIZE + 2));

	//���ƽ���
	map(ROW, COL, SIZE);
	//������ά��������ʾ����״̬
	int life[ROW][COL] = { 0 };
	int count[ROW][COL] = { 0 };

	//�ж�Start״��
	int key = 0;
	//������
	ExMessage msg;

	while (1) {
		//��ʼ������
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

		//�������Ϣ�����棬û�з��ؼ�
		if (peekmessage(&msg, EM_MOUSE))
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

					cout << "�ߺ�,���Ҽ������" << endl;
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
		//��������������͵���
		checklife(life, count);
		//ˢ�½���
		cleardevice();
		//���»����µ�����
		againdraw(life);
		//�ӳ�ʱ��,�Ա�۲춯̬�ݱ�
		Sleep(500);

	}
	//�رս���
	closegraph();
	return 0;
}