#include"lsmath.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>

extern int selectItem(int);
extern int setting(void);

extern int msgbox(char title[], char text[], int x, int y, int W, int H, int mode, int counter, ...);
extern void loginui(void);
extern int inputdata(int[], int);
extern int outputdata(int[], int, int);
extern int lsbaseWindows(void);

int showItem(int x, int y, int w, int select, int quantity, ...);
int mej(int xxx,int smax, int sele, int *quickKey);

extern int base(int[], int, int[], int, int[], int);


int mej(int xxx,int smax, int sele, int *quickKey)
{
	int key, flag = 1;
	while (flag)
	{
		key = _getch();
		if (key == 224)
		{
			key = _getch();
			if (key == 72)
			{
				sele--;
				if (sele == 0)
					sele = smax;
				flag = 0;
			}
			if (key == 80)
			{
				sele++;
				if (sele == smax + 1)
					sele = 1;
				flag = 0;
			}
		}
		////////////////////////////////////////

		switch (key)
		{

		case 48 + 1:
			sele = 1;
			*quickKey = 1;
			flag = 0;
			break;
		case 48 + 2:
			if (key - 48 < smax)
				sele = 2;
			else
				sele = smax;
			*quickKey = 1;
			flag = 0;
			break;
		case 48 + 3:
			if (key - 48 < smax)
				sele = 3;
			else
				sele = smax;
			*quickKey = 1;
			flag = 0;
			break;
		case 48 + 4:
			if (key - 48 < smax)
				sele = 4;
			else
				sele = smax;
			*quickKey = 1;
			flag = 0;
			break;
		case 48 + 5:
			if (key - 48 < smax)
				sele = 5;
			else
				sele = smax;
			*quickKey = 1;
			flag = 0;
			break;
		case 48 + 6:
			if (key - 48 < smax)
				sele = 6;
			else
				sele = smax;
			*quickKey = 1;
			flag = 0;
			break;
		case 48 + 7:
			if (key - 48 < smax)
				sele = 7;
			else
				sele = smax;
			*quickKey = 1;
			flag = 0;
			break;
		case 48 + 8:
			if (key - 48 < smax)
				sele = 8;
			else
				sele = smax;
			*quickKey = 1;
			flag = 0;
			break;
		case 48 + 9:
			if (key - 48 < smax)
				sele = 9;
			else
				sele = smax;
			*quickKey = 1;
			flag = 0;
			break;
		case 27:
			sele = -1;
			flag = 0;
			break;
		case 13:
			sele = xxx + sele;
			flag = 0;
			break;
		}

	}
	return sele;
}


int dealMenu(int n)
{
	static int item;
	int mark = 1, lastMark = 1, keyMark = 0;
	int sele, smax;
	HWND hwnd = GetForegroundWindow();
	switch (n)
	{
	case 1000:
		smax = 4;
		mark = 1;
		showItem(0, 2, 75, mark, smax, "����ʵ����", "��ȡ����", "�����Ŷ�", "�뿪ʵ����");
		while (1)
		{
			lastMark = mark;
			mark = mej(10,4, mark, &keyMark);
			if (mark > 10)
				break;
			if (keyMark == 1)
			{
				showItem(0, 2, 75, mark, smax, "����ʵ����", "��ȡ����", "�����Ŷ�", "�뿪ʵ����");
				return 10 + mark;
			}

			else if (mark == -1)
			{
				if (msgbox("��ʾ", "�����Ҫ�뿪ʵ����ô", 12, 5, 50, 8, LS_YESNO, 0) == 1)
					exit(0);
				loginui();
				mark = lastMark;
			}
			showItem(0, 2, 75, mark, smax, "����ʵ����", "��ȡ����", "�����Ŷ�", "�뿪ʵ����");
		}
		break;

	case 11:
		
		SetWindowTextA(hwnd, "��ɢ��ѧʵ���� - ���˵�");
		smax = 8;
		mark = 1;
		showItem(0, 2, 75, mark, smax, "��ϵ�Ļ�������", "�ѿ����˻�����", "�жϹ�ϵ�հ�", "��ϵ��������", "�жϵȼ۹�ϵ", "�ж�ƫ���ϵ", "�����ȼ���", "���ϵ����");

		while (1)
		{
			lastMark = mark;
			mark = mej(110,8, mark, &keyMark);
			
			if (mark > 100)
				break;
			if (keyMark == 1)
			{
				showItem(0, 2, 75, mark, smax, "��ϵ�Ļ�������", "�ѿ����˻�����", "�жϹ�ϵ�հ�", "��ϵ��������", "�жϵȼ۹�ϵ", "�ж�ƫ���ϵ", "�����ȼ���", "���ϵ����");

				return 110 + mark;
			}

			else if (mark == -1)
			{
				return 1000;
			}
			showItem(0, 2, 75, mark, smax, "��ϵ�Ļ�������", "�ѿ����˻�����", "�жϹ�ϵ�հ�", "��ϵ��������", "�жϵȼ۹�ϵ", "�ж�ƫ���ϵ", "�����ȼ���", "���ϵ����");

		}

		break;
	case 12:
		SetWindowTextA(hwnd, "��ɢ��ѧʵ���� - ��ȡ����");
		smax = 8;
		mark = 1;
		showItem(0, 2, 75, mark, smax, "��ϵ�Ļ�������.TXT", "�ѿ����˻�����.TXT", "�жϹ�ϵ�հ�.TXT", "��ϵ��������.TXT", "�жϵȼ۹�ϵ.TXT", "�ж�ƫ���ϵ.TXT", "�����ȼ���.TXT", "���ϵ����.TXT");

		while (1)
		{
			lastMark = mark;
			mark = mej(120,8, mark, &keyMark);
			
			if (mark > 100)
				break;
			if (keyMark == 1)
			{
				showItem(0, 2, 75, mark, smax, "��ϵ�Ļ�������.TXT", "�ѿ����˻�����.TXT", "�жϹ�ϵ�հ�.TXT", "��ϵ��������.TXT", "�жϵȼ۹�ϵ.TXT", "�ж�ƫ���ϵ.TXT", "�����ȼ���.TXT", "���ϵ����.TXT");

				return 120 + mark;
			}

			else if (mark == -1)
			{
				return 1000;
			}
			showItem(0, 2, 75, mark, smax, "��ϵ�Ļ�������.TXT", "�ѿ����˻�����.TXT", "�жϹ�ϵ�հ�.TXT", "��ϵ��������.TXT", "�жϵȼ۹�ϵ.TXT", "�ж�ƫ���ϵ.TXT", "�����ȼ���.TXT", "���ϵ����.TXT");

		}

		break;


	}
	return mark;

}


