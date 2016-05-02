#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include"lsmath.h"


extern void gameStart(void);
extern int dealMenu(int);
extern void loginui(void);
extern void gotoxy(int, int);

void teamAbout(void)
{
	int i;
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - 团队信息");

	
	loginui();
	printf("\n\n");
	printf("\t\t\t\t     程序作者\n\n\t\t\t\t      张博强\n\n\t\t\t辽宁工程技术大学 软件学院 15级9班\n\n\t\t\t\t    ");
	printf(DATENOW);
	printf("\n");
	printf("\n\t本软件在最终发布前对功能进行了测试，确保功能都尽量准确执行，但由\n\t于团队水平和开发经验有限，错误和疏漏在所难免，还望各位不吝赐教。");
	gotoxy(0, 2);
	for (i = 0; i<MAXH + 5; i++)
		printf("\n");
	for (i = 0; i < 40; i++)
		printf("━");
	i = 1;
	while (_getch() == ' ')
	{
		i++;
		if (i > 8)
		{
			gameStart();
			CLS;
			loginui();
			dealMenu(1);
		}
	}
	CLS;
	loginui();
	dealMenu(1);
	
}