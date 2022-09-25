#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A 0 //表示自己
#define B 1
#define C 2 //表示地主

//分牌
void rand_(int* card[18], int sum);

//排序
void sort_(int(*card)[18]);

//打印
void print(int(*card)[18],int landlord);
//landlord:0-a 1-b 2-c -1-没有,

//抢地主
int grab(int(*card)[18]);

//出牌
void play_cards(int (*card)[18],int n);
