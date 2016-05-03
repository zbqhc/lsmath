#include<conio.h>
#include<stdio.h>
#include<Windows.h>
#include"lsmath.h"

extern void loginui(void);
extern int inputdata(int[], int);
extern int outputdata(int[], int, int);

extern void gotoxy(int x, int y);
extern int lsmath(int[], int, int[], int);
extern int gxfh(int a[], int ai, int b[], int bi, int obj[]);
extern int inversion(int [],int [],int);


int base(int a[], int ai, int b[], int bi, int obj[], int mode);
int dker(int[], int, int[], int,int [], int);

int lsbaseWindows(void)
{
	int i, quantity, flag = 1, flag2;
	int obj[200] = { 0 };
	CLS;
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - 关系的基本运算");
	loginui();
	printf("请输入第一组关系：\n");
	int a[100] = { 0 }, quantity_A;
	quantity_A = inputdata(a, 2);

	printf("请输入第二组关系：\n");
	int b[100] = { 0 }, quantity_B;
	quantity_B = inputdata(b, 2);
	loginui();
	while (flag)
	{
		printf("第一组关系为：\n");
		for (i = 0; i < 2 * quantity_A; i += 2)
		{
			printf("<%d,%d>\t", a[i], a[i + 1]);
			if (i % 14 == 0 && i > 8)
				printf("\n");
		}
		printf("\n\n第二组关系为：\n");
		for (i = 0; i < 2 * quantity_B; i += 2)
		{
			printf("<%d,%d>\t", b[i], b[i + 1]);
			if (i % 14 == 0 && i > 8)
				printf("\n");
		}

		printf("\n\n\n\n运算结果：\n");

		quantity = base(a, quantity_A, b, quantity_B, obj, 1);
		printf("\n并集：\n\t");
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
		flag = 0;
		gotoxy(0, MAXH+7);
		printf("计算完毕 按r重新计算 按esc返回上一级菜单 按s保存计算结果");

		i = 0;
		while (quantity = _getch())
		{
			if (quantity == 13)
				i++;
			if (quantity == 13 && i == 2)
			{
				gotoxy(0, MAXH+7);
				printf("计算完毕 按r重新计算 按esc返回上一级菜单 按s保存计算结果  你按回车键干嘛");
			}
			if (quantity == 13 && i == 3)
			{
				gotoxy(0, MAXH+7);
				printf("计算完毕 按r重新计算 按esc返回上一级菜单 按s保存计算结果  而且还按了三次");
			}
			if (quantity == 13 && i >= 5)
			{
				gotoxy(0, MAXH+7);
				printf("计算完毕 按r重新计算 按esc返回上一级菜单 按s保存计算结果  好吧按回车键也可以退出");
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
				printf("save!!");
				_getch();
				loginui();
				flag = 1;
				break;
			}

		}
	}


	return flag2;
}

int dkerWindows(void)
{
	CLS;
	int i;
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - 笛卡尔乘积运算");
	loginui();

	int a[20] = { 0 }, b[20] = { 0 }, obj[400] = { 0 }, quantity_A, quantity_B;
	printf("请输入第一组集合数据：\n");
	quantity_A = inputdata(a, 1);
	printf("请输入第二组集合数据：\n");
	quantity_B = inputdata(b, 1);

	
	gotoxy(0, 2);
	printf("第一组集合为：\n\t{");
	for (i = 0; i <  quantity_A; i ++)
	{
		printf("%d, ", a[i]);
		if (i % 20 == 0 && i > 4)
			printf("\n");
	}
	printf("\b\b}\n\n");

	printf("第二组集合为：\n\t{");
	for (i = 0; i <  quantity_B; i ++)
	{
		printf("%d, ", b[i]);
		if (i % 20 == 0 && i > 8)
			printf("\n");
	}
	printf("\b\b}\n\n\n笛卡尔乘积运算结果：\n\t");
	quantity_A = dker(a, quantity_A, b, quantity_B, obj, 0);

	for (i = 0; i < 2 * quantity_A; i += 2)
	{
		printf("<%d,%d>\t", obj[i], obj[i + 1]);
		if (i % 16 == 0 && i > 8)
			printf("\n\t");
	}

	_getch();
	loginui();
	return 11;
}

