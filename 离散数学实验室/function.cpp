#include"lsmath.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<Windows.h>

int denum(int[], int);
int iscf(int[], int);
extern void gotoxy(int x, int y);



using namespace std;



//==========================================================================================================================================
//��������dker
//���ߣ�ȷ����ʽ��
//���ڣ�2016.04.18
//���ܣ������������ϵѿ����˻�
//���������	lsa��	����a
//			lsaa��	����aԪ�ظ���
//			lsb��	����b
//			lsbb��	����bԪ�ظ���
//			obj:	Ŀ������
//			debug��	����ģʽ��1������0������
//����ֵ��	����������1����������0
//�޸ļ�¼��
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
//��������isin
//���ߣ�ȷ����ʽ��
//���ڣ�2016.04.25
//���ܣ��ж�ĳԪ���Ƿ������ĳ����
//���������	arr��	Ŀ������
//			n��		����Ԫ�ظ���
//			num��	���ж�����
//����ֵ��	���ڣ�1�������ڣ�0
//�޸ļ�¼��
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
//��������csort
//���ߣ�ȷ����ʽ��
//���ڣ�2016.04.25
//���ܣ��Ը������ݽ��дӴ�С���С��������
//��������� p��		������ģ�һά������
//          cou:	���ݸ���
//			mode��	����ģʽ��1������-1������
//����ֵ��	����������1����������-1
//�޸ļ�¼��
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
//��������lsmath
//���ߣ�ȷ����ʽ��
//���ڣ�2016.04.26
//���ܣ��Ը�����ϵ���Ͻ��з����Ƿ������Է����Գ��Լ����ݣ����ֱ𷵻����Է����Գơ����ݱհ�
//��������� org					���뼯������
//			a					��������Ԫ�ظ���
//			arr					�����ϵ����
//			n					��ϵ����Ԫ�ظ���
//			debug_mode_run		����ģʽ����
//����ֵ��	����		���Σ�int��
//			ĩλ���֣��������Է��� 4���ԳƼ� 2�����ݼ� 1��ĩλ��Ϊ��ϵ��������Ӻͣ���δ����Ϊ0
//			���ڶ�λ��1�����Է�	2�����Գ�	3��ͬʱ���㷴�Է������Գ�
//			��λ���֣�ǧ��λ����λΪ�Է��հ���Ŀ��ʮ��λ��λΪ�ԳƱհ�������ǧλ��λΪ���ݱհ���ʽ
//			������룺-1		�ڴ�����ʧ��
//					 -2		���ݴ���
//�޸ļ�¼��
//
//
//
//==========================================================================================================================================
int lsmath(int org[], int a, int arr[], int n, int debug_mode_run)
{
	int count_zf = 0, count_dc = 0, count_cd = 0; //�հ���������
	int i, o, p, x, y, t, k = 1;
	int re = 0;
	int flag = 0, flag2 = 0, flag3 = 0;

	HANDLE hOut;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	csort(org, a, 1);



	//���ɹ�ϵ����========================Create the relational matrix=======================================================================

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




	//����ģʽ============================DEBUG Mode======================================================================
	if (DEBUG_MODE || debug_mode_run)
	{
		printf("\n\n��ϵ����\n");
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
				printf("\n    ��");
				for (o = 0; o < a - 1; o++)
					printf("����");
				printf("����\n  ");
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
				printf(" ��");


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
					printf("��");
				}
				else
					printf(" %d��", tp[i][o]);

			}
			if (i != a - 1)
			{
				printf("\n    ��");
				for (o = 0; o < a - 1; o++)
					printf("����");
				printf("����");
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
					printf(" ��");
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
					printf(" ��");
				}
			}
			else
			{
				printf("\n    ��");
				for (o = 0; o < a - 1; o++)
					printf("����");
				printf("����\n");
			}
		}
	}
	//�ж��Է�============================ZIFAN Analysis======================================================================
	{
		for (i = 0; i < a; i++)
		{
			if (tp[i][i] == 0)
			{
				flag = 1;
				count_zf++;
			}
		}
		if (count_zf == a)//���Է�
			re += 10;
		if (flag == 0)
		{
			re += 4;
		}

		flag = 0;
	}

	//�ж϶Գ�============================DUICHEN Analysis======================================================================
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
			o++;
		}

		if (flag == 1 && flag3 == 0)
			re += 20;
		if (flag == 0)
		{
			re += 2;
		}

		flag = 0;
	}

	//�жϴ���==================================================================================================
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

	//������==================================================================================================
	re += count_zf * 1000000 + count_dc * 10000 + count_cd * 100;


	if (DEBUG_MODE || debug_mode_run)
		printf("\n����ԭʼ����Ϊ��%d", re);
	return re;


}


