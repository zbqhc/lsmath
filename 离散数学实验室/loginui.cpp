#include<stdio.h>
#include<Windows.h>
#include"lsmath.h"


extern void gotoxy(int, int);
void loginui(void)
{
	
	int i;
	CLS;
	printf("  ��ɢ��ѧʵ����\t\t\t\t\t    ");
	printf(VERSION);
	printf("  Build ");
	printf(BUILDNUMBER);
		printf("\n");
	for (i = 0; i < 40; i++)
		printf("��");

	gotoxy(0, 2);
	printf("\n");
	for (i = 0; i<MAXH + 5; i++)
		printf("\n");
	for (i = 0; i < 40; i++)
		printf("��");
	gotoxy(0, 2);
}