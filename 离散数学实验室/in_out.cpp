#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

using namespace std;

extern void gotoxy(int, int);
extern void loginui(void);

//==========================================================================================================================================
//函数名：inputdata
//作者：确定格式化
//日期：2016.04.25
//功能：格式化输入集合或关系
//输入参数： arr：		输入函数目标（一维）数组
//			count：	待输入的元素的个数
//			mode：	集合|关系输入模式，1：输入集合，2：输入关系
//返回值：	类型		整形（int）
//			返回输入关系的对数（仅当mode为2时返回值有意义）
//修改记录：
//
//
//
//==========================================================================================================================================
int inputdata(int arr[], int mode)		//1:jihe		2:guanxi
{
	int key = -1, num[10], n = 0, flag = 1, m, pow = 1, u, i, cn = 10,cjh=0;
	//for (i = 0; i < count; i++)		arr[i] = 0;
	if (mode == 1)	cout << "{";
	for (i = 0; i < 150 && flag; i++)
	{
		if (mode == 2)	cout << "<";

		for (u = 0; u < 10; u++)
			num[u] = -1;

		pow = 1;
		key = -1;
		n = 0;
		while (flag)
		{
			key = _getch();
			////////////////beta
			if (key == 8)
			{
				printf("\b \b");
				n--;/////////////beta
			}else
			if (key > 47 && key < 58)
			{
				flag = 2;
				num[n++] = key - 48;
				cout << key - 48;

			}
			else if (flag > 1)
			{
				cout << ",";
				break;
			}
			else if (key = 10)
			{
				flag = 0;
				break;
			}

			//if (cn == count + 10)		break;

		}
		cjh++;
		if (flag == 2)		flag = 1;
		for (m = 0, pow = 1; m < n; m++)
		{
			if (mode == 2)		arr[2 * i] += num[n - m - 1] * pow;
			if (mode == 1)		arr[i] += num[n - m - 1] * pow;
			pow *= 10;
		}
		if (mode == 2)
		{
			key = -1;

			n = 0;
			for (u = 0; u < 10; u++)
				num[u] = -1;
			while (flag)
			{
				key = _getch();
				////////////////beta
				if (key == 8)
				{
					printf("\b \b");
					n--;/////////////beta
				}
				else
				if (key > 47 && key < 58)
				{
					flag = 2;
					num[n++] = key - 48;
					cout << key - 48;
				}
				else if (flag > 1)
				{
					if (mode == 2)	cout << ">" << endl;
					if (mode == 1)	cout << ",";
					break;

				}

			}
		}

		if (flag == 2)		flag = 1;

		if (mode == 2)
		{

			for (m = 0, pow = 1; m < n; m++)
			{
				arr[2 * i + 1] += num[n - m - 1] * pow;
				pow *= 10;
			}

		}
		/*if (mode == 1 && i > count - 2)
		{
			break;
		}*/
	}
	if (mode == 1)	cout << "}";
	
	loginui();
	
	/*if (mode == 2)
	{
		gotoxy(0, 2);
		cout << "第  组集合数据：" << endl;
	}
	if (mode == 1)	cout <<  "组关系" << endl << "{";

	for (u = 0; u < (i - 1) * mode + (4 - 2 * mode) && mode==2; u += mode)
	{

			cout << "<" << arr[u] << "," << arr[u + 1] << ">\t";
			
	}
	for (u = 0; u < cjh-1 && mode == 1; u ++)
	{

		
		cout << arr[u] << ",";
	}
	if (mode == 1)	cout << "\b}";
	cout << endl;*/
	return i - 1;
}

int outputdata(int arr[], int count, int mode)
{
	int i,flag=0;

	if (mode == 1)
		cout << "{";
	else
	{

	}


	for (i = 0; i < count*mode; i += mode)
	{
		flag = 1;
		if (mode == 1)
			cout << arr[i] << ",";
		else
			cout << "<" << arr[i] << "," << arr[i + 1] << "> ";
	}
	if (mode == 1)
		if (flag)
			cout << "\b}";
		else
			cout << "\b空集";

	return count*mode;
}

