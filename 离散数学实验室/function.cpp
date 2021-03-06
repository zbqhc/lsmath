#include"lsmath.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>

int denum(int[], int);
int iscf(int[], int);
extern void gotoxy(int x, int y);


//==========================================================================================================================================
//函数名：dker
//作者：范守峰
//日期：2016.04.18
//功能：计算两个集合笛卡尔乘积
//输入参数：	lsa：	集合a
//			lsaa：	集合a元素个数
//			lsb：	集合b
//			lsbb：	集合b元素个数
//			obj:	目标数组
//			debug：	调试模式，1：允许，0：禁用
//返回值：	运行正常：1，参数错误：0
//修改记录：
//
//
//
//==========================================================================================================================================
int dker(int lsa[], int lsaa, int lsb[], int lsbb, int obj[], int debug)
{
	int o, p, i = 0;
	if (lsaa <= 0 || lsbb <= 0)
		return 0;
	for (o = 0; o < lsaa; o++)
		for (p = 0; p < lsbb; p++)
		{
			i++;
			obj[2 * (o*lsbb + p)] = lsa[o];
			obj[2 * (o*lsbb + p) + 1] = lsb[p];
		}

	return i;
}

//==========================================================================================================================================
//函数名：isin
//作者：张博强
//日期：2016.04.25
//功能：判断某元素是否存在于某数组
//输入参数：	arr：	目标数组
//			n：		数组元素个数
//			num：	待判断数据
//返回值：	存在：1，不存在：0
//修改记录：
//
//==========================================================================================================================================
int isin(int arr[], int n, int num)
{
	for (int i = 0; i < n; i++)
	{
		if (num == arr[i])	return 1;
	}
	return 0;
}

//==========================================================================================================================================
//函数名：csort
//作者：张博强
//日期：2016.04.25
//功能：对给定数据进行从大到小或从小到大排序
//输入参数： p：		待处理的（一维）数组
//          cou:	数据个数
//			mode：	排序模式，1：降序，-1：升序
//返回值：	运行正常：1，参数错误：-1
//修改记录：
//
//
//
//==========================================================================================================================================
int csort(int p[], int counter, int mode)  //obj arr  ; the number of   ;mode 1:v   0:?^
{
	int ct = -1, i, u;
	for (i = 0; i < counter; i++)
	{
		ct = p[i];
		for (u = i - 1; u >= 0; u--)
		{
			if (mode != 1 && mode != -1)
			{
				//printf("ERROR!\nat parameter of csort");
				return -1;
			}
			if (mode == 1 && p[u] > ct)
				p[u + 1] = p[u];
			else if (mode == -1 && p[u] < ct)
				p[u + 1] = p[u];
			else
				break;
		}
		p[u + 1] = ct;
	}
	return 1;
}

