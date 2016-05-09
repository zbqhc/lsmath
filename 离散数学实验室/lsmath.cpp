#include"lsmath.h"
#include<conio.h>
#include<stdio.h>
#include<Windows.h>


extern void loginui(void);
extern int inputdata(int[], int);
extern int outputdata(int[], int, int);
extern int produceRandNumber(int, int, int);

extern void gotoxy(int x, int y);
extern int lsmath(int[], int, int[], int,int);
extern int gxfh(int a[], int ai, int b[], int bi, int obj[]);
extern int inversion(int [],int [],int);
extern int msgbox(char title[], char text[], int x, int y, int W, int H, int mode, int counter, ...);
extern int equalclassNew(int arr[], int quantity, int n, int meo[100][100]);


int base(int a[], int ai, int b[], int bi, int obj[], int mode);
int dker(int[], int, int[], int,int [], int);
int autoInput(int mode, int arr[],int flag,int mark);


int lsbaseWindows(void)
{
	int i, quantity, flag = 1, flag2,mark;
	int obj[200] = { 0 };
	int a[100] = { 0 }, quantity_A;
	int b[100] = { 0 }, quantity_B;
	int save = 1;
	CLS;
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - 关系的基本运算");
	loginui();

	mark = autoInput(2, a,1,0);
	quantity_A = mark;
	if (mark == -1)
		printf("\n\n打开文件失败\n");
	if (mark)
		mark = autoInput(2, b, 0, 0);
	loginui();
	quantity_B = mark;
	if (mark == -1)
		printf("\n\n打开文件失败\n");
	if (mark < 1)
	{

		printf("请输入第一组关系：\n");




		quantity_A = inputdata(a, 2);
		if (quantity_A == -1)
		{
			loginui();
			return 11;
		}
		else if (quantity_A == -3)
		{
			loginui();
			return 111;
		}

		printf("\n\n请输入第二组关系：\n");
		
		quantity_B = inputdata(b, 2);
		if (quantity_B == -1)
		{
			loginui();
			return 11;
		}
	}
	loginui();
	while (flag)
	{
		if (save)
		{
			printf("第一组关系为：\n\t");
			for (i = 0; i < 2 * quantity_A; i += 2)
			{


				printf("<%d,%d>\t", a[i], a[i + 1]);
				if (i % 14 == 0 && i > 8)
					printf("\n\t");
			}
			if (quantity_A == 0)
				printf("\t[空集]");

			printf("\n\n第二组关系为：\n\t");
			for (i = 0; i < 2 * quantity_B; i += 2)
			{

				printf("<%d,%d>\t", b[i], b[i + 1]);
				if (i % 14 == 0 && i > 8)
					printf("\n\t");
			}
			if (quantity_B == 0)
				printf("\t[空集]");
			printf("\n\n\n\n运算结果：\n\t");

			quantity = base(a, quantity_A, b, quantity_B, obj, 1);
			printf("\n并集：\n\t");
			if (quantity == 0)
				printf("[空集]");
			for (i = 0; i < 2 * quantity; i += 2)
			{
				printf("<%d,%d>\t", obj[i], obj[i + 1]);
				if (i % 14 == 0 && i > 4)
					printf("\n\t");
			}


			quantity = base(a, quantity_A, b, quantity_B, obj, 2);
			printf("\n\n交集：\n\t");
			if (quantity == -20)
				printf("[空集]");
			for (i = 0; i < 2 * quantity; i += 2)
			{
				printf("<%d,%d>\t", obj[i], obj[i + 1]);
				if (i % 14 == 0 && i > 4)
					printf("\n\t");
			}


			quantity = base(a, quantity_A, b, quantity_B, obj, 3);
			printf("\n\n差集：\n\t");
			if (quantity == -20)
				printf("[空集]");
			for (i = 0; i < 2 * quantity; i += 2)
			{
				printf("<%d,%d>\t", obj[i], obj[i + 1]);
				if (i % 14 == 0 && i > 4)
					printf("\n\t");
			}
		}
		else
		{
			FILE *fp;
			fp = fopen("关系的基本运算.txt", "a+");
			fprintf(fp,"第一组关系为：\n\t");
			for (i = 0; i < 2 * quantity_A; i += 2)
			{


				fprintf(fp,"<%d,%d>\t", a[i], a[i + 1]);
				if (i % 14 == 0 && i > 8)
					fprintf(fp,"\n");
			}
			if (quantity_A == 0)
				fprintf(fp,"\t[空集]");

			fprintf(fp,"\n\n第二组关系为：\n\t");
			for (i = 0; i < 2 * quantity_B; i += 2)
			{

				fprintf(fp,"<%d,%d>\t", b[i], b[i + 1]);
				if (i % 14 == 0 && i > 8)
					fprintf(fp,"\n");
			}
			if (quantity_B == 0)
				fprintf(fp,"\t[空集]");
			fprintf(fp,"\n\n\n\n运算结果：\n");

			quantity = base(a, quantity_A, b, quantity_B, obj, 1);
			fprintf(fp,"\n并集：\n\t");
			if (quantity == 0)
				fprintf(fp,"[空集]");
			for (i = 0; i < 2 * quantity; i += 2)
			{
				fprintf(fp,"<%d,%d>\t", obj[i], obj[i + 1]);
				if (i % 14 == 0 && i > 4)
					fprintf(fp,"\n\t");
			}


			quantity = base(a, quantity_A, b, quantity_B, obj, 2);
			fprintf(fp,"\n\n交集：\n\t");
			if (quantity == -20)
				fprintf(fp,"[空集]");
			for (i = 0; i < 2 * quantity; i += 2)
			{
				fprintf(fp,"<%d,%d>\t", obj[i], obj[i + 1]);
				if (i % 14 == 0 && i > 4)
					fprintf(fp,"\n\t");
			}


			quantity = base(a, quantity_A, b, quantity_B, obj, 3);
			fprintf(fp,"\n\n差集：\n\t");
			if (quantity == -20)
				fprintf(fp,"[空集]");
			for (i = 0; i < 2 * quantity; i += 2)
			{
				fprintf(fp,"<%d,%d>\t", obj[i], obj[i + 1]);
				if (i % 14 == 0 && i > 4)
					fprintf(fp,"\n\t");
			}
			fprintf(fp,"\n\n===========================================================================\n\n");
			fclose(fp);
		}
		save = 1;
		flag = 0;
		gotoxy(0, MAXH+7);
		printf("计算完毕 按r重新计算 按esc返回上一级菜单 按s保存结果");

		i = 0;
		while (quantity = _getch())
		{
			if (quantity == 13)
				i++;
			if (quantity == 13 && i == 2)
			{
				gotoxy(0, MAXH+7);
				printf("计算完毕 按r重新计算 按esc返回上一级菜单  你按回车键干嘛");
			}
			if (quantity == 13 && i == 3)
			{
				gotoxy(0, MAXH+7);
				printf("计算完毕 按r重新计算 按esc返回上一级菜单  而且还按了三次");
			}
			if (quantity == 13 && i >= 5)
			{
				gotoxy(0, MAXH+7);
				printf("计算完毕 按r重新计算 按esc返回上一级菜单  好吧按回车键也可以退出");
				_getch();
				loginui();
				flag2 = 11;
				break;
			}
			if (quantity == 27)
			{
				loginui();
				flag2 = 11;
				break;
			}
			if (quantity == 114)
			{
				flag2 = 111;
				loginui();
				break;
			}
			if (quantity == 115)
			{
				printf("  保存成功！");
				flag = 1;
				save = 0;
				break;
			}

		}
	}


	return flag2;
}

