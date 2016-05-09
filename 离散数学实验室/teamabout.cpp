#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include"lsmath.h"


extern void gameStart(void);
extern int dealMenu(int);
extern void loginui(void);
extern void gotoxy(int, int);

int teamAbout(void)
{
	int i;
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - 团队信息");

	
	loginui();
	printf("\n\n");
	printf("\t\t\t\t     程序作者\n\n\t\t\t\t      张博强\n\n\t\t\t辽宁工程技术大学 软件学院 15级9班\n\n\t\t\t\t    ");
	//printf("\t\t\t\t     团队信息\n\n\t\t\t    张博强、李昕、范守峰、王妍\n\n\t\t\t辽宁工程技术大学 软件学院 15级9班\n\n\t\t\t\t    ");
	printf("\n\t\t\t\t     指导老师\n\n\t\t\t\t      冯永安\n\n");

	printf("\n\n");
	printf("\n\t本软件在最终发布前对功能进行了测试，确保功能都尽量准确执行，但由\n\t于团队水平和开发经验有限，错误和疏漏在所难免，还望各位不吝赐教。\n");
	printf("\n\t\t\t\t\t\t\t  ");
	printf(DATENOW);
	
	i = 1;
	while (_getch() == ' ')
	{
		i++;
		if (i > 7)
		{
			gameStart();
			break;
		}
	}
	

	return 1000;
	
	
}