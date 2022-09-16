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

	//���������
	//1.list������¸��ڵ㲻�ǿ�ָ��Ļ�����Ҫ����preָ���´����Ľڵ�
	//2.list����¸��ڵ��ǿ�ָ��Ļ����Ͳ��ò���preָ���½ڵ���

	if (list->next)//����¸��ڵ㲻Ϊ�յĻ�
	{
		//node
		node->next = list->next;
		node->pre = list;
		//list->next listԭ�ȵ��¸��ڵ�ָ���½ڵ�
		list->next->pre = node;
		//list
		list->next = node;
	}
	else
	{
		node->next = list->next;//��������
		node->pre = list;
		list->next = node;
	}
}

void tailinsert(Node* list, Data* data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = *data;
	node->next = NULL;
	
	//�ҵ��սڵ�
	while (list->next) list = list->next;
	node->pre = list;//nodeָ���ϸ��ڵ�
	list->next = node;//listָ���½ڵ�
}

int  Delete(Node* list, Data* data)
{
	Node* delnode = list->next;

	while (delnode)
	{
		if (strcmp(delnode->data.name, data->name) == 0)
		{
			//�����ϸ��ڵ�ָ�������
			//�����Ͻڵ���¸��ڵ�
			delnode->pre->next = delnode->next;
			//���Ҫɾ���Ľڵ���¸��ڵ㲻Ϊ��ָ��Ļ���preָ��Ҫɾ���ڵ���ϸ��ڵ�
			if (delnode->next != NULL)
				//����Ҫɾ���ڵ���¸��ڵ�
				delnode->next->pre = delnode->pre;
			free(delnode);
			delnode = NULL;
			return 1;
		}
		//�ƶ����¸��ڵ�
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
	Data data = { "����",12 };

	headinsert(list, &data);
	sscanf("�ܴ� 12 ", "%s%d", data.name, &(data.age));
	headinsert(list, &data);
	sscanf("�ܶ� 12 ", "%s%d", data.name, &(data.age));
	headinsert(list, &data);

	sscanf("��ͷǿ 34 ", "%s%d", data.name, &(data.age));
	tailinsert(list, &data);
	sscanf("���� 43 ", "%s%d", data.name, &(data.age));
	tailinsert(list, &data);
	sscanf("���� 12 ", "%s%d", data.name, &(data.age));
	tailinsert(list, &data);

	Delete(list, &data);

	print(list);
	return 0;
}