int dkerWindows(void)
{
	CLS;
	int i,flag=1,mark,flag2=1,save=1,quantity_C;
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - 笛卡尔乘积运算");
	loginui();

	int a[20] = { 0 }, b[20] = { 0 }, obj[400] = { 0 }, quantity_A, quantity_B;

	mark = autoInput(1, a, 1,0);
	quantity_A = mark;
	if (mark == -1)
		printf("\n\n打开文件失败\n");
	if (mark)
		mark = autoInput(1, b, 0, 0);
	loginui();
	quantity_B = mark;
	if (mark == -1)
		printf("\n\n打开文件失败\n");
	if (mark < 1)
	{
		while (flag)
		{
			printf("请输入第一组集合数据：\n");
			quantity_A = inputdata(a, 1);
			if (quantity_A == -1)
			{
				loginui();
				return 11;
			}
			if (quantity_A == 0)
			{
				msgbox("出错了呢", "未检测到有效数据，请再输入一遍", 5, 5, 50, 8, 0, 1);
				loginui();
			}
			else
				flag = 0;
		}
		flag = 1;
		while (flag)
		{
			printf("\n\n请输入第二组集合数据：\n");
			quantity_B = inputdata(b, 1);
			if (quantity_B == -1)
			{
				loginui();
				return 11;
			}
			if (quantity_B == 0)
			{
				msgbox("出错了呢", "未检测到有效数据，请再输入一遍", 5, 5, 50, 8, 0, 1);
				loginui();
			}
			else
				flag = 0;


		}
	}
	flag = 1;
	
			loginui();
			gotoxy(0, 2);
			printf("第一组集合为：\n\n\t{");
			for (i = 0; i < quantity_A; i++)
			{
				printf("%d, ", a[i]);
				if (i % 20 == 0 && i > 4)
					printf("\n");
			}
			printf("\b\b}\n\n");

			printf("第二组集合为：\n\n\t{");
			for (i = 0; i < quantity_B; i++)
			{
				printf("%d, ", b[i]);
				if (i % 20 == 0 && i > 8)
					printf("\n");
			}
			printf("\b\b}\n\n\n笛卡尔乘积运算结果：\n\n\t");
			quantity_C = dker(a, quantity_A, b, quantity_B, obj, 0);

			for (i = 0; i < 2 * quantity_C; i += 2)
			{
				printf("<%d,%d>\t", obj[i], obj[i + 1]);
				if (i % 16 == 0 && i > 8)
					printf("\n\t");
			}
			gotoxy(0, MAXH + 7);
			printf("按任意键返回 按s保存数据");
			if (_getch() == 115)
			{
				FILE *fp;
				fp = fopen("笛卡尔乘积运算.txt","a+" );
				fprintf(fp,"第一组集合为：\n\n\t{");
				for (i = 0; i < quantity_A; i++)
				{
					fprintf(fp,"%d, ", a[i]);
					if (i % 20 == 0 && i > 4)
						fprintf(fp,"\n");
				}
				fprintf(fp,"}\n\n");

				fprintf(fp,"第二组集合为：\n\n\t{");
				for (i = 0; i < quantity_B; i++)
				{
					fprintf(fp,"%d, ", b[i]);
					if (i % 20 == 0 && i > 8)
						fprintf(fp,"\n");
				}
				fprintf(fp,"}\n\n\n笛卡尔乘积运算结果：\n\n\t");
				quantity_C = dker(a, quantity_A, b, quantity_B, obj, 0);

				for (i = 0; i < 2 * quantity_C; i += 2)
				{
					fprintf(fp, "<%d,%d>\t", obj[i], obj[i + 1]);
					if (i % 16 == 0 && i > 8)
						fprintf(fp, "\n\t");
				}
					fprintf(fp, "\n\n===========================================================================\n\n");
				
				fclose(fp);
				
				printf("  保存成功！");
				_getch();
			}
		
	loginui();
	return 11;
}