//==========================================================================================================================================
//函数名：lsmath
//作者：张博强
//日期：2016.04.26
//功能：对给定关系集合进行分析是否满足自反、对称以及传递，并分别返回其自反、对称、传递闭包
//输入参数： org					传入集合数组
//			a					集合数组元素个数
//			arr					传入关系数组
//			n					关系数组元素个数
//			debug_mode_run		调试模式开关
//返回值：	类型		整形（int）
//			末位数字：当满足自反记 4，对称记 2，传递记 1，末位即为关系满足情况加和，均未满足为0
//			倒第二位：1：反自反	2：反对称	3：同时满足反自反、反对称
//			高位数字：千万位百万位为自反闭包数目，十万位万位为对称闭包个数，千位百位为传递闭包格式
//			错误代码：-1		内存申请失败
//					 -2		数据错误
//修改记录：
//
//
//
//==========================================================================================================================================
int lsmath(int org[], int a, int arr[], int n, int debug_mode_run)
{
	int count_zf = 0, count_dc = 0, count_cd = 0; //闭包计数变量
	int i, o, p, x, y, t, k = 1;
	int re = 0;
	int flag = 0, flag2 = 0, flag3 = 0;

	HANDLE hOut;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	csort(org, a, 1);



	//生成关系矩阵========================Create the relational matrix=======================================================================

	int **tp;
	tp = (int **)malloc(a * sizeof(int *));

	for (i = 0; i < a; i++)
		tp[i] = (int *)malloc(a * sizeof(int));



	for (i = 0; i < a; i++)
		for (o = 0; o < a; o++)
			tp[i][o] = 0;
	for (i = 0; i < 2 * n; i += 2)
	{
		x = arr[i];
		y = arr[i + 1];
		for (t = 0; t < a && flag2 != 2; t++)
		{
			if (x == org[t])
			{
				x = t;
				flag2++;
			}
			if (y == org[t])
			{
				y = t;
				flag2++;
			}
		}
		if (flag2 < 2)		return -1;
		flag2 = 0;
		tp[x][y] = 1;

	}




	//调试模式============================DEBUG Mode======================================================================
	if (DEBUG_MODE || debug_mode_run)
	{
		printf("\n\n关系矩阵：\n");
		for (i = 0; i < a; i++)
		{
			if (i == 0)
			{
				printf("    ");
				for (o = 0; o < a; o++)
				{
					printf("   ");
					SetConsoleTextAttribute(hOut,
						FOREGROUND_RED |
						FOREGROUND_GREEN |
						FOREGROUND_INTENSITY);
					printf("%d", org[o]);
					SetConsoleTextAttribute(hOut,
						FOREGROUND_RED |
						FOREGROUND_GREEN |
						FOREGROUND_BLUE |
						FOREGROUND_INTENSITY);
				}
				printf("\n    ┌");
				for (o = 0; o < a - 1; o++)
					printf("─┬");
				printf("─┐\n  ");
				SetConsoleTextAttribute(hOut,
					FOREGROUND_RED |
					FOREGROUND_GREEN |
					FOREGROUND_INTENSITY);
				printf("%d", org[i]);
				SetConsoleTextAttribute(hOut,
					FOREGROUND_RED |
					FOREGROUND_GREEN |
					FOREGROUND_BLUE |
					FOREGROUND_INTENSITY);
				printf(" │");


			}
			for (o = 0; o < a; o++)
			{
				if (tp[i][o] == 1)
				{
					printf(" ");
					SetConsoleTextAttribute(hOut,
						FOREGROUND_BLUE |
						FOREGROUND_RED |
						FOREGROUND_GREEN |
						BACKGROUND_RED |
						FOREGROUND_INTENSITY);
					printf("%d", tp[i][o]);
					SetConsoleTextAttribute(hOut,
						FOREGROUND_RED |
						FOREGROUND_GREEN |
						FOREGROUND_BLUE |
						FOREGROUND_INTENSITY);
					printf("│");
				}
				else
					printf(" %d│", tp[i][o]);

			}
			if (i != a - 1)
			{
				printf("\n    ├");
				for (o = 0; o < a - 1; o++)
					printf("─┼");
				printf("─┤");
				if (org[i + 1] > 9)
				{
					printf("\n");
					SetConsoleTextAttribute(hOut,
						FOREGROUND_RED |
						FOREGROUND_GREEN |
						FOREGROUND_INTENSITY);
					printf(" %d", org[i + 1]);
					SetConsoleTextAttribute(hOut,
						FOREGROUND_RED |
						FOREGROUND_GREEN |
						FOREGROUND_BLUE |
						FOREGROUND_INTENSITY);
					printf(" │");
				}
				else
				{
					printf("\n  ");
					SetConsoleTextAttribute(hOut,
						FOREGROUND_RED |
						FOREGROUND_GREEN |
						FOREGROUND_INTENSITY);
					printf("%d", org[i + 1]);
					SetConsoleTextAttribute(hOut,
						FOREGROUND_RED |
						FOREGROUND_GREEN |
						FOREGROUND_BLUE |
						FOREGROUND_INTENSITY);
					printf(" │");
				}
			}
			else
			{
				printf("\n    └");
				for (o = 0; o < a - 1; o++)
					printf("─┴");
				printf("─┘\n");
			}
		}
	}
	//判断自反============================ZIFAN Analysis======================================================================
	{
		for (i = 0; i < a; i++)
		{
			if (tp[i][i] == 0)
			{
				flag = 1;
				count_zf++;
			}
		}
		if (count_zf == a)//反自反
			re += 10;
		if (flag == 0)
		{
			re += 4;
		}

		flag = 0;
	}

	//判断对称============================DUICHEN Analysis======================================================================
	{
		for (i = 0; i < a - 1; i++, k++)
		{
			for (p = k; p < a; p++)
			{
				if (tp[i][p] != tp[p][i])
				{
					flag = 1;
					count_dc++;
				}
				else if (tp[i][p] == 1)
					flag3 = 1;
			}
		}

		if (flag == 1 && flag3 == 0)
			re += 20;
		if (flag == 0)
		{
			re += 2;
		}

		flag = 0;
	}

	//判断传递==================================================================================================
	{
		for (i = 0; i < a; i++)
		{
			for (p = 0; p < a; p++)
			{
				if (tp[i][p] == 1)
				{
					for (o = 0; o < a; o++)
					{
						if (tp[p][o] == 1)
						{
							if (tp[i][o] == 0)
							{
								flag = 1;
								count_cd++;
							}
						}
					}
				}
			}
		}





		if (flag == 0)
		{
			re += 1;
		}

		flag = 0;
	}

	//输出结果==================================================================================================
	re += count_zf * 1000000 + count_dc * 10000 + count_cd * 100;


	if (DEBUG_MODE || debug_mode_run)
		printf("\n返回原始数据为：%d", re);
	return re;


}

