
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
void map(int R, int C, int S);
void live(int x, int y, int s);
void die(int x, int y, int s);
void counter( int life[][COL], int count[][COL]);
void cheak(int life[][COL], int count[][COL]);
void show(int life[][COL], int count[][COL]);
void touch(ExMessage msg, int* key, int life[][COL]);