int gxbbWindows(void)
{
	int i, flag = 1, flag3 = 1, flag4 = 0,mark,debug_mode_run=0,keyp;
	int count_zf, count_dc, count_cd, overall;
	int obj[200] = { 0 };
	int ans = 0;
	int a[50] = { 0 }, quantity_A;
	int b[100] = { 0 }, quantity_B;
	CLS;
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - 分析关系闭包");
	loginui();

 	mark = autoInput(1, a, 1,1);
	if (mark)
	{
		quantity_A = mark;
		if (mark == -1)
			printf("\n\n打开文件失败\n");

		mark = autoInput(2, b, 0, 1);
		quantity_B = mark;
		if (mark == -1)
			printf("\n\n打开文件失败\n");
	}
	if (mark < 1)
	{
		loginui();
		while (flag3)
		{
			printf("请输入集合元素：\n");

			quantity_A = inputdata(a, 1);
			if (quantity_A == -1)
			{
				loginui();
				return 11;
			}
			if (quantity_A == 0)
			{
				msgbox("出错了呢", "未检测到有效数据，请再输入一遍", 5, 5, 50, 8, 0, 1); \
					loginui();
			}
			else
				flag3 = 0;
		}
		flag3 = 1;

		printf("\n\n");
		printf("请输入关系数据：\n");
		quantity_B = inputdata(b, 2);
		if (quantity_B == -1)
		{
			loginui();
			return 11;
		}
	}
	flag3 = 0;
	mark = 0;
	do
	{
		gotoxy(0, 2);
		loginui();
		printf("集合数据为：\n\t{");
		for (i = 0; i < quantity_A; i++)
		{
			printf("%d, ", a[i]);
			if (i % 14 == 0 && i > 4)
				printf("\n");
		}
		printf("\b\b}\n\n");
		printf("关系数据为：\n\t");
		for (i = 0; i < 2 * quantity_B; i += 2)
		{
			printf("<%d,%d>\t", b[i], b[i + 1]);
			if (i % 14 == 0 && i > 8)
				printf("\n");
			flag4 = 1;
		}
		if (!flag4)
			printf("[关系数据为空]");

		ans = lsmath(a, quantity_A, b, quantity_B,debug_mode_run);
		overall = ans % 100;
		count_zf = (ans - ans % 1000000) / 1000000;
		count_dc = (ans - count_zf * 1000000 - ans % 10000) / 10000;
		count_cd = (ans - count_zf * 1000000 - count_dc * 10000 - ans % 100) / 100;


		//printf("\n%d\t%d\t%d\t%d\t%d", ans,count_zf,count_dc,count_cd,overall);
		if (overall > 0 && flag4 != 0)
			printf("\n\n该关系满足");
		//else
			//printf("\n\n该关系不满足自反、对称、传递\n");
		if (flag4)
		{
			switch (overall)
			{
			case 1:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("传递");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("性质\n");
				break;
			case 2:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("对称");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("性质\n");
				break;
			case 3:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("对称");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("、");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("传递");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("性质");
				break;
			case 4:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("自反");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("性质\n");
				break;
			case 5:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("自反");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("、");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("传递");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("性质");
				break;
			case 6:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("自反");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("、");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("对称");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("性质");
				break;
			case 7:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("自反");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("、");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("对称");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("、");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("传递");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("性质");
				break;
			case 10:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("反自反");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("性质\n");
				break;
			case 11:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("反自反");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("、");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("传递");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("性质");
				break;
			case 12:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("反自反");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("、");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("对称");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("性质");
				break;
			case 13:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("反自反");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("、");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("对称");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("、");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("传递");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("性质");
				break;
			case 30:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("反自反");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("、");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("反对称");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("性质");
				break;
			case 31:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("反自反");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("、");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("反对称");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("、");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("传递");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("性质");
				break;
			case 20:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("反对称");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("性质\n");
				break;
			case 21:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("反对称");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("、");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("传递");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("性质");
				break;
			case 24:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("自反");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("、");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("反对称");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("性质");
				break;
			case 25:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("自反");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("、");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("反对称");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("、");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
				printf("传递");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				printf("性质");
				break;
			default:
				break;
			}
			printf("\n\n自反闭包：%d\t对称闭包：%d\t传递闭包：%d", count_zf, count_dc, count_cd);
		}
		else
			printf("\n无法计算关系闭包");
			gotoxy(0, MAXH + 7);
			printf("按F12显示关系矩阵 按s保存计算结果 按其他键返回上一级菜单");
			keyp = _getch();

		if (keyp == 224)
			if (_getch() == 134)
			{
				flag3 = 1;
				mark++;
				debug_mode_run = mark % 2;
			}
			else
			{
				flag3 = 0;
				debug_mode_run = 0;
			}
		else if (keyp == 115)
		{
			FILE *fp;
			fp = fopen("判断关系闭包.txt", "a+");
			fprintf(fp,"集合数据为：\n\t{");
			for (i = 0; i < quantity_A; i++)
			{
				fprintf(fp,"%d, ", a[i]);
				if (i % 14 == 0 && i > 4)
					fprintf(fp,"\n");
			}
			fprintf(fp,"}\n\n");
			fprintf(fp,"关系数据为：\n\t");
			for (i = 0; i < 2 * quantity_B; i += 2)
			{
				fprintf(fp,"<%d,%d>\t", b[i], b[i + 1]);
				if (i % 14 == 0 && i > 8)
					fprintf(fp,"\n");
				flag4 = 1;
			}
			if (!flag4)
				fprintf(fp,"[关系数据为空]");

			ans = lsmath(a, quantity_A, b, quantity_B, debug_mode_run);
			overall = ans % 100;
			count_zf = (ans - ans % 1000000) / 1000000;
			count_dc = (ans - count_zf * 1000000 - ans % 10000) / 10000;
			count_cd = (ans - count_zf * 1000000 - count_dc * 10000 - ans % 100) / 100;


			if (overall > 0 && flag4 != 0)
				fprintf(fp,"\n\n该关系满足");
			if (flag4)
			{
				switch (overall)
				{
				case 1:
					fprintf(fp,"传递");
					fprintf(fp,"性质\n");
					break;
				case 2:
					fprintf(fp,"对称");
					fprintf(fp,"性质\n");
					break;
				case 3:
					fprintf(fp,"对称");
					fprintf(fp,"、");
					fprintf(fp,"传递");
					fprintf(fp,"性质");
					break;
				case 4:
					fprintf(fp,"自反");
					fprintf(fp,"性质\n");
					break;
				case 5:
					fprintf(fp,"自反");
					fprintf(fp,"、");
					fprintf(fp,"传递");
					fprintf(fp,"性质");
					break;
				case 6:
					fprintf(fp,"自反");
					fprintf(fp,"、");
					fprintf(fp,"对称");
					fprintf(fp,"性质");
					break;
				case 7:
					fprintf(fp,"自反");
					fprintf(fp,"、");
					fprintf(fp,"对称");
					fprintf(fp,"、");
					fprintf(fp,"传递");
					fprintf(fp,"性质");
					break;
				case 10:
					fprintf(fp,"反自反");
					fprintf(fp,"性质\n");
					break;
				case 11:
					fprintf(fp,"反自反");
					fprintf(fp,"、");
					fprintf(fp,"传递");
					fprintf(fp,"性质");
					break;
				case 12:
					fprintf(fp,"反自反");
					fprintf(fp,"、");
					fprintf(fp,"对称");
					fprintf(fp,"性质");
					break;
				case 13:
					fprintf(fp,"反自反");
					fprintf(fp,"、");
					fprintf(fp,"对称");
					fprintf(fp,"、");
					fprintf(fp,"传递");
					fprintf(fp,"性质");
					break;
				case 30:
					fprintf(fp,"反自反");
					fprintf(fp,"、");
					fprintf(fp,"反对称");
					fprintf(fp,"性质");
					break;
				case 31:
					fprintf(fp,"反自反");
					fprintf(fp,"、");
					fprintf(fp,"反对称");
					fprintf(fp,"、");
					fprintf(fp,"传递");
					fprintf(fp,"性质");
					break;
				case 20:
					fprintf(fp,"反对称");
					fprintf(fp,"性质\n");
					break;
				case 21:
					fprintf(fp,"反对称");
					fprintf(fp,"、");
					fprintf(fp,"传递");
					fprintf(fp,"性质");
					break;
				case 24:
					fprintf(fp,"自反");
					fprintf(fp,"、");
					fprintf(fp,"反对称");
					fprintf(fp,"性质");
					break;
				case 25:
					fprintf(fp,"自反");
					fprintf(fp,"、");
					fprintf(fp,"反对称");
					fprintf(fp,"、");
					fprintf(fp,"传递");
					fprintf(fp,"性质");
					break;
				default:
					break;
				}
				fprintf(fp,"\n\n自反闭包：%d\t对称闭包：%d\t传递闭包：%d", count_zf, count_dc, count_cd);
			}
			else
			{
				fprintf(fp, "\n无法计算关系闭包");
			}

			fprintf(fp, "\n\n===========================================================================\n\n");
			printf("  保存成功");
			_getch();
			flag3 = 1;
			fclose(fp);
		}
		else
		{
			flag3 = 0;
		}
	}while (flag3);


	loginui();
	return 11;
}


