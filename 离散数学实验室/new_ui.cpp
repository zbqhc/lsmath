#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
#include<Windows.h>
#include"lsmath.h"



//int pos;
extern void gotoxy(int, int);



int showItem(int x,int y,int w,int select, int quantity, ...)
{
	int i,strl,u;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	va_list item;
	va_start(item, quantity);
	char **stringList;
	stringList = (char **)malloc((quantity+1) * sizeof(char *));
	for (i = 1; i < quantity+1; i++)
	{
		*stringList = (char *)malloc(70 * sizeof(char));
		stringList[i] = va_arg(item, char *);
	}
	va_end(item);
	
	gotoxy(x, y);
	for (i = 0; i<(MAXH-quantity)/2; i++)
		printf("\n");
	
	for (i = 1; i < quantity + 1; i++)
	{
		strl = strlen(stringList[i]);
		for (u = 0; u < (w - strl)/2;u++)
			printf(" ");
		
		if (select == i)
			SetConsoleTextAttribute(hOut,
				BACKGROUND_RED |
				BACKGROUND_GREEN |
				BACKGROUND_BLUE |
				BACKGROUND_INTENSITY);
		printf("%s\n", stringList[i]);
		SetConsoleTextAttribute(hOut,
			FOREGROUND_RED |
			FOREGROUND_GREEN |
			FOREGROUND_BLUE |
			FOREGROUND_INTENSITY);
			printf("\n");
	}
	/*gotoxy(0, 2);
	for (i = 0; i<MAXH+5; i++)
		printf("\n");
	for (i = 0; i < 40; i++)
		printf("��");*/
return 0;

}
int selectItem(int n)
{
	int key, sele = 1, smax = 8;
	int keyMark = 0;
	while (1)
	{
		switch (n)
		{
		case 21:
			smax = 3;
			showItem(0, 5, 75, sele, 3, "���㲢��","���㽻��", "����");
				break;

		case 2:
			smax = 8;
			showItem(0, 2, 75, sele, smax, "��ϵ�Ļ�������", "�ѿ����˻�����", "�жϹ�ϵ�հ�", "��ϵ��������", "�жϵȼ۹�ϵ", "�ж�ƫ���ϵ", "�����ȼ���", "���ϵ����");
			break;
		case 1:
			smax = 4;
			showItem(0, 2, 75, sele, smax, "����ʵ����", "�߼�����", "��������", "�뿪ʵ����");
			break;
		}
		key = _getch();

		

		if (key == 72)
		{
			sele--;
			if (sele == 0)
				sele = smax;
		}
		if (key == 80)
		{
			sele++;
			if (sele == smax + 1)
				sele = 1;
		}
		if (key == 13)
			break;
		if (key == 27)
			return -1;

		if (keyMark)
			return sele;


	}
	return sele;

}