//==========================================================================================================================================
//函数名：base
//作者：李昕
//日期：2016.04.27
//功能：对给定两个集合进行基本运算
//输入参数：	a		第一个关系
//			ai		第一个关系元素个数
//			b		第二个关系
//			bi		第二个关系元素个数
//			obj		基本运算结果目标
//			mode	运算模式：1	并集运算，2 交集运算，3 差集运算（a差b）
//返回值：	类型		整形（int）
//					表示运算结果所包含元素个数
//			错误代码：-1		输入数据错误
//修改记录：
//
//
//==========================================================================================================================================
int base(int a[], int ai, int b[], int bi, int obj[], int mode)
{
	int i, j, u, flag = 0, flag2 = 1, flag3 = 0, f = 0;
	int objarr = 0;



	switch (mode)
	{
	case 1:
		for (i = 0; i < 2 * ai; i += 2)
		{
			for (j = 0; j < objarr; j += 2)
				if (obj[j] == a[i] && obj[j + 1] == a[i + 1])
					flag2 = 0;
			if (flag2)
			{
				obj[objarr] = a[i];
				obj[objarr + 1] = a[i + 1];
				objarr += 2;
			}
			flag2 = 1;
		}

		for (i = 0; i < 2 * bi; i += 2)
		{
			for (j = 0; j < objarr; j += 2)
				if (obj[j] == b[i] && obj[j + 1] == b[i + 1])
				{
					flag2 = 0;
					break;
				}
			if (flag2)
			{
				obj[objarr] = b[i];
				obj[objarr + 1] = b[i + 1];
				objarr += 2;
			}
			flag2 = 1;
		}
		flag = objarr / 2;
		break;

	case 2:
		for (i = 0; i < 2 * ai; i += 2)
		{
			for (u = 0; u < 2 * bi; u += 2)
			{
				if (a[i] == b[u] && a[i + 1] == b[u + 1])
				{
					obj[flag++] = a[i];
					obj[flag++] = a[i + 1];
					flag3 = 1;
					break;
				}
			}
		}
		if (flag3)
			flag /= 2;
		else
			flag = -20;
		break;
	case 3:
		for (i = 0; i < 2 * ai; i += 2, f = 0)
		{
			for (u = 0; u < 2 * bi; u += 2)
			{
				if (a[i] == b[u] && a[i + 1] == b[u + 1])
				{
					f = 1;
					break;
				}
			}
			if (f == 0)
			{
				obj[flag++] = a[i];
				obj[flag++] = a[i + 1];
				flag3 = 1;
			}
		}
		if (flag3)
			flag /= 2;
		else
			flag = -20;
		break;
	}
	return flag;
}