int complexWindows(void)
{
	int  obj[100] = { 0 },quantity,flag3=1,mark;
	int a[100] = { 0 }, quantity_A;
	int b[100] = { 0 }, quantity_B;
	CLS;
	int i;
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - 关系复合运算");
	loginui();

	mark = autoInput(2, a, 1,0);
	quantity_A = mark;
	if (mark == -1)
		printf("\n\n打开文件失败\n");
	if (mark)
		mark = autoInput(2, b, 0, 0);
	loginui();
	quantity_B = mark;
	if (mark == -1)
		printf("\n\n打开文件失败\n");
	if (mark < 1)
	{

		while (flag3)
		{
			printf("请输入第一组关系：\n");
			quantity_A = inputdata(a, 2);
			if (quantity_A == -1)
			{
				loginui();
				return 11;
			}
			if (quantity_A == 0)
			{
				msgbox("出错了呢", "未检测到有效数据，请再输入一遍", 5, 5, 50, 8, 0, 1);
				loginui();
			}
			else
				flag3 = 0;
		}
		flag3 = 1;
		while (flag3)
		{
			printf("\b \n\n请输入第二组关系：\n");

			quantity_B = inputdata(b, 2);
			if (quantity_B == -1)
			{
				loginui();
				return 11;
			}
			if (quantity_B == 0)
			{
				msgbox("出错了呢", "未检测到有效数据，请再输入一遍", 5, 5, 50, 8, 0, 1);
				loginui();
			}
			else
				flag3 = 0;
		}
		flag3 = 1;
	}
	loginui();


	printf("第一组关系为：\n\t");
	for (i = 0; i < 2 * quantity_A; i += 2)
	{
		printf("<%d,%d>\t", a[i], a[i + 1]);
		if (i % 14 == 0 && i > 8)
			printf("\n");
	}
	printf("\n\n第二组关系为：\n\t");
	for (i = 0; i < 2 * quantity_B; i += 2)
	{
		printf("<%d,%d>\t", b[i], b[i + 1]);
		if (i % 14 == 0 && i > 8)
			printf("\n");
	}

	quantity = gxfh(a, quantity_A, b, quantity_B, obj);

	printf("\n\n\n复合关系运算结果：\n\t");
	

	for (i = 0; i <  quantity; i += 2)
	{
		flag3 = 0;
		printf("<%d,%d>\t", obj[i], obj[i + 1]);
		if (i % 16 == 0 && i > 8)
			printf("\n\t");
	}
	if (flag3)
		printf("[无运算结果]");
	flag3 = 1;
	gotoxy(0, MAXH + 7);
	printf("按s保存计算结果 按其他键返回上一级菜单");
	if (_getch() == 115)
	{
		FILE *fp;
		fp = fopen("关系复合运算.txt", "a+");
		fprintf(fp,"第一组关系为：\n\t");
		for (i = 0; i < 2 * quantity_A; i += 2)
		{
			fprintf(fp,"<%d,%d>\t", a[i], a[i + 1]);
			if (i % 14 == 0 && i > 8)
				fprintf(fp,"\n");
		}
		fprintf(fp,"\n\n第二组关系为：\n\t");
		for (i = 0; i < 2 * quantity_B; i += 2)
		{
			fprintf(fp,"<%d,%d>\t", b[i], b[i + 1]);
			if (i % 14 == 0 && i > 8)
				fprintf(fp,"\n");
		}

		quantity = gxfh(a, quantity_A, b, quantity_B, obj);

		fprintf(fp,"\n\n\n符合关系运算结果：\n\t");


		for (i = 0; i < quantity; i += 2)
		{
			flag3 = 0;
			fprintf(fp,"<%d,%d>\t", obj[i], obj[i + 1]);
			if (i % 16 == 0 && i > 8)
				fprintf(fp,"\n\t");
		}
		if (flag3)
			fprintf(fp,"[无运算结果]");

		fprintf(fp, "\n\n===========================================================================\n\n");
		printf("  保存成功！");
		_getch();
		fclose(fp);
	}
	loginui();
	return 11;

}

