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
	Data data;//����
	struct Node* pre;//ָ����һ���ڵ�
	struct Node* next;//ָ����һ���ڵ�
}Node;//�ڵ�

Node* initlist()
{
	Node* list = (Node*)calloc(1, sizeof(Node));
	list->pre = NULL;
	list->next = NULL;
	return list;
}//��������

void headinsert(Node* list, Data* data)
{
	//�����ڵ㲢��ֵ
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = *data;
	//����ڵ�
	if (list->next == NULL)//����¸��ڵ㲻����pte�Ļ�
	{
		node->next = list->next;//�½ڵ��������
		node->pre = list;//ָ���ϸ��ڵ�
		//list�������½ڵ�
		list->next = node;
	}
	else
	{
		//node��������
		node->next = list->next;//��������
		node->pre = list;//ָ���ϸ��ڵ�
		//list����node
		list->next->pre = node;//ԭ���Ľڵ��preҲҪ�����½ڵ�
		list->next = node;//list���¸���ָ���½ڵ�
	}
}

void tailinsert(Node* list, Data* data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = *data;
	node->next = NULL;

	while (list->next)list = list->next;//�ҵ��սڵ�
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
			delnode->pre->next = delnode->next;//�ϸ��ڵ�ָ�����¸��ڵ�
			if (delnode->next != NULL)//�¸��ڵ��pte�������ϸ��ڵ�
				delnode->next->pre = delnode->pre;
			free(delnode);
			delnode = NULL;
			return 1;//ɾ���ɹ�
		}
		//�ƶ����¸��ڵ�
		delnode = delnode->next;
	}
	return 0;//δɾ��
}

void print(Node* list)
{
	printf("%-20s %-5s %-5s\n", "����","�Ա�","����");
	while (list = list->next)
	{
		printf("%-20s %-5s %-5d\n", list->data.name, list->data.sex, list->data.age);
	}
}

int main()
{
	Node* list = initlist();
	Data data = { "С��","��",19 };

	headinsert(list, &data);
	sscanf("�ܴ� �� 12","%s%s%d",data.name,data.sex,&(data.age));
	headinsert(list, &data);
	sscanf("��� �� 32", "%s%s%d", data.name, data.sex, &(data.age));
	headinsert(list, &data);
	sscanf("�仨 �� 42", "%s%s%d", data.name, data.sex, &(data.age));
	headinsert(list, &data);
	sscanf("���� �� 432", "%s%s%d", data.name, data.sex, &(data.age));
	headinsert(list, &data);

	sscanf("��ͷǿ �� 43", "%s%s%d", data.name, data.sex, &(data.age));
	tailinsert(list, &data);
	sscanf("���� Ů 35", "%s%s%d", data.name, data.sex, &(data.age));
	tailinsert(list, &data);
	sscanf("���� �� 22", "%s%s%d", data.name, data.sex, &(data.age));
	tailinsert(list, &data);
	sscanf("���� �� 34", "%s%s%d", data.name, data.sex, &(data.age));
	tailinsert(list, &data);
	sscanf("�ܶ� �� 11", "%s%s%d", data.name, data.sex, &(data.age));
	tailinsert(list, &data);

	strcpy(data.name, "�ܴ�");
	Delete(list, &data);
	strcpy(data.name, "����");
	Delete(list, &data);
	strcpy(data.name, "����");
	Delete(list, &data);
	strcpy(data.name, "���");
	Delete(list, &data);

	print(list);
	return 0;
}