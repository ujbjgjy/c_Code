#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
	char name[20];
	char sxt[5];
	int age;
}Data;//数据

typedef struct Node
{
	Data data;//数据
	struct Node* next;//指向下一个节点
}Node;//节点

Node* initlist()
{
	Node* list = (Node*)calloc(1, sizeof(Node));
	//list->next = NULL;//下个节点为空
	return list;
}//创建链表

void headinsert(Node* list, Data* data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = *data;//传来的数据进行赋值
	node->next = list->next;//可以理解为由node接管list指向的链表
	list->next = node;//list再来指向node
}

void tailinsert(Node* list, Data* data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = *data;

	//找到头节点的尾部也就是空指针
	Node* ptr = list;//不可乱移动头节点
	while (ptr->next)
		ptr=ptr->next;//ptr的下一个节点为空

	node->next = NULL;//node作为尾节点的下个节点为空
	ptr->next = node;//头节点尾部连接上新节点;
	ptr = NULL;
}

void Delete(Node* list, Data* data)
{
	//找到相同和数据，如果不相同就移动到下个节点
	Node* ptr = list;//头节点
	Node* curr = list->next;//头节点的下个节点也就要删除的节点

	while (curr)
	{
		if (strcmp(curr->data.name, data->name) == 0)
		{
			ptr->next = curr->next;//移出curr
			free(curr);
			ptr = NULL;
			curr = NULL;
			break;
		}
		//如果不相同移动节点
		ptr = curr;//ptr移动到下个节点
		curr = curr->next;//curr移动到下个节点
	}
}

void printlist(Node* list)
{
	printf("%-20s %-5s %-5s\n", "名字", "性别", "年龄");
	while (list = list->next)
	{
		printf("%-20s %-5s %-5d\n", list->data.name, list->data.sxt, list->data.age);
	}
}

void printmenu()
{
	printf("********************\n");
	printf("*   1:headinsetr   *\n");
	printf("*   2:tailinsetr   *\n");
	printf("*   3:deletelist   *\n");
	printf("*   4:printlist    *\n");
	printf("*   0:exit         *\n");
	printf("********************\n");
}

int main()
{
	Node* list=initlist();
	Data data = { 0 };
	
	while (1)
	{
		printmenu();
		printf("选择=>");
		int input = 0;
		scanf("%d", &input);
		if (input == 1)
		{
			printf("名字=>");
			scanf("%s", data.name);
			printf("性别=>");
			scanf("%s", data.sxt);
			printf("年龄=>");
			scanf("%d", &(data.age));
			headinsert(list, &data);
			system("cls");
		}
		else if (input == 2)
		{
			printf("名字=>");
			scanf("%s", data.name);
			printf("性别=>");
			scanf("%s", data.sxt);
			printf("年龄=>");
			scanf("%d", &(data.age));
			tailinsert(list, &data);;
			system("cls");
		}
		else if (input == 3)
		{
			printf("要删除的名字=>");
			scanf("%s", data.name);
			Delete(list, &data);
			system("cls");
		}
		else if (input == 4)
		{
			system("cls");
			printlist(list);
		}
		else if (input == 0)
		{
			return 0;
		}
		else
		{
			printf("输入错误\n");
			system("cls");
		}
	}

	return 0;
}