int equalWindows(void)
{
	int i, flag = 1,overall,flag3=1,mark,debug_mode_run=0;
	int a[50] = { 0 }, quantity_A;
	int b[100] = { 0 }, quantity_B;
	int obj[200] = { 0 };
	int ans = 0;
	CLS;
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - 分析等价关系");
	loginui();
	mark = autoInput(1, a, 1,1);
	quantity_A = mark;
	if (mark == -1)
		printf("\n\n打开文件失败\n");
	if (mark)
		mark = autoInput(2, b, 0, 1);
	loginui();
	quantity_B = mark;
	if (mark == -1)
		printf("\n\n打开文件失败\n");
	if (mark < 1)
	{
		while (flag3)
		{
			printf("请输入集合元素：\n");
			quantity_A = inputdata(a, 1);
			if (quantity_A == -1)
			{
				loginui();
				return 11;
			}
			if (quantity_A == 0)
			{
				msgbox("出错了呢", "未检测到有效数据，请再输入一遍", 5, 5, 50, 8, 0, 1); \
					loginui();
			}
			else
				flag3 = 0;
		}
		flag3 = 1;

		printf("\n\n\n");
		while (flag3)
		{
			printf("请输入关系数据：\n");
			quantity_B = inputdata(b, 2);
			if (quantity_B == -1)
			{
				loginui();
				return 11;
			}
			if (quantity_B == 0)
			{
				msgbox("出错了呢", "未检测到有效数据，请再输入一遍", 5, 5, 50, 8, 0, 1); \
					loginui();
			}
			else
				flag3 = 0;
		}
		flag3 = 1;
	}
	loginui();
	gotoxy(0, 2);
	printf("集合数据为：\n\t{");
	for (i = 0; i < quantity_A; i++)
	{
		printf("%d, ", a[i]);
		if (i % 14 == 0 && i > 4)
			printf("\n");
	}
	printf("\b\b}\n\n");
	printf("关系数据为：\n\t");
	for (i = 0; i < 2 * quantity_B; i += 2)
	{
		printf("<%d,%d>\t", b[i], b[i + 1]);
		if (i % 14 == 0 && i > 8)
			printf("\n");
	}


	ans = lsmath(a, quantity_A, b, quantity_B,debug_mode_run);
	overall = ans % 10;
	switch (overall)
	{
	
	case 7:
		printf("\n\n该关系满足等价关系");
		break;
	default:
		printf("\n\n该关系不满足等价关系");
		break;
	}

	gotoxy(0, MAXH + 7);
	printf("按s保存计算结果 按其他键返回上一级菜单");
	if (_getch() == 115)
	{
		FILE *fp;
		fp = fopen("判断等价关系.txt", "a+");
		fprintf(fp,"集合数据为：\n\t{");
		for (i = 0; i < quantity_A; i++)
		{
			fprintf(fp,"%d, ", a[i]);
			if (i % 14 == 0 && i > 4)
				fprintf(fp,"\n");
		}
		fprintf(fp,"}\n\n");
		fprintf(fp,"关系数据为：\n\t");
		for (i = 0; i < 2 * quantity_B; i += 2)
		{
			fprintf(fp,"<%d,%d>\t", b[i], b[i + 1]);
			if (i % 14 == 0 && i > 8)
				fprintf(fp,"\n");
		}


		ans = lsmath(a, quantity_A, b, quantity_B, debug_mode_run);
		overall = ans % 10;
		switch (overall)
		{

		case 7:
			fprintf(fp,"\n\n该关系满足等价关系");
			break;
		default:
			fprintf(fp,"\n\n该关系不满足等价关系");
			break;
		}
		fprintf(fp, "\n\n===========================================================================\n\n");
		printf("  保存成功！");
		_getch();
		fclose(fp);
	}


	loginui();
	return 11;
}