//==========================================================================================================================================
//函数名：denum
//作者：张博强
//日期：2016.04.26
//功能：去除给定数据重复元素
//输入参数：	arr		待处理数组、
//			n		数组元素个数
//返回值：	类型		整形（int）
//			表示处理后数组元素个数
//修改记录：
//
//
//==========================================================================================================================================
int denum(int arr[], int n)
{
	int i, j, m = 0, flag = 1;
	//for (int o = 0; o < n; o++)	printf("%d\n", arr[o]);
	//int *tmp=(int *)malloc(n*sizeof(int));
	int tmp[10];
	for (i = 0; i < n; i++)//arr[i]
	{
		for (j = 0, flag = 1; j < m; j++)
		{
			if (tmp[j] == arr[i])
			{
				flag = 0;
			}

		}
		if (flag)
		{
			tmp[m++] = arr[i];
			//printf("\ntmp[%d++]=arr[%d]=%d", m, i,arr[i]);
		}

	}

	for (i = 0; i < m; i++)
	{
		arr[i] = tmp[i];
	}
	//free(tmp);
	return m;
}

//==========================================================================================================================================
//函数名：iscf
//作者：张博强
//日期：2016.04.27
//功能：判断给定数组元素是否存在重复元素
//输入参数：	arr		待处理数组、
//			n		数组元素个数
//返回值：	类型		整形（int）
//			1：存在重复元素，2：不存在重复元素
//修改记录：
//
//
//==========================================================================================================================================
int iscf(int arr[], int n)
{
	int i, m;
	for (i = 0; i < n; i++)
		for (m = i + 1; m < n; m++)
			if (arr[i] == arr[m])
				return 1;
	return 0;
}

//==========================================================================================================================================
//函数名：gxfh
//作者：范守峰
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
//==========================================================================================================================================
int gxfh(int a[], int ai, int b[], int bi, int obj[])
{

	int i, n, m = 0, o;
	int flag = 0;

	for (i = 1; i < 2 * ai; i += 2)
	{
		for (n = 0; n < 2 * bi; n += 2)
		{
			if (a[i] == b[n])
			{
				for (o = 0; o < m; o = o + 2)
				{
					if (a[i - 1] == obj[o] && b[n + 1] == obj[o + 1])
					{
						flag = 1;
						break;
					}
				}
				if (flag != 1)
				{
					obj[m] = a[i - 1];
					obj[m + 1] = b[n + 1];
					m += 2;
				}
				flag = 0;
			}
		}

	}
	return m / 2;
}

//==========================================================================================================================================
//函数名：inversion
//作者：王妍
//日期：2016.05.04
//功能：对给定两个关系进行关系复合运算
//输入参数：	org		原始数据
//			obj		目标数组
//			count	原始数据关系数目
//返回值：	类型		整形（int）
//					表示运算结果所包含关系个数
//			错误代码：-1		数据错误
//					  1		数据大概没错
//			
//修改记录：
//
//
//==========================================================================================================================================
int inversion(int org[], int obj[], int count)
{
	int i;
	for (i = 0; i < 2 * count; i += 2)
	{
		obj[i + 1] = org[i];
		obj[i] = org[i + 1];
	}
	if (count < 0)
		return -1;
	return 1;
}

//==========================================================================================================================================
//函数名：equalClassNew
//作者：张博强
//日期：2016.05.04
//功能：对给定两个关系进行关系复合运算
//输入参数：	arr			原始数据
//			quanyity	原始数据关系数目
//			n			模n同余
//			meo			目标数组
//返回值：	类型		整形（int）
//					无意义
//			
//修改记录：
//
//
//==========================================================================================================================================
int equalclassNew(int arr[], int quantity, int n, int meo[100][100])
{
	for (int i = 0; i < quantity; i++)
		meo[(arr[i]) % n][1 + (meo[(arr[i]) % n][0]++)] = arr[i];
	return 1;
}