int gxbbWindows(void)
{
	int i,  flag = 1, flag2;
	int count_zf, count_dc, count_cd,overall;
	int obj[200] = { 0 };
	int ans = 0;
	CLS;
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - 分析关系闭包");
	loginui();

	printf("请输入集合元素：\n");
	int a[50] = { 0 },quantity_A;
	quantity_A = inputdata(a, 1);
	printf("\n\t");
	printf("请输入关系数据：\n");
	int b[100] = { 0 }, quantity_B;
	quantity_B = inputdata(b, 2);

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


	ans = lsmath(a, quantity_A, b, quantity_B);
	overall = ans % 10;
	count_zf = (ans - ans % 100000) / 100000;
	count_dc = (ans - count_zf*100000 - ans % 1000) / 1000;
	count_cd = (ans - count_zf*100000 - count_dc*1000 - ans % 10) / 10;


	//printf("\n%d\t%d\t%d\t%d\t%d", ans,count_zf,count_dc,count_cd,overall);
	if (overall > 0)
		printf("该关系满足");
	else
		printf("该关系不满足自反、对称、传递\n");

	switch (overall)
	{
	case 1:
		printf("\033[4m传递\033[0m性质\n");
		break;
	case 2:
		printf("\033[4m对称\033[0m性质\n");
		break;
	case 3:
		printf("\033[4m对称\033[0m、\033[4m传递\033[0m性质\n");
		break;
	case 4:
		printf("\033[4m自反\033[0m性质\n");
		break;
	case 5:
		printf("\033[4m自反\033[0m、\033[4m传递\033[0m性质\n");
		break;
	case 6:
		printf("\033[4m自反\033[0m、\033[4m对称\033[0m性质\n");
		break;
	case 7:
		printf("\033[4m自反\033[0m、\033[4m对称\033[0m、\033[4m传递\033[0m性质\n");
		break;
	default:
		break;
	}
	printf("\n自反闭包：%d\t对称闭包：%d\t传递闭包：%d", count_zf, count_dc, count_cd);
	_getch();


	loginui();
	return 11;
}

//函数名：gxfh
//作者：确定格式化
//日期：2016.04.03
//功能：对给定两个关系进行关系复合运算
//输入参数：	a		第一组关系
//			ai		第一组关系个数
//			b		第二组关系
//			bi		第二组关系个数
//			obj		关系复合运算结果目标
//返回值：	类型		整形（int）
//					表示运算结果所包含元素个数
//			错误代码：-1		内存分配失败
//					  0		关系复合运算结果为空
//			
//修改记录：
//
//



int complexWindows(void)
{
	int  obj[100] = { 0 },quantity;
	CLS;
	int i;
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - 笛卡尔乘积运算");
	loginui();


	printf("请输入第一组关系：\n");
	int a[100] = { 0 }, quantity_A;
	quantity_A = inputdata(a, 2);

	printf("请输入第二组关系：\n");
	int b[100] = { 0 }, quantity_B;
	quantity_B = inputdata(b, 2);
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

	printf("\n\n\n符合关系运算结果：\n\t");
	

	for (i = 0; i <  quantity; i += 2)
	{
		printf("<%d,%d>\t", obj[i], obj[i + 1]);
		if (i % 16 == 0 && i > 8)
			printf("\n\t");
	}

	_getch();
	loginui();
	return 11;

}

int equalWindows(void)
{
	int i, flag = 1, flag2;
	int count_zf, count_dc, count_cd, overall;
	int obj[200] = { 0 };
	int ans = 0;
	CLS;
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - 分析关系闭包");
	loginui();

	printf("请输入集合元素：\n");
	int a[50] = { 0 }, quantity_A;
	quantity_A = inputdata(a, 1);
	printf("\n\t");
	printf("请输入关系数据：\n");
	int b[100] = { 0 }, quantity_B;
	quantity_B = inputdata(b, 2);

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


	ans = lsmath(a, quantity_A, b, quantity_B);
	overall = ans % 10;
	switch (overall)
	{
	
	case 7:
		printf("该关系满足等价关系");
		break;
	default:
		printf("该关系不满足等价关系");
		break;
	}
	
	_getch();


	loginui();
	return 11;
}

int partialWindows(void)
{
	int i, flag = 1, flag2;
	int count_zf, count_dc, count_cd, overall;
	int obj[200] = { 0 };
	int ans = 0;
	CLS;
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - 分析关系闭包");
	loginui();

	printf("请输入集合元素：\n");
	int a[50] = { 0 }, quantity_A;
	quantity_A = inputdata(a, 1);
	printf("\n\t");
	printf("请输入关系数据：\n");
	int b[100] = { 0 }, quantity_B;
	quantity_B = inputdata(b, 2);

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


	ans = lsmath(a, quantity_A, b, quantity_B);
	overall = ans % 10;
	switch (overall)
	{

	case 5:
		printf("该关系满足偏序关系");
		break;
	default:
		printf("该关系不满足偏序关系");
		break;
	}

	_getch();


	loginui();
	return 11;
}

int inversionWindows(void)
{
	loginui();
	printf("请输入关系数据：\n");
	int b[100] = { 0 }, quantity_B;
	quantity_B = inputdata(b, 2);
	int obj[100];
	inversion(b, obj, quantity_B);
	printf("\b\b}\n\n");
	printf("关系的逆为为：\n\t");
	for (int i = 0; i < 2 * quantity_B; i += 2)
	{
		printf("<%d,%d>\t", b[i], b[i + 1]);
		if (i % 14 == 0 && i > 8)
			printf("\n");
	}
	loginui();
	return 11;
}