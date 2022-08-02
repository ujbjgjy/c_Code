#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

Node* initlist()
{
	Node* list = (Node*)calloc(1, sizeof(Node));
	list->next = list;//下个节点指向头节点
	return list;
}

void headinsert(Node* list, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;

	node->next=list->next;
	list->next = node;
}

void tailinsert(Node* list, int data)
{
	Node* ptr = list;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = list;
	while (list->next != ptr) list = list->next;
	list->next = node;
}

void Delete(Node* list, int data)
{
	Node* delnode = list->next;
	while (delnode)
	{
		if (delnode->data == data)
		{
			//如果找到数据
			//list下节点不在指向delnode
			list->next = delnode->next;
			free(delnode);
			delnode = NULL;
			return;
		}
		list = delnode;
		delnode = delnode->next;
	}
}

void printlist(Node* list)
{
	Node* ptr = list;
	while (ptr->next != list)
	{
		ptr = ptr->next;
		printf("%d ", ptr->data);
	}
	printf("\n");
}

int main()
{
	Node* list = initlist();
	headinsert(list, 1);
	headinsert(list, 2);
	headinsert(list, 3);
	headinsert(list, 4);
	headinsert(list, 5);
	tailinsert(list, 6);
	tailinsert(list, 7);
	tailinsert(list, 8);
	tailinsert(list, 9);
	tailinsert(list, 10);

	printlist(list);
	return 0;
}