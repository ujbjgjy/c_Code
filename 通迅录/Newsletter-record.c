#include "header.h"

void Initialize(struct Newsletter_type* ps)
{
	ps->deda = (struct Newsletter*)malloc(CURREMT * sizeof(struct Newsletter));
	ps->size = 0;
	ps->current = CURREMT;
	Load(ps);//加载文件中的通迅录信息
}

void Load(struct Newsletter_type* ps)
{
	Newsletter tmp = { 0 };
	FILE* pf = fopen("Newsletter_file.obj", "rb");
	if (pf == NULL)
	{
		printf("Load:%s\n", strerror(errno));
		return;
	}

	while (fread(&tmp, sizeof(Newsletter), 1, pf))
	{
		increase(ps);//如果空间不够，增容。
		ps->deda[ps->size] = tmp;
		ps->size++;
	}

	fclose(pf);
	pf = NULL;
}

int increase(struct Newsletter_type* ps)
{
	if (ps->size == ps->current)
	{
		Newsletter* ptr = (Newsletter*)realloc(ps->deda, (ps->current + CURREMT) * sizeof(Newsletter));
		if (ptr != NULL)
		{
			ps->deda = ptr;
			ps->current += CURREMT;
			printf("增容\n");
		}
		else
		{
			printf("增容失败\n");
			return -1;
		}
	}
}



void ADD(struct Newsletter_type* ps)
{
	if(increase(ps)== -1) return;

	printf("请输入名字=>");
	scanf("%s", ps->deda[ps->size].name);
	int tmp = check(ps);
	while (tmp != -1)
	{
		printf("名字重复，请重新输入\n");
		printf("请输入名字=>");
		scanf("%s", ps->deda[ps->size].name);
		tmp = check(ps);
	}
	printf("请输入年龄=>");
	scanf("%d", &(ps->deda[ps->size].aeg));
	printf("请输入性别=>");
	scanf("%s", ps->deda[ps->size].sex);
	printf("请输入电话=>");
	scanf("%s", ps->deda[ps->size].phone);
	printf("请输入住址=>");
	scanf("%s", ps->deda[ps->size].address);
	ps->size++;
	system("cls");
	printf("添加成功\n");
}

void Print(const struct Newsletter_type* ps)
{
	if (ps->size == 0)
	{
		printf("通迅录为空\n");
	}
	else
	{
		system("cls");
		printf("%-12s %-5s %-5s %-12s %-10s\n", "名字", "年龄", "性别", "电话", "住址");
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			printf("%-12s %-5d %-5s %-12s %-10s\n", ps->deda[i].name,
													ps->deda[i].aeg,
													ps->deda[i].sex,
													ps->deda[i].phone,
													ps->deda[i].address);
		}
	}
}

int check(const struct Newsletter_type* ps)
{
	if (ps->size == 0) return -1;
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->deda[ps->size].name, ps->deda[i].name))
		{
			return i;
		}
	}
	return -1;
}

void Delete(struct Newsletter_type* ps)
{
	if (ps->size == 0)
	{
		printf("通迅为空\n");
		return;
	}

	printf("请输入你要删除的名字=>");
	scanf("%s", ps->deda[ps->size].name);
	int i=check(ps);
	if (i != -1)
	{
		for (; i < ps->size-1; i++)
		{
			memcpy(&(ps->deda[i]), &(ps->deda[i + 1]), sizeof(ps->deda[0]));
		}
		ps->size--;
		system("cls");
		printf("删除成功\n");
	}
	else
	{
		printf("找不到\n");
	}
}

void Check(struct Newsletter_type* ps)
{
	if (ps->size == 0)
	{
		printf("通迅为空\n");
		return;
	}

	printf("请输入你要查找的名字=>");
	scanf("%s", ps->deda[ps->size].name);
	int i = check(ps);
	if (i != -1)
	{
		system("cls");
		printf("%-12s %-5s %-5s %-12s %-10s\n", "名字", "年龄", "性别", "电话", "住址");
		printf("%-12s %-5d %-5s %-12s %-10s\n", ps->deda[i].name,
												ps->deda[i].aeg,
												ps->deda[i].sex,
												ps->deda[i].phone,
												ps->deda[i].address);
	}
	else
	{
		printf("找不到你要查找的名字\n");
	}
}

void Change(struct Newsletter_type* ps)
{
	if (ps->size == 0)
	{
		printf("通迅为空\n");
		return;
	}

	printf("请输入你要修改的名字=>");
	scanf("%s", ps->deda[ps->size].name);
	int i = check(ps);
	if (i != -1)
	{
		printf("请在次输入名字=>");
		scanf("%s", ps->deda[i].name);
		printf("请在次输入年龄=>");
		scanf("%d", &(ps->deda[i].aeg));
		printf("请在次输入性别=>");
		scanf("%s", ps->deda[i].sex);
		printf("请在次输入电话=>");
		scanf("%s", ps->deda[i].phone);
		printf("请在次输入住址=>");
		scanf("%s", ps->deda[i].address);
		system("cls");
		printf("修改成功\n");
	}
	else
	{
		printf("找不到你要查找的名字\n");
	}
}

void Sorting(struct Newsletter_type* ps)
{
	if (ps->size == 0)
	{
		printf("通迅为空\n");
		return;
	}

	int i = 0,j=0;

	for (i = 0; i < ps->size-1; i++)
	{
		int flag = 1;
		for (j = 0; j < ps->size - 1 - i; j++)
		{
			if (ps->deda[j].aeg > ps->deda[j + 1].aeg)
			{
				Newsletter tmp ={0};
				memcpy(&tmp, &(ps->deda[j + 1]), sizeof(ps->deda[0]));
				memcpy(&(ps->deda[j + 1]), &(ps->deda[j]), sizeof(ps->deda[0]));
				memcpy(&(ps->deda[j]), &tmp, sizeof(ps->deda[0]));
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
	system("cls");
	printf("排序成功\n");
}

void Save(struct Newsletter_type* ps)
{
	FILE* pf = fopen("Newsletter_file.obj", "wb");
	if (pf == NULL)
	{
		printf("Save:%s", strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->deda[i]), sizeof(Newsletter), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}
