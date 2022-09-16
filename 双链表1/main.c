#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
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


void headlist(Node* list, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	
	if (list->next == NULL)//如果下个节点为空的话，就不用让pre指向新节点了
	{
		node->next = list->next;//接替链表
		node->pre = list;//指向上个节点
		//list
		list->next = node;//下个节点指向新节点
	}
	else
	{
	//当节点不是空的话list原先的下个节点是要指向新节点的
	//新建的节点
		node->next = list->next;
		node->pre = list;
		//头节点的下个节点
		list->next->pre = node;//头节点原先的下个节点-执行这个时不要改原先list下个节点的地址
		//头节点
		list->next = node;//list的下个节点指向新节点
	}
}

void taillist(Node* list, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	//找到list最后一个节点
	while (list->next) list = list->next;
	//下个节点为空的话插入新节点
	node->pre = list;
	list->next = node;
}

int Delete(Node* list, int data)
{
	Node* delnode = list->next;//定义一个要删除的节点

	while (delnode)
	{
		if (delnode->data == data)//找到相同的数据
		{
			//delnode的上个节点不再指向dlenode 而是指向delnode的下个节点
			delnode->pre->next = delnode->next;//delnode节点地址还没变
			if (delnode->next != NULL)
				//将dlenode的下个节点连接
				delnode->next->pre = delnode->pre;//delnode->pre=list->next
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
		printf("%d ", list->data);
	}
}

int main()
{
	Node* list = initlist();
	headlist(list, 1);
	headlist(list, 2);
	headlist(list, 3);
	headlist(list, 4);
	headlist(list, 5);

	taillist(list, 6);
	taillist(list, 7);
	taillist(list, 8);
	taillist(list, 9);
	taillist(list, 10);

	Delete(list, 8);
	Delete(list, 1);
	Delete(list, 5);
	Delete(list, 10);
	
	print(list);
	return 0;
}