int partialWindows(void)
{
	int i, flag = 1,flag3=1,mark;
	int  overall;
	int obj[200] = { 0 };
	int ans = 0;
	int a[50] = { 0 }, quantity_A;
	int b[100] = { 0 }, quantity_B;
	int debug_mode_run = 0;

	CLS;
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - 分析偏序关系");
	loginui();
	mark = autoInput(1, a, 1,1);
	quantity_A = mark;
	if (mark == -1)
		printf("\n\n打开文件失败\n");
	if (mark)
		mark = autoInput(2, b, 0, 1);
	loginui();
	quantity_B = mark;
	if (mark == -1)
		printf("\n\n打开文件失败\n");
	if (mark < 1)
	{
		while (flag3)
		{
			printf("请输入集合元素：\n");

			quantity_A = inputdata(a, 1);
			if (quantity_A == -1)
			{
				loginui();
				return 11;
			}
			if (quantity_A == 0)
			{
				msgbox("出错了呢", "未检测到有效数据，请再输入一遍", 5, 5, 50, 8, 0, 1); \
					loginui();
			}
			else
				flag3 = 0;
		}
		flag3 = 1;

		while (flag3)
		{
			printf("\n\t");
			printf("请输入关系数据：\n");
			quantity_B = inputdata(b, 2);
			if (quantity_B == -1)
			{
				loginui();
				return 11;
			}
			if (quantity_B == 0)
			{
				msgbox("出错了呢", "未检测到有效数据，请再输入一遍", 5, 5, 50, 8, 0, 1); \
					loginui();
			}
			else
				flag3 = 0;
		}
		flag3 = 1;
	}

	gotoxy(0, 2);
	printf("集合数据为：\n\t{");
	for (i = 0; i < quantity_A; i++)
	{
		printf("%d, ", a[i]);
		if (i % 14 == 0 && i > 4)
			printf("\n");
	}
	printf("}\n\n");
	printf("关系数据为：\n\t");
	for (i = 0; i < 2 * quantity_B; i += 2)
	{
		printf("<%d,%d>\t", b[i], b[i + 1]);
		if (i % 14 == 0 && i > 8)
			printf("\n");
	}


	ans = lsmath(a, quantity_A, b, quantity_B,debug_mode_run);
	overall = ans % 100;
	switch (overall)
	{

	case 25:
		printf("\n该关系满足偏序关系");
		break;
	default:
		printf("\n该关系不满足偏序关系");
		break;
	}

	gotoxy(0, MAXH + 7);
	printf("按s保存计算结果 按其他键返回上一级菜单");
	if (_getch() == 115)
	{
		FILE *fp;
		fp = fopen("判断偏序关系.txt", "a+");
		fprintf(fp, "集合数据为：\n\t{");
		for (i = 0; i < quantity_A; i++)
		{
			fprintf(fp, "%d, ", a[i]);
			if (i % 14 == 0 && i > 4)
				fprintf(fp, "\n");
		}
		fprintf(fp, "\b\b}\n\n");
		fprintf(fp, "关系数据为：\n\t");
		for (i = 0; i < 2 * quantity_B; i += 2)
		{
			fprintf(fp, "<%d,%d>\t", b[i], b[i + 1]);
			if (i % 14 == 0 && i > 8)
				fprintf(fp, "\n");
		}


		ans = lsmath(a, quantity_A, b, quantity_B, debug_mode_run);
		overall = ans % 100;
		switch (overall)
		{

		case 25:
			fprintf(fp, "\n该关系满足偏序关系");
			break;
		default:
			fprintf(fp, "\n该关系不满足偏序关系");
			break;
		}
		fprintf(fp, "\n\n===========================================================================\n\n");
		printf("  保存成功！");
		_getch();
		fclose(fp);
	}
	


	loginui();
	return 11;
}

