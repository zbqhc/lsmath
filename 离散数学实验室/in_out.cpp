#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

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
int inputdata(int arr[], int count, int mode)		//1:jihe		2:guanxi
{
	int key = -1, num[10], n = 0, flag = 1, m, pow = 1, u, i, cn = 10;
	for (i = 0; i < count; i++)		arr[i] = 0;
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
			else if (key = 10 && mode == 2)
			{
				flag = 0;
				break;
			}

			if (cn == count + 10)		break;

		}
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
		if (mode == 1 && i > count - 2)
		{
			break;
		}
	}
	if (mode == 1)	cout << "}";
	system("cls");


	if (mode == 2)	cout << "input " << i - 1 << " zhu data:" << endl;
	if (mode == 1)	cout << "input " << count << " ge yuanshu:" << endl << "{";

	for (u = 0; u < (i - 1) * mode + (4 - 2 * mode); u += mode)
	{

		if (mode == 2)	cout << "<" << arr[u] << "," << arr[u + 1] << ">\t";
		if (mode == 1)	cout << arr[u] << ",";
	}
	if (mode == 1)	cout << "\b}";
	cout << endl;

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





int msgbox(char title[], char text[], int W, int H, int mode)
{
	system("cls");
	int i, m, u, r = 0, ch, s = 1;
	int mainlen = strlen(text);
	int max = W - 4;
	int strrr = 0;
	int w = strlen(title);
	//w-=w/3;
	//printf("%d %d\n",w,t);
	if ((w % 2) + (W % 2) == 1)
		W--;
	printf("\n\n\t\033[47;30m");
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
		printf("\033[0m\n\t\033[47;30m║");
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

	printf("\033[0m\n\t\033[47;30m╚");
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
			if (ch == 75)
			{
				printf("\033[0m\r\t\033[47;30m╚");
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
				printf("\033[0m\r\t\033[47;30m╚");
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
				printf("\033[0m\r\t\033[47;30m╚");
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
				printf("\033[0m\r\t\033[47;30m╚");
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

		printf("\n%d", s);
		break;

	}
	printf("\033[0m\n");
	return 0;
}

