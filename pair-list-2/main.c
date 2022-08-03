#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
	char name[20];
	char sex[5];
	int age;
}Data;

typedef struct Node
{
	Data data;//数据
	struct Node* pre;//指向上一个节点
	struct Node* next;//指向下一个节点
}Node;//节点

Node* initlist()
{
	Node* list = (Node*)calloc(1, sizeof(Node));
	list->pre = NULL;
	list->next = NULL;
	return list;
}//创建链表

void headinsert(Node* list, Data* data)
{
	//创建节点并赋值
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = *data;
	//插入节点
	if (list->next == NULL)//如果下个节点不包含pte的话
	{
		node->next = list->next;//新节点接替链表
		node->pre = list;//指向上个节点
		//list再连接新节点
		list->next = node;
	}
	else
	{
		//node连接链表
		node->next = list->next;//接替链表
		node->pre = list;//指向上个节点
		//list连接node
		list->next->pre = node;//原来的节点的pre也要链接新节点
		list->next = node;//list的下个节指向新节点
	}
}

void tailinsert(Node* list, Data* data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = *data;
	node->next = NULL;

	while (list->next)list = list->next;//找到空节点
	list->next = node;
	node->pre = list;
}

void Delete(Node* list, Data* data)
{
	Node* delnode = list->next;
	while (delnode)
	{
		if (strcmp(delnode->data.name, data->name) == 0)
		{
			delnode->pre->next = delnode->next;//上个节点指向下下个节点
			if (delnode->next != NULL)//下个节点的pte连接上上个节点
				delnode->next->pre = delnode->pre;
			free(delnode);
			delnode = NULL;
			return 1;//删除成功
		}
		//移动到下个节点
		delnode = delnode->next;
	}
	return 0;//未删除
}

void print(Node* list)
{
	printf("%-20s %-5s %-5s\n", "名字","性别","年龄");
	while (list = list->next)
	{
		printf("%-20s %-5s %-5d\n", list->data.name, list->data.sex, list->data.age);
	}
}

int main()
{
	Node* list = initlist();
	Data data = { "小花","男",19 };

	headinsert(list, &data);
	sscanf("熊大 男 12","%s%s%d",data.name,data.sex,&(data.age));
	headinsert(list, &data);
	sscanf("李白 男 32", "%s%s%d", data.name, data.sex, &(data.age));
	headinsert(list, &data);
	sscanf("翠花 男 42", "%s%s%d", data.name, data.sex, &(data.age));
	headinsert(list, &data);
	sscanf("麻子 男 432", "%s%s%d", data.name, data.sex, &(data.age));
	headinsert(list, &data);

	sscanf("光头强 男 43", "%s%s%d", data.name, data.sex, &(data.age));
	tailinsert(list, &data);
	sscanf("铁锤 女 35", "%s%s%d", data.name, data.sex, &(data.age));
	tailinsert(list, &data);
	sscanf("王二 男 22", "%s%s%d", data.name, data.sex, &(data.age));
	tailinsert(list, &data);
	sscanf("张三 男 34", "%s%s%d", data.name, data.sex, &(data.age));
	tailinsert(list, &data);
	sscanf("熊二 男 11", "%s%s%d", data.name, data.sex, &(data.age));
	tailinsert(list, &data);

	strcpy(data.name, "熊大");
	Delete(list, &data);
	strcpy(data.name, "王二");
	Delete(list, &data);
	strcpy(data.name, "麻子");
	Delete(list, &data);
	strcpy(data.name, "李白");
	Delete(list, &data);

	print(list);
	return 0;
}