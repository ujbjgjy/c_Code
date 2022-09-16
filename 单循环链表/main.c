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
	struct Node* next;
}Node;

Node* initlist()
{
	Node* list = (Node*)calloc(1, sizeof(Node));
	list->next =list;
	return list;
}

void headinsert(Node* list, Data* data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = *data;

	node->next = list->next;
	list->next = node;
}

void tailinsert(Node* list, Data* data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = *data;
	node->next = list;

	Node* ptr = list;
	while (ptr->next != list) ptr = ptr->next;
	ptr->next = node;
}

int Delete(Node* list, Data* data)
{
	Node* delnode = list->next;
	while (delnode)
	{
		if (strcmp(delnode->data.name, data->name) == 0)
		{
			list->next = delnode->next;
			free(delnode);
			delnode = NULL;
			return 1;
		}
		list = delnode;
		delnode = delnode->next;
	}
	return 0;

}//����1��ʾ��ɾ����0δɾ��

void print(Node* list)
{
	Node* ptr = list->next;
	printf("%-20s %-5s\n", "����", "����");
	while (ptr != list)
	{
		printf("%-20s %-5d\n", ptr->data.name, ptr->data.age);
		ptr = ptr->next;
	}
}

int main()
{
	Node* list = initlist();
	Data data = { "���",45 };
	headinsert(list, &data);
	sscanf("���� 19", "%s %d", data.name, &(data.age));
	headinsert(list, &data);
	sscanf("�ܶ� 13", "%s %d", data.name, &(data.age));
	headinsert(list, &data);
	sscanf("�ܴ� 19", "%s %d", data.name, &(data.age));
	headinsert(list, &data);
	sscanf("���� 100", "%s %d", data.name, &(data.age));
	tailinsert(list, &data);
	sscanf("��Ԫ� 35", "%s %d", data.name, &(data.age));
	tailinsert(list, &data);
	sscanf("������ 34", "%s %d", data.name, &(data.age));
	tailinsert(list, &data);


	print(list, &data);
	return 0;
}