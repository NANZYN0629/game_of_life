#pragma once

#include <iostream>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <Windows.h>
//简化命名
using namespace std;

//定义基础量
#define ROW  50
#define COL 50
#define SIZE 15
//自定义函数
void map(int R, int C, int S);
void live(int x, int y, int s);
void die(int x, int y, int s);
void checklife(int life[ROW][COL], int count[ROW][COL]);
void againdraw(int life[ROW][COL]);
int control(int s);
void click(int life[ROW][COL]);
void backrecord(int life[ROW][COL], int back[ROW][COL]);
void backdraw(int life[ROW][COL], int back[ROW][COL]);
void backwhite(int life[ROW][COL], int back[ROW][COL]);