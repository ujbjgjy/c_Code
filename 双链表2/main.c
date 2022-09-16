#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Data
{
	char name[20];
	int age;
}Data;

typedef struct Node
{
	Data data;
	struct Node* pre;
	struct Node* next;
}Node;

Node* initlist()
{
	Node* list = (Node*)calloc(1, sizeof(Node));
	list->pre = NULL;
	list->next = NULL;
	return list;
}

void headinsert(Node* list, Data* data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = *data;

	//分两种情况
	//1.list如果是下个节点不是空指针的话，需要操作pre指向新创建的节点
	//2.list如果下个节点是空指针的话，就不用操作pre指向新节点了

	if (list->next)//如果下个节点不为空的话
	{
		//node
		node->next = list->next;
		node->pre = list;
		//list->next list原先的下个节点指向新节点
		list->next->pre = node;
		//list
		list->next = node;
	}
	else
	{
		node->next = list->next;//接替链表
		node->pre = list;
		list->next = node;
	}
}

void tailinsert(Node* list, Data* data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = *data;
	node->next = NULL;
	
	//找到空节点
	while (list->next) list = list->next;
	node->pre = list;//node指向上个节点
	list->next = node;//list指向新节点
}

int  Delete(Node* list, Data* data)
{
	Node* delnode = list->next;

	while (delnode)
	{
		if (strcmp(delnode->data.name, data->name) == 0)
		{
			//接替上个节点指向的链表
			//操作上节点的下个节点
			delnode->pre->next = delnode->next;
			//如果要删除的节点的下个节点不为空指针的话，pre指向要删除节点的上个节点
			if (delnode->next != NULL)
				//操作要删除节点的下个节点
				delnode->next->pre = delnode->pre;
			free(delnode);
			delnode = NULL;
			return 1;
		}
		//移动到下个节点
		delnode = delnode->next;
	}
	return 0;
}

void print(Node* list)
{
	while (list = list->next)
	{
		printf("%-20s %-5d\n", list->data.name, list->data.age);
	}
}

int main()
{
	Node* list = initlist();
	Data data = { "张三",12 };

	headinsert(list, &data);
	sscanf("熊大 12 ", "%s%d", data.name, &(data.age));
	headinsert(list, &data);
	sscanf("熊二 12 ", "%s%d", data.name, &(data.age));
	headinsert(list, &data);

	sscanf("光头强 34 ", "%s%d", data.name, &(data.age));
	tailinsert(list, &data);
	sscanf("铁锤 43 ", "%s%d", data.name, &(data.age));
	tailinsert(list, &data);
	sscanf("王二 12 ", "%s%d", data.name, &(data.age));
	tailinsert(list, &data);

	Delete(list, &data);

	print(list);
	return 0;
}

