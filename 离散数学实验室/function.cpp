#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>

int denum(int[], int);
int iscf(int[], int);

extern int DEBUG_MODE;

using namespace std;



//==========================================================================================================================================
//函数名：dker
//作者：确定格式化
//日期：2016.04.18
//功能：计算两个集合笛卡尔乘积
//输入参数：	lsa：	集合a
//			lsaa：	集合a元素个数
//			lsb：	集合b
//			lsb：	集合b元素个数
//			debug：	调试模式，1：允许，0：禁用
//返回值：	运行正常：1，参数错误：0
//修改记录：
//
//
//
//==========================================================================================================================================
int dker(int lsa[], int lsaa, int lsb[], int lsbb, int obj[], int debug)
{
	int o, p;
	if (lsaa <= 0 || lsbb <= 0)
		return 0;
	for (o = 0; o < lsaa; o++)
		for (p = 0; p < lsbb; p++)
		{
			if (debug)
				printf("<%d,%d>\t", lsa[o], lsb[p]);
			obj[2 * (o*lsbb + p)] = lsa[o];
			obj[2 * (o*lsbb + p) + 1] = lsb[p];
		}

	return 1;
}


//==========================================================================================================================================
//函数名：isin
//作者：确定格式化
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
//作者：确定格式化
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
//作者：确定格式化
//日期：2016.04.26
//功能：对给定关系集合进行分析是否满足自反、对称以及传递，并分别返回其自反、对称、传递闭包
//输入参数： org		传入集合数组
//			a		集合数组元素个数
//			arr		传入关系数组
//			n		关系数组元素个数
//返回值：	类型		整形（int）
//			末位数字：当满足自反记 4，对称记 2，传递记 1，末位即为关系满足情况加和，均未满足为0
//			高位数字：十万百万位为自反闭包数目，千位万位为对称闭包个数，百位十位为传递闭包格式
//			错误代码：-1		内存申请失败
//					 -2		数据错误
//修改记录：
//
//
//
//==========================================================================================================================================
int lsmath(int org[], int a, int arr[], int n)
{
	int count_zf = 0, count_dc = 0, count_cd = 0; //闭包计数变量
	int i, o, p, x, y, t, k = 1;
	int re = 0;
	int flag = 0, flag2 = 0;

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
	if (DEBUG_MODE)
	{
		printf("关系矩阵：\n");
		for (i = 0; i < a; i++)
		{
			if (i == 0)
			{
				printf("    ");
				for (o = 0; o < a; o++)
					printf("   \033[4m%d\033[0m", org[o]);
				printf("\n    ┌");
				for (o = 0; o < a - 1; o++)
					printf("─┬");
				printf("─┐\n   \033[4m%d\033[m│", org[i]);


			}
			for (o = 0; o < a; o++)
			{
				if (tp[i][o]==1)
					printf(" \033[41m%d\033[0m│", tp[i][o]);
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
					printf("\n  \033[4m%d\033[m│", org[i + 1]);
				else
					printf("\n   \033[4m%d\033[m│", org[i + 1]);
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
			}
			o++;
		}
		if (flag == 0)
		{
			re += 2;
		}

		flag = 0;
	}

	//判断传递==================================================================================================
	{
		for (i = 0; i < a; i++)//hang
		{
			for (p = 0; p < a; p++)//lie
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
	re += count_zf * 100000 + count_dc * 1000 + count_cd * 10;


	return re;


}


//==========================================================================================================================================
//函数名：base
//作者：确定格式化
//日期：2016.04.27
//功能：对给定两个集合进行基本运算
//输入参数：	a		第一个集合
//			ai		第一个集合元素个数
//			b		第二个集合
//			bi		第二个集合元素个数
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
	int i,j, u, flag = 0, f = 0;
	if (iscf(a, ai) + iscf(b, bi) > 0)
		return -1;

	switch (mode)
	{
	case 1:
		for (i = 0; i < ai; i++)
			obj[i] = a[i];
		for (j=0; j < bi; j++)
			obj[i+j] = b[j];
		flag = denum(obj, ai + bi);
		
		break;
	case 2:
		for (i = 0; i < ai; i++)
		{
			for (u = 0; u < bi; u++)
			{
				if (a[i] == b[u])
				{
					obj[flag++] = a[i];
					break;
				}
			}
		}
		break;
	case 3:
		for (i = 0; i < ai; i++, f = 0)
		{
			for (u = 0; u < bi; u++)
			{
				if (a[i] == b[u])
				{
					f = 1;
					break;
				}
			}
			if (f == 0)
				obj[flag++] = a[i];
		}
	}
	return flag;
}


//==========================================================================================================================================
//函数名：denum
//作者：确定格式化
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
	int i,j,m=0,flag=1;
	//for (int o = 0; o < n; o++)	printf("%d\n", arr[o]);
	//int *tmp=(int *)malloc(n*sizeof(int));
	int tmp[10];
	for (i = 0; i < n; i++)//arr[i]
	{
		for (j = 0,flag = 1; j < m; j++)
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
//作者：确定格式化
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
//==========================================================================================================================================
int gxfh(int a[], int ai, int b[], int bi, int obj[])
{
	int i, o, p = 0, m, flag = 0;
	int counter = 0;
	int *tmp;

	tmp = (int *)malloc(2 * ai * sizeof(int));

	if (tmp == NULL)
		return -1;

	for (i = 1; i < 2 * ai; i += 2)
		for (o = 0; o < 2 * bi; o += 2)
			if (a[i] == b[o])
				if (a[i - 1] == b[o + 1])
				{
					for (m = 0; m < p; m++)
					{
						if (a[i - 1] = tmp[m])
						{
							m = p;//esc
							flag = 1;
						}
					}
					if (flag == 0)
					{
						tmp[p++] = a[i - 1];
						obj[counter++] = a[i - 1];
						obj[counter++] = b[o + 1];
					}
					flag = 0;
				}
				else
				{
					obj[counter++] = a[i - 1];
					obj[counter++] = b[o + 1];
				}

	return counter;
}



int analysisEqualClass(int dataInput[], int amountInput, int dataOutput[])
{
	dataOutput = (int *)malloc(amountInput * sizeof(int));
	for (int i = 0; i<amountInput; i++)
		dataOutput[i] = dataInput[i];
	amountInput = denum(dataOutput, amountInput);
	csort(dataOutput, amountInput, -1);
	free(dataOutput);
	return amountInput;
}
