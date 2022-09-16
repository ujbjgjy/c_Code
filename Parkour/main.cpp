#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>

IMAGE img[10];

void menu()
{
	setfillcolor(BLUE);//填充图形颜色
	//画矩图
	solidrectangle(300,100,500,160);//开始游戏
	solidrectangle(300,180,500,240);//退出游戏
	solidrectangle(0,550,800,600);//下方长条
	//输出文字
	char startString[24] = "开始游戏";
	char closeString[24] = "退出游戏";
	settextcolor(RED);//设置文字颜色
	setbkmode(TRANSPARENT);//去掉文字背景
	settextstyle(48, 0, "微软雅黑");//设置字体样式
	outtextxy(300+25, 100+5, startString);
	outtextxy(300+25, 180+5, closeString);
	//注
	settextcolor(RGB(60, 60, 60));//设置文字颜色
	setbkmode(TRANSPARENT);//去掉文字背景
	settextstyle(30, 0, "黑体");//设置字体样式
	outtextxy(250, 300, "按空格跳跃，下键翻滚。");

	//鼠标交互
	while (1)
	{
		MOUSEMSG m;//定义一个鼠标变量,存储鼠标消息
		m = GetMouseMsg();//获取鼠标消息
		if ((m.x >= 300 && m.x >= 100) && (m.y <= 500 && m.y <= 180))
		{
			setlinecolor(RED);
			rectangle(300-5, 100-5, 500+5, 160+5);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				break;
			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(300 - 5, 100 - 5, 500 + 5, 160 + 5);
		}
		if ((m.x >= 300 && m.y >= 180) && (m.x <= 500 && m.y <= 240))
		{
			setlinecolor(RED);
			rectangle(300 - 5, 180 - 5, 500 + 5, 240 + 5);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				exit(0);
			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(300 - 5, 180 - 5, 500 + 5, 240 + 5);
		}
	}

}

void Loadimage()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		char arr[24];
		sprintf(arr,"matches\\img(%d).png", i);
		loadimage(img+i, arr, 150, 150);
	}
}

void Putimagerun()//奔跑
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		cleardevice();//清空屏幕上的所有内容
		solidrectangle(0, 540, 800, 600);//下方长条

		putimage(50, 385, &img[i]);
		Sleep(80);
	}
}
void Putimageturn()//翻滚
{
	int i = 0;
	for (i = 5; i < 10; i++)
	{
		cleardevice();//清空屏幕上的所有内容
		solidrectangle(0, 540, 800, 600);//下方长条
		putimage(50, 385, &img[i]);
		Sleep(60);
	}
}

void Putimagejump()//跳跃
{
	int y = 0;
	for (y = 385; y >= 85; y-=50)
	{
		cleardevice();//清空屏幕上的所有内容
		solidrectangle(0, 540, 800, 600);//下方长条
		putimage(50, y, &img[0]);
		Sleep(50);
	}//上升
	for (y = 85; y >= 385; y += 50)
	{
		cleardevice();//清空屏幕上的所有内容
		solidrectangle(0, 540, 800, 600);//下方长条
		putimage(50, y, &img[0]);
		Sleep(50);
	}//下降
}

void button()
{
	if (GetAsyncKeyState(' '))//获取按键，程序正常执行
	{
		Putimageturn();
	}
	if (GetAsyncKeyState('J'))//获取按键，程序正常执行
	{
		Putimagejump();
	}
}

int main()
{
	initgraph(800, 600, 0);
	setbkcolor(WHITE);
	cleardevice();

	menu();//菜单
	Loadimage();//加载图片
	setfillcolor(RGB(0, 180, 255));//填充图形颜色

	while (1)
	{
		Putimagerun();
		button();
	}

	getchar();
	closegraph();
	return 0;
}