//==========================================================================================================================================
//��������base
//���ߣ�ȷ����ʽ��
//���ڣ�2016.04.27
//���ܣ��Ը����������Ͻ��л�������
//���������	a		��һ����ϵ
//			ai		��һ����ϵԪ�ظ���
//			b		�ڶ�����ϵ
//			bi		�ڶ�����ϵԪ�ظ���
//			obj		����������Ŀ��
//			mode	����ģʽ��1	�������㣬2 �������㣬3 ����㣨a��b��
//����ֵ��	����		���Σ�int��
//					��ʾ������������Ԫ�ظ���
//			������룺-1		�������ݴ���
//�޸ļ�¼��
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
//��������denum
//���ߣ�ȷ����ʽ��
//���ڣ�2016.04.26
//���ܣ�ȥ�����������ظ�Ԫ��
//���������	arr		���������顢
//			n		����Ԫ�ظ���
//����ֵ��	����		���Σ�int��
//			��ʾ���������Ԫ�ظ���
//�޸ļ�¼��
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
//��������iscf
//���ߣ�ȷ����ʽ��
//���ڣ�2016.04.27
//���ܣ��жϸ�������Ԫ���Ƿ�����ظ�Ԫ��
//���������	arr		���������顢
//			n		����Ԫ�ظ���
//����ֵ��	����		���Σ�int��
//			1�������ظ�Ԫ�أ�2���������ظ�Ԫ��
//�޸ļ�¼��
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
//��������gxfh
//���ߣ�ȷ����ʽ��
//���ڣ�2016.04.03
//���ܣ��Ը���������ϵ���й�ϵ��������
//���������	a		��һ���ϵ
//			ai		��һ���ϵ����
//			b		�ڶ����ϵ
//			bi		�ڶ����ϵ����
//			obj		��ϵ����������Ŀ��
//����ֵ��	����		���Σ�int��
//					��ʾ������������Ԫ�ظ���
//			������룺-1		�ڴ����ʧ��
//					  0		��ϵ����������Ϊ��
//			
//�޸ļ�¼��
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
	//dataOutput = (int *)malloc(amountInput * sizeof(int));
	for (int i = 0; i < amountInput; i++)
		dataOutput[i] = dataInput[i];
	amountInput = denum(dataOutput, amountInput);
	csort(dataOutput, amountInput, 1);
	//free(dataOutput);
	return amountInput;
}

//==========================================================================================================================================
//��������inversion
//���ߣ�ȷ����ʽ��
//���ڣ�2016.05.04
//���ܣ��Ը���������ϵ���й�ϵ��������
//���������	org		ԭʼ����
//			obj		Ŀ������
//			count	ԭʼ���ݹ�ϵ��Ŀ
//����ֵ��	����		���Σ�int��
//					��ʾ��������������ϵ����
//			������룺-1		���ݴ���
//					  1		���ݴ��û��
//			
//�޸ļ�¼��
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




int equalclassNew(int arr[], int quantity, int n, int meo[100][100])
{

	int i, k = 1;
	for (i = 0; i < quantity; i++)
		meo[(arr[i]) % n][1 + (meo[(arr[i]) % n][0]++)] = arr[i];
	return 1;
}