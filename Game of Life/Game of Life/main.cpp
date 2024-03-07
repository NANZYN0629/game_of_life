#include "main.h"

int main() {

	//��������
	initgraph(ROW * SIZE, COL * (SIZE + 2));

	//���ƽ���
	map(ROW, COL, SIZE);
	//������ά��������ʾ����״̬
	int life[ROW][COL] = { 0 };
	int count[ROW][COL] = { 0 };

	//����������ӳ�ʱ��
	int sleep_time = 500;
A:
	//�ж�Start״��
	int key = 0;
	ExMessage msg;

	while (1) {

		//��ʼ������,����ѭ��
		if (key == 1)
		{
			key--;
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

			default:
				break;
			}
			
		}
		//�ո�ʼ;
		if (GetAsyncKeyState(VK_SPACE))
		{
			cout << "�ո�����" << endl;
			key++;
			key %= 2;
		}
	}

	while (1)
	{   
		//������
		sleep_time=control(sleep_time);
		if (GetAsyncKeyState(VK_SPACE)) {
			goto A;
		}
		//˫���������˸
		BeginBatchDraw();
		//��������������͵���
		checklife(life, count);
		//ˢ�½���
		cleardevice();
		//���»����µ�����
		againdraw(life);
		// ������������
		EndBatchDraw();
		//�ӳ�ʱ��,�Ա�۲춯̬�ݱ�
		Sleep(sleep_time);

	}
	//�رս���
	closegraph();
	return 0;
}