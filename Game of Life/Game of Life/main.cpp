#include "main.h"

int main() {
	//��������
	initgraph(ROW * SIZE, COL * (SIZE + 2));

	//���ƽ���
	map(ROW, COL, SIZE);
	//������ά��������ʾ����״̬
	int life[ROW][COL] = { 0 };
	int count[ROW][COL] = { 0 };
	int back[ROW][COL] = { 0 };

	//����������ӳ�ʱ��
	int sleep_time = 500;
A:
	//���ÿ�ʼ��
	int key = 0;
	ExMessage msg;

	while (1) {

		//��ʼ������,����ѭ��
		if (key == 1)
		{
			key--;
			break;
		}
		//�ո�ʱ,���s���ص���ʼ����
		if (GetAsyncKeyState(0x53)) {
			//���,���¿�ʼ
			backwhite(life);
			//ˢ�½���
			cleardevice();
			againdraw(life);
		}
        //�ո�ʱ,���w���ص���һ������״̬
		if (GetAsyncKeyState(0x57)) {
			cleardevice();
			againdraw(back);
		}
		//�������Ϣ�����棬û�з��ؼ�
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)//������ô��
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 0 && msg.x <= ROW * SIZE && msg.y >= 0 && msg.y <= COL * SIZE)
				{
					cout << "�ߺ�,����������" << endl;
					int temp_x = msg.x / SIZE;
					int temp_y = msg.y / SIZE;
					life[temp_x][temp_y] = 1;
					//�����ϸ����ֵ
					live(temp_x, temp_y, SIZE);

				}

				break;//�Ҽ�ȡ��
			case WM_RBUTTONDOWN:
				if (msg.x >= 0 && msg.x <= ROW * SIZE && msg.y >= 0 && msg.y <= COL * SIZE)
				{

					cout << "�ߺ�,���Ҽ������" << endl;
					int temp_x = msg.x / SIZE;
					int temp_y = msg.y / SIZE;
					life[temp_x][temp_y] = 0;
					//������ϸ����ֵ
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
		//˫���������˸
		BeginBatchDraw();
		//��¼��һ������״̬
	    backrecord(life,back);
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
        //������
		sleep_time=control(sleep_time);
		if (GetAsyncKeyState(VK_SPACE)) {
			goto A;
		}

	}
	//�رս���
	closegraph();
	return 0;
}