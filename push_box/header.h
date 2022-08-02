#pragma once
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define	NUMBER	10	//多少关
#define	LINE	10	//行
#define COLUMN	10	//列

enum en
{
	cle,	//空地
	wall,	//墙
	tar,	//目标
	box,	//箱子
	fig		//人物
};

//函数声明
void Print(const int(*ps)[NUMBER][LINE][COLUMN],int sum);//打印地图
int Operation(int(*ps)[NUMBER][LINE][COLUMN]);//执行游戏操作
//返回-1出错，返回0退出游戏，返回1通关成功
int check(int(*ps)[NUMBER][LINE][COLUMN],int sum);//检查有没有箱子
int Location(const int(*ps)[NUMBER][LINE][COLUMN], int sum,int* x,int* y);//找到人物坐标