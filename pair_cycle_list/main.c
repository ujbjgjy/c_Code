#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	list->pre = list;
	list->next = list;
	return list;
}

void headinsert(Node* list, Data* data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = *data;

	//如果没有节点，就不必操作pre了
	if (list->next == list)
	{
		//printf("hehe\n");
		//当前还没有节点，插入即是尾节点
		node->pre = list;//指向上个节点 
		node->next = list->next;//接替链表
		
		list->pre = node;//指向尾节点
		list->next = node;//指向新节点
	}
	//有下个节点了可以操作节点的pre指向上个节点了
	else
	{
		node->pre = list;//指向上个节点
		node->next = list->next;//接替链表
		//原先list的下个节点
		list->next->pre = node;
		//list
		list->next = node;
	}
}

void tailinsert(Node* list, Data* data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = *data;
	
	//尾插法要涉及到尾节点的变化，所以头节点要指
	//向新的尾节点，所以要记录头节点
	Node* ptr = list;
	//找到尾节点
	while (ptr->next != list) ptr = ptr->next;
	//要操作头节点，尾节点，尾节点的上个节点
	//node
	node->next = list;//新节点也就尾节点的下个节点指向头节点
	node->pre = ptr;//指向上个节点
	//ptr
	ptr->next = node;
	//list
	list->pre = node;//指向新的尾节点
}

int Delete(Node* list, Data* data)
{
	Node* delnode = list->next;
	while (delnode != list)
	{
		if (strcmp(delnode->data.name, data->name) == 0)
		{
			//要删除节点的上个节点的next指个下下个节点
			delnode->pre->next = delnode->next;
			//要删除节点的下个节点的pre指个上上个节点
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
	Node* ptr = list;
	while ((list = list->next) != ptr)
	{
		printf("%-20s %-5d\n", list->data.name, list->data.age);
	}
}



int main()
{
	Node* list = initlist();
	Data data = { "张三",10 };

	headinsert(list, &data);
	sscanf("熊大 23", "%s%d", data.name, &(data.age));
	headinsert(list, &data);
	sscanf("熊二 13", "%s%d", data.name, &(data.age));
	headinsert(list, &data);

	sscanf("铁锤 33", "%s%d", data.name, &(data.age));
	tailinsert(list, &data);
	sscanf("麻子 53", "%s%d", data.name, &(data.age));
	tailinsert(list, &data);
	sscanf("王二 93", "%s%d", data.name, &(data.age));
	tailinsert(list, &data);

	Delete(list, &data);
	sscanf("铁锤 33", "%s%d", data.name, &(data.age));
	Delete(list, &data);
	sscanf("麻子 33", "%s%d", data.name, &(data.age));
	Delete(list, &data);


	print(list);
	return 0;
}



