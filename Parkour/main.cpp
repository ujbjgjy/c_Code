#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>

IMAGE img[10];

void menu()
{
	setfillcolor(BLUE);//���ͼ����ɫ
	//����ͼ
	solidrectangle(300,100,500,160);//��ʼ��Ϸ
	solidrectangle(300,180,500,240);//�˳���Ϸ
	solidrectangle(0,550,800,600);//�·�����
	//�������
	char startString[24] = "��ʼ��Ϸ";
	char closeString[24] = "�˳���Ϸ";
	settextcolor(RED);//����������ɫ
	setbkmode(TRANSPARENT);//ȥ�����ֱ���
	settextstyle(48, 0, "΢���ź�");//����������ʽ
	outtextxy(300+25, 100+5, startString);
	outtextxy(300+25, 180+5, closeString);
	//ע
	settextcolor(RGB(60, 60, 60));//����������ɫ
	setbkmode(TRANSPARENT);//ȥ�����ֱ���
	settextstyle(30, 0, "����");//����������ʽ
	outtextxy(250, 300, "���ո���Ծ���¼�������");

	//��꽻��
	while (1)
	{
		MOUSEMSG m;//����һ��������,�洢�����Ϣ
		m = GetMouseMsg();//��ȡ�����Ϣ
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

void Putimagerun()//����
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		cleardevice();//�����Ļ�ϵ���������
		solidrectangle(0, 540, 800, 600);//�·�����

		putimage(50, 385, &img[i]);
		Sleep(80);
	}
}
void Putimageturn()//����
{
	int i = 0;
	for (i = 5; i < 10; i++)
	{
		cleardevice();//�����Ļ�ϵ���������
		solidrectangle(0, 540, 800, 600);//�·�����
		putimage(50, 385, &img[i]);
		Sleep(60);
	}
}

void Putimagejump()//��Ծ
{
	int y = 0;
	for (y = 385; y >= 85; y-=50)
	{
		cleardevice();//�����Ļ�ϵ���������
		solidrectangle(0, 540, 800, 600);//�·�����
		putimage(50, y, &img[0]);
		Sleep(50);
	}//����
	for (y = 85; y >= 385; y += 50)
	{
		cleardevice();//�����Ļ�ϵ���������
		solidrectangle(0, 540, 800, 600);//�·�����
		putimage(50, y, &img[0]);
		Sleep(50);
	}//�½�
}

void button()
{
	if (GetAsyncKeyState(' '))//��ȡ��������������ִ��
	{
		Putimageturn();
	}
	if (GetAsyncKeyState('J'))//��ȡ��������������ִ��
	{
		Putimagejump();
	}
}

int main()
{
	initgraph(800, 600, 0);
	setbkcolor(WHITE);
	cleardevice();

	menu();//�˵�
	Loadimage();//����ͼƬ
	setfillcolor(RGB(0, 180, 255));//���ͼ����ɫ

	while (1)
	{
		Putimagerun();
		button();
	}

	getchar();
	closegraph();
	return 0;
}