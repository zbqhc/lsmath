#include<stdio.h>
#include<Windows.h>
#include"lsmath.h"

extern int DEBUG_MODE;
void loginui(void)
{
	
	int i;
	system("cls");
	printf("  ��ɢ��ѧʵ����\t\t\t\t\t    ");
	printf(VERSION);
	printf("  Build ");
	printf(BUILDNUMBER);
		printf("\n");
	for (i = 0; i < 40; i++)
		printf("��");
	printf("\n");
}