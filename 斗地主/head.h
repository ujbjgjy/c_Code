#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define A 0 //表示自己
#define B 1
#define C 2 //表示地主
#define PEOPEL 3
#define CARDNUM 20 //地主牌数 51/3=17+3

//分牌
void rand_(int* card[CARDNUM], int sum);

//排序
void sort_(int(*card)[CARDNUM]);//-1表示没有地主，0a 1b 2c

//打印
void print(int(*card)[CARDNUM],int landlord);
//landlord:0-a 1-b 2-c -1-没有,

//抢地主
int grab(int(*card)[CARDNUM]);

//玩家出牌
void play_cards(int (*card)[CARDNUM],int n);
