#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A 0 //��ʾ�Լ�
#define B 1
#define C 2 //��ʾ����

//����
void rand_(int* card[18], int sum);

//����
void sort_(int(*card)[18]);

//��ӡ
void print(int(*card)[18],int landlord);
//landlord:0-a 1-b 2-c -1-û��,

//������
int grab(int(*card)[18]);

//����
void play_cards(int (*card)[8],int n);