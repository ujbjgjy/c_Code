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

}//返回1表示已删除，0未删除

void print(Node* list)
{
	Node* ptr = list->next;
	printf("%-20s %-5s\n", "名字", "年龄");
	while (ptr != list)
	{
		printf("%-20s %-5d\n", ptr->data.name, ptr->data.age);
		ptr = ptr->next;
	}
}

int main()
{
	Node* list = initlist();
	Data data = { "李白",45 };
	headinsert(list, &data);
	sscanf("张三 19", "%s %d", data.name, &(data.age));
	headinsert(list, &data);
	sscanf("熊二 13", "%s %d", data.name, &(data.age));
	headinsert(list, &data);
	sscanf("熊大 19", "%s %d", data.name, &(data.age));
	headinsert(list, &data);
	sscanf("李四 100", "%s %d", data.name, &(data.age));
	tailinsert(list, &data);
	sscanf("朱元璋 35", "%s %d", data.name, &(data.age));
	tailinsert(list, &data);
	sscanf("汉高祖 34", "%s %d", data.name, &(data.age));
	tailinsert(list, &data);


	print(list, &data);
	return 0;
}