#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

//#define MAX 100
#define CURREMT 3//初始化容量

typedef struct Newsletter
{
	char name[12];//名字
	int aeg;//年龄
	char sex[5];//性别
	char phone[12];//电话
	char address[10];//住址
}Newsletter;

typedef struct Newsletter_type
{
	struct Newsletter* deda;
	int current;//当前容量
	int size;//下标位置
}Newsletter_type;

//声明函数
void Initialize(struct Newsletter_type* ps);//初始化
int increase(struct Newsletter_type* ps);//增容
void ADD(struct Newsletter_type* ps);//添加
void Print(const struct Newsletter_type* ps);//显示
void Delete(struct Newsletter_type* ps);//删除
void Check(struct Newsletter_type* ps);//查找
void Change(struct Newsletter_type* ps);//修改
void Sorting(struct Newsletter_type* ps);//排序
void Save(struct Newsletter_type* ps);//保存
void Load(struct Newsletter_type* ps);//加载

int check(const struct Newsletter_type* ps);//查找名字，找到返回相同的下标，找不到返回-1