int inversionWindows(void)
{
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - 计算关系的逆");
	loginui();

	int flag3 = 1,mark,i;
	int b[100] = { 0 }, quantity_B;
	
	mark = autoInput(2, b, 1,0);
	quantity_B = mark;
	if (mark == -1)
		printf("\n\n打开文件失败\n");
	if (mark < 1)
	{
		while (flag3)
		{
			loginui();
			printf("请输入关系数据：\n");

			quantity_B = inputdata(b, 2);
			if (quantity_B == -1)
			{
				loginui();
				return 11;
			}
			if (quantity_B == 0)
			{
				msgbox("出错了呢", "未检测到有效数据，请再输入一遍", 5, 5, 50, 8, 0, 1); \
					loginui();
			}
			else
				flag3 = 0;
		}
		flag3 = 1;
	}
	loginui();
	printf("关系数据为：\n\t");
	for (i = 0; i < 2 * quantity_B; i += 2)
	{
		printf("<%d,%d>\t", b[i], b[i + 1]);
		if (i % 14 == 0 && i > 8)
			printf("\n");
	}

	int obj[100];
	inversion(b, obj, quantity_B);
	printf("\b\b\n\n");
	printf("关系的逆为：\n\t");
	for (int i = 0; i < 2 * quantity_B; i += 2)
	{
		printf("<%d,%d>\t", b[i+1], b[i]);
		if (i % 14 == 0 && i > 8)
			printf("\n\t");
	}

	gotoxy(0, MAXH + 7);
	printf("按s保存计算结果 按其他键返回上一级菜单");
	if (_getch() == 115)
	{
		FILE *fp;
		fp = fopen("逆关系运算.txt", "a+");

		fprintf(fp,"关系数据为：\n\t");
	for (i = 0; i < 2 * quantity_B; i += 2)
	{
		fprintf(fp,"<%d,%d>\t", b[i], b[i + 1]);
		if (i % 14 == 0 && i > 8)
			fprintf(fp,"\n");
	}

	int obj[100];
	inversion(b, obj, quantity_B);
	fprintf(fp,"\n\n");
	fprintf(fp,"关系的逆为：\n\t");
	for (int i = 0; i < 2 * quantity_B; i += 2)
	{
		fprintf(fp,"<%d,%d>\t", b[i+1], b[i]);
		if (i % 14 == 0 && i > 8)
			fprintf(fp,"\n\t");
	}
	fprintf(fp, "\n\n===========================================================================\n\n");
	printf("  保存成功！");
	_getch();
	fclose(fp);


	}
	loginui();
	return 11;
}

