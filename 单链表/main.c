#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
	char name[20];
	char sxt[5];
	int age;
}Data;//����

typedef struct Node
{
	Data data;//����
	struct Node* next;//ָ����һ���ڵ�
}Node;//�ڵ�

Node* initlist()
{
	Node* list = (Node*)calloc(1, sizeof(Node));
	//list->next = NULL;//�¸��ڵ�Ϊ��
	return list;
}//��������

void headinsert(Node* list, Data* data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = *data;//���������ݽ��и�ֵ
	node->next = list->next;//�������Ϊ��node�ӹ�listָ�������
	list->next = node;//list����ָ��node
}

void tailinsert(Node* list, Data* data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = *data;

	//�ҵ�ͷ�ڵ��β��Ҳ���ǿ�ָ��
	Node* ptr = list;//�������ƶ�ͷ�ڵ�
	while (ptr->next)
		ptr=ptr->next;//ptr����һ���ڵ�Ϊ��

	node->next = NULL;//node��Ϊβ�ڵ���¸��ڵ�Ϊ��
	ptr->next = node;//ͷ�ڵ�β���������½ڵ�;
	ptr = NULL;
}

void Delete(Node* list, Data* data)
{
	//�ҵ���ͬ�����ݣ��������ͬ���ƶ����¸��ڵ�
	Node* ptr = list;//ͷ�ڵ�
	Node* curr = list->next;//ͷ�ڵ���¸��ڵ�Ҳ��Ҫɾ���Ľڵ�

	while (curr)
	{
		if (strcmp(curr->data.name, data->name) == 0)
		{
			ptr->next = curr->next;//�Ƴ�curr
			free(curr);
			ptr = NULL;
			curr = NULL;
			break;
		}
		//�������ͬ�ƶ��ڵ�
		ptr = curr;//ptr�ƶ����¸��ڵ�
		curr = curr->next;//curr�ƶ����¸��ڵ�
	}
}

void printlist(Node* list)
{
	printf("%-20s %-5s %-5s\n", "����", "�Ա�", "����");
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
		printf("ѡ��=>");
		int input = 0;
		scanf("%d", &input);
		if (input == 1)
		{
			printf("����=>");
			scanf("%s", data.name);
			printf("�Ա�=>");
			scanf("%s", data.sxt);
			printf("����=>");
			scanf("%d", &(data.age));
			headinsert(list, &data);
			system("cls");
		}
		else if (input == 2)
		{
			printf("����=>");
			scanf("%s", data.name);
			printf("�Ա�=>");
			scanf("%s", data.sxt);
			printf("����=>");
			scanf("%d", &(data.age));
			tailinsert(list, &data);;
			system("cls");
		}
		else if (input == 3)
		{
			printf("Ҫɾ��������=>");
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
			printf("�������\n");
			system("cls");
		}
	}

	return 0;
}