
#include<iostream>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
#define ROW  50
#define COL 50
#define SIZE 15

using namespace std;
class cell
{
public:
	static cell cells[ROW][COL];

	int count;
	bool life;
	bool lifebefore;
	//声明二维数组来表示生命状态


	static void cellcheak();
	static void cellshow();
	static void showbefore();
	static void swapn();
	static void swapb();
	static void touch(ExMessage msg, int* key);
	static void counter();
	static void dosomething();
};
void map(int R, int C, int S);
void live(int x, int y, int s);
void die(int x, int y, int s);
/*
void counter( cell cells[][COL]);
void cheak(bool life[][COL], int count[][COL]);
void show(bool life[][COL], bool count[][COL]);
void showbefore(bool life[][COL]);
void swap(bool life[][COL], bool lifebefore[][COL]);

*/