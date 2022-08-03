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
	
	if (list->next == NULL)//����¸��ڵ�Ϊ�յĻ����Ͳ�����preָ���½ڵ���
	{
		node->next = list->next;//��������
		node->pre = list;//ָ���ϸ��ڵ�
		//list
		list->next = node;//�¸��ڵ�ָ���½ڵ�
	}
	else
	{
	//���ڵ㲻�ǿյĻ�listԭ�ȵ��¸��ڵ���Ҫָ���½ڵ��
	//�½��Ľڵ�
		node->next = list->next;
		node->pre = list;
		//ͷ�ڵ���¸��ڵ�
		list->next->pre = node;//ͷ�ڵ�ԭ�ȵ��¸��ڵ�-ִ�����ʱ��Ҫ��ԭ��list�¸��ڵ�ĵ�ַ
		//ͷ�ڵ�
		list->next = node;//list���¸��ڵ�ָ���½ڵ�
	}
}

void taillist(Node* list, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	//�ҵ�list���һ���ڵ�
	while (list->next) list = list->next;
	//�¸��ڵ�Ϊ�յĻ������½ڵ�
	node->pre = list;
	list->next = node;
}

int Delete(Node* list, int data)
{
	Node* delnode = list->next;//����һ��Ҫɾ���Ľڵ�

	while (delnode)
	{
		if (delnode->data == data)//�ҵ���ͬ������
		{
			//delnode���ϸ��ڵ㲻��ָ��dlenode ����ָ��delnode���¸��ڵ�
			delnode->pre->next = delnode->next;//delnode�ڵ��ַ��û��
			if (delnode->next != NULL)
				//��dlenode���¸��ڵ�����
				delnode->next->pre = delnode->pre;//delnode->pre=list->next
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