int msgbox(char title[], char text[],int x,int y, int W, int H, int mode,int counter,...)
{
	int *arr = (int *)malloc((counter+1) * sizeof(int));
	
	int i, m, u, r = 0, ch, s = 1;
	int mainlen = strlen(text);
	int max = W - 4;
	int strrr = 0;
	int w = strlen(title);
	int xnumber = 1;

	va_list number;
	va_start(number, counter);
	for (i = 1; i < counter+1; i++)
	{
		arr[i] = va_arg(number, int);
	}
	va_end(number);
	if ((w % 2) + (W % 2) == 1)
		W--;
	gotoxy(x, y);
	printf("\033[47;30m");
	printf("╔");
	for (i = 0; i < W / 2; i++)
		printf("═");
	printf("╗");
	for (i = 1; i < (W + w) / 2 + 4; i++)
		printf("\b");
	printf(" \033[31;47m%s\033[;47m ", title);
	w = strlen(text);


	for (i = 0; i < H; i++)
	{
		gotoxy(x, ++y);
		printf("\033[0m\033[47;30m║");
		for (m = 0; m < W; m++)
			//printf("\n%d\n",strlen(title));
			printf(" ");
		printf("║");

		for (u = 0; u < W - 1; u++)
			printf("\b");


		for (r = 0; r < W - 6;)
		{
			if (strrr > w)
				break;

			if (text[strrr] <= 128)
			{
				if (text[strrr] == '%' && text[strrr + 1] == 'd')
				{
					printf("%d", arr[xnumber++]);
					strrr += 2;
					if (arr[xnumber - 1] < 10)
						r--;
					else if ((xnumber >= 100 && xnumber < 1000) || (xnumber<=-10 && xnumber>-100))
						r++;
					else if ((xnumber >= 1000 && xnumber < 10000) || (xnumber <= -100 && xnumber>-1000))
						r += 2;
					else if ((xnumber >= 10000 && xnumber < 100000) || (xnumber <= -1000 && xnumber>-10000))
						r += 3;
					else if ((xnumber >= 100000 && xnumber < 1000000) || (xnumber <= -10000 && xnumber>-100000))
						r += 4;
					else if ((xnumber >= 1000000 && xnumber < 10000000) || (xnumber <= -100000 && xnumber>-1000000))
						r += 5;
				}
				else
					printf("%c", text[strrr++]);
				r++;
			}
			else
			{
				printf("%c%c%c", text[strrr++], text[strrr++], text[strrr++]);
				r += 2;
			}
		}

	}
	gotoxy(x,++y);
	printf("\033[0m\033[47;30m╚");
	for (i = 0; i < W / 2; i++)
		printf("═");
	printf("╝");


	switch (mode)
	{

	case 1:
	{
		for (i = 0; i < (W - 16) / 3 + 8; i++)
			printf("\b");
		printf(" [ 否 ] ");

		for (i = 0; i < ((W - 16) / 3 + 6) * 2; i++)
			printf("\b");
		printf("\033[37;44m [ 是 ] \033[0m");



		while (ch = _getch(), ch != 13)
		{
			if (ch == 0)
				ch = _getch();
			else if (ch == 27)
				return 2;
			else if (ch==121)
			{
				return 1;

			}
			else if (ch==110)
			{
				return 2;
			}
			if (ch == 75)
			{
				gotoxy(x,  y);
				printf("\033[0m\033[47;30m╚");
				for (i = 0; i < W / 2; i++)
					printf("═");
				printf("╝");
				for (i = 0; i < (W - 16) / 3 + 8; i++)
					printf("\b");
				printf(" [ 否 ] ");
				for (i = 0; i < ((W - 16) / 3 + 6) * 2; i++)
					printf("\b");
				printf("\033[37;44m [ 是 ] \033[0m");
				s = 1;
			}

			if (ch == 77)
			{
				gotoxy(x, y);
				printf("\033[0m\033[47;30m╚");
				for (i = 0; i < W / 2; i++)
					printf("═");
				printf("╝");
				for (i = 0; i < (W - 16) / 3 + 8; i++)
					printf("\b");
				printf("\033[37;44m [ 否 ] \033[0m");
				for (i = 0; i < ((W - 16) / 3 + 6) * 2; i++)
					printf("\b");
				printf("\033[47;30m [ 是 ] \033[0m");
				s = 2;
			}
			
		}


		break;
	}

	case 2:
		for (i = 0; i < (W - 16) / 3 + 8; i++)
			printf("\b");
		printf(" [忽略] ");

		for (i = 0; i < ((W - 16) / 3 + 6) * 2; i++)
			printf("\b");
		printf("\033[37;44m [终止] \033[0m");



		while (ch = _getch(), ch != 13)
		{
			if (ch == 0)
				ch = _getch();
			if (ch == 75)
			{
				gotoxy(x, y);
				printf("\033[0m\033[47;30m╚");
				for (i = 0; i < W / 2; i++)
					printf("═");
				printf("╝");
				for (i = 0; i < (W - 16) / 3 + 8; i++)
					printf("\b");
				printf(" [忽略] ");
				for (i = 0; i < ((W - 16) / 3 + 6) * 2; i++)
					printf("\b");
				printf("\033[37;44m [终止] \033[0m");
				s = 1;
			}

			if (ch == 77)
			{
				gotoxy(x, y);
				printf("\033[0m\033[47;30m╚");
				for (i = 0; i < W / 2; i++)
					printf("═");
				printf("╝");
				for (i = 0; i < (W - 16) / 3 + 8; i++)
					printf("\b");
				printf("\033[37;44m [忽略] \033[0m");
				for (i = 0; i < ((W - 16) / 3 + 6) * 2; i++)
					printf("\b");
				printf("\033[47;30m [终止] \033[0m");
				s = 2;
			}
		}

		
		break;
	case 0 :
		for (i = 0; i < (W-8)/2+10; i++)
			printf("\b");
		printf("\033[37;44m [确定] \033[0m");
		while (_getch() != 13);
		s = 1;
		break;
	default:
		break;
	}
	
	return s;
}

