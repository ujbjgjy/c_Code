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

	//���û�нڵ㣬�Ͳ��ز���pre��
	if (list->next == list)
	{
		//printf("hehe\n");
		//��ǰ��û�нڵ㣬���뼴��β�ڵ�
		node->pre = list;//ָ���ϸ��ڵ� 
		node->next = list->next;//��������
		
		list->pre = node;//ָ��β�ڵ�
		list->next = node;//ָ���½ڵ�
	}
	//���¸��ڵ��˿��Բ����ڵ��preָ���ϸ��ڵ���
	else
	{
		node->pre = list;//ָ���ϸ��ڵ�
		node->next = list->next;//��������
		//ԭ��list���¸��ڵ�
		list->next->pre = node;
		//list
		list->next = node;
	}
}

void tailinsert(Node* list, Data* data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = *data;
	
	//β�巨Ҫ�漰��β�ڵ�ı仯������ͷ�ڵ�Ҫָ
	//���µ�β�ڵ㣬����Ҫ��¼ͷ�ڵ�
	Node* ptr = list;
	//�ҵ�β�ڵ�
	while (ptr->next != list) ptr = ptr->next;
	//Ҫ����ͷ�ڵ㣬β�ڵ㣬β�ڵ���ϸ��ڵ�
	//node
	node->next = list;//�½ڵ�Ҳ��β�ڵ���¸��ڵ�ָ��ͷ�ڵ�
	node->pre = ptr;//ָ���ϸ��ڵ�
	//ptr
	ptr->next = node;
	//list
	list->pre = node;//ָ���µ�β�ڵ�
}

int Delete(Node* list, Data* data)
{
	Node* delnode = list->next;
	while (delnode != list)
	{
		if (strcmp(delnode->data.name, data->name) == 0)
		{
			//Ҫɾ���ڵ���ϸ��ڵ��nextָ�����¸��ڵ�
			delnode->pre->next = delnode->next;
			//Ҫɾ���ڵ���¸��ڵ��preָ�����ϸ��ڵ�
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
	Node* ptr = list;
	while ((list = list->next) != ptr)
	{
		printf("%-20s %-5d\n", list->data.name, list->data.age);
	}
}



int main()
{
	Node* list = initlist();
	Data data = { "����",10 };

	headinsert(list, &data);
	sscanf("�ܴ� 23", "%s%d", data.name, &(data.age));
	headinsert(list, &data);
	sscanf("�ܶ� 13", "%s%d", data.name, &(data.age));
	headinsert(list, &data);

	sscanf("���� 33", "%s%d", data.name, &(data.age));
	tailinsert(list, &data);
	sscanf("���� 53", "%s%d", data.name, &(data.age));
	tailinsert(list, &data);
	sscanf("���� 93", "%s%d", data.name, &(data.age));
	tailinsert(list, &data);

	Delete(list, &data);
	sscanf("���� 33", "%s%d", data.name, &(data.age));
	Delete(list, &data);
	sscanf("���� 33", "%s%d", data.name, &(data.age));
	Delete(list, &data);


	print(list);
	return 0;
}



