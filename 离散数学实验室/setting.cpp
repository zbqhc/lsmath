#include<stdio.h>
#include<conio.h>
extern void loginui(void);
int setting(void)
{
	loginui();
	printf("������");
	_getch();
	return 1000;
}