int autoInput(int mode,int arr[],int flag,int mark)
{
	int re;
	if (flag)
	{
		printf("\n\n=====按空格键自动载入数据，其他键进入手动输入模式=====");
		if (_getch() != 32)
			return 0;
	}
	loginui();
	char fileName[10][20] = { "jh_auto_input_1.dat",
		"jh_auto_input_2.dat",
		"jh_auto_input_3.dat",
		"jh_auto_input_4.dat",
		"jh_auto_input_5.dat",
		"gx_auto_input_1.dat",
		"gx_auto_input_2.dat",
		"gx_auto_input_3.dat",
		"gx_auto_input_4.dat",
		"gx_auto_input_5.dat" };

	int n,m;
	FILE *fp;
	if (mode == 1)
	{
		n = produceRandNumber(0, 4, 17);
		if (mark)
			n = mark;
		fp = fopen(fileName[n], "r");
		
	}
	else
	{
		n = produceRandNumber(5, 9, 12);
		if (mark)
			n = mark+5;
		fp = fopen(fileName[n], "r");
	}
	if (!fp)
	{
		fclose(fp);
		return -1;
	}

	//fseek(fp, 0L, SEEK_END);
	fscanf(fp,"%d", &m);
	//int arrr[30] = { 0 };
	for (n = 0; n < m; n++)
	{
		fscanf(fp,"%d", &arr[n]);
	}
	fclose(fp);
	re = m;
	if (mode == 2)
		re /= 2;
	//arr[0] = 1; arr[1] = 1;
	return re;

}



//==========================================================================================================================================
//函数名：equalclassWindows
//作者：确定格式化
//日期：2016.05.05
//功能：分析等价类（模x同余）
//输入参数：无
//返回值：	类型		整形（int）
//					11：上一级菜单GUID
//			
//修改记录：
//
//
//==========================================================================================================================================
int equalclassWindows(void)
{
	CLS;
	int i, flag = 1, mark,h;
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - 分析等价类");
	loginui();

	int a[100] = { 0 }, quantity_A;
	int modnumber;
	int meo[100][100] = { 0 };
	

	mark = autoInput(1, a, 1, 0);
	quantity_A = mark;
	if (mark == -1)
		printf("\n\n打开文件失败\n");
	
	if (mark < 1)
	{
		while (flag)
		{
			loginui();
			printf("请输入集合数据：\n");
			quantity_A = inputdata(a, 1);
			if (quantity_A == -1)
			{
				loginui();
				return 11;
			}
			if (quantity_A == 0)
			{
				msgbox("出错了呢", "未检测到有效数据，请再输入一遍", 5, 5, 50, 8, 0, 1);
				loginui();
			}
			else
				flag = 0;
		}
		
	}
	flag = 1;
	loginui();
	gotoxy(0, 2);
	printf("第一组集合为：\n\n\t{");
	for (i = 0; i < quantity_A; i++)
	{
		printf("%d, ", a[i]);
		if (i % 20 == 0 && i > 4)
			printf("\n");
	}
	printf("\b\b}\n\n");
	printf("计算模_____同余\b\b\b\b\b\b\b");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | COMMON_LVB_UNDERSCORE);
	scanf("%d", &modnumber);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);


	equalclassNew(a, quantity_A, modnumber, meo);
	
	printf("\n\n\n运算结果：\n\n\t");

	for (i = 0; i < modnumber; i ++)
	{
		for (h = 1; h <= meo[i][0]; h++)
		{
			printf("[%d] = ", meo[i][h]);
		}
		printf("{");
		for (h = 1; h <= meo[i][0]; h++)
		{
			printf("%d,", meo[i][h]);
		}
		if (i < modnumber)
			printf("\b}\n\n\t");
	}

	gotoxy(0, MAXH + 7);
	printf("按s保存计算结果 按其他键返回上一级菜单");
	if (_getch() == 115)
	{
		FILE *fp;
		fp = fopen("分析等价类.txt", "a+");
		fprintf(fp, "第一组集合为：\n\n\t{");
		for (i = 0; i < quantity_A; i++)
		{
			fprintf(fp, "%d, ", a[i]);
			if (i % 20 == 0 && i > 4)
				fprintf(fp, "\n");
		}
		fprintf(fp, "}\n\n计算模 %d 同余", modnumber);
		fprintf(fp, "\n\n\n运算结果：\n\n\t");

		for (i = 0; i < modnumber; i++)
		{
			for (h = 1; h <= meo[i][0]; h++)
			{
				fprintf(fp, "[%d] = ", meo[i][h]);
			}
			fprintf(fp, "{");
			for (h = 1; h <= meo[i][0]; h++)
			{
				fprintf(fp, "%d,", meo[i][h]);
			}
			if (i < modnumber)
				fprintf(fp, "}\n\n\t");
		}

		fprintf(fp, "\n\n===========================================================================\n\n");
		printf("  保存成功！");
		_getch();
		fclose(fp);
	}
	loginui();
	return 11;
}
