#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include<Windows.h>

extern int DEBUG_MODE;
extern int gameFlag;
void gotoxy(int x, int y);



void uiselect(int, int);

using namespace std;
void gotoxy(int x, int y)

{
	COORD pos;

	pos.X = (gameFlag +1)* x;

	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int ui(int sele)
{
	int i = 0, ch;
	uiselect(0, 0);
	while (ch = _getch(), ch != '\n')
	{
		if (ch == 0)
			ch = _getch();
		if (ch == 72)
		{
			if (--i < 1) i = 8;
			uiselect(i, 1);
		}
		if (ch == 80)
		{
			if (++i > 8) i = 1;
			uiselect(i, 1);
		}
	}


	switch (i)
	{
	case 0:
		uiselect(0, 2);
		cout << "��ϵ�Ĵ洢���ģ��";
		break;
	case 1:
		uiselect(0, 2);
		cout << "�ѿ����˻����ģ��";
		break;
	case 2:
		uiselect(0, 2);
		cout << "��ϵ�������ģ��";
		break;
	case 3:
		uiselect(0, 2);
		cout << "��ϵ�հ����ģ��";
		break;
	case 4:
		uiselect(0, 2);
		cout << "�ȼ۹�ϵ���ģ��";
		break;
	case 5:
		uiselect(0, 2);
		cout << "ƫ���ϵ���ģ��";
		break;
	case 6:
		uiselect(0, 3);
		break;
	case 7:
		uiselect(0, 2);
		
		break;
	}






	return 0;
}

void uiselect(int item, int cl)
{
	if (cl == 1) system("cls");
	if (cl == 2)
	{
		system("cls");
		return;
	}
	cout << "��ɢ��ѧʵ����" << endl;
	cout << "By ȷ����ʽ��" << endl;
	cout << "Version: 0.1" << endl << endl;
	cout << "=================================================================" << endl << endl;

	switch (item)
	{
	case 0:
	{
		cout << "            ��ϵ�Ĵ��漰�������㣨���������" << endl;
		cout << "                    �ѿ����˻�����" << endl;
		cout << "                   ��ϵ���ϡ����ϵ" << endl;
		cout << "              ��ϵ�հ����Է����Գơ����ݣ�" << endl;
		cout << "                     �ȼ۹�ϵ�ж�" << endl;
		cout << "                     ƫ���ϵ�ж�" << endl << endl;
		cout << "                         ����" << endl;
		cout << "                         �˳�" << endl << endl;
		break;
	}
	case 1:
	{
		cout << "            \033[7m��ϵ�Ĵ��漰�������㣨���������\033[0m" << endl;
		cout << "                    �ѿ����˻�����" << endl;
		cout << "                   ��ϵ���ϡ����ϵ" << endl;
		cout << "              ��ϵ�հ����Է����Գơ����ݣ�" << endl;
		cout << "                     �ȼ۹�ϵ�ж�" << endl;
		cout << "                     ƫ���ϵ�ж�" << endl << endl;
		cout << "                         ����" << endl;
		cout << "                         �˳�" << endl << endl;
		break;
	}
	case 2:
	{
		cout << "            ��ϵ�Ĵ��漰�������㣨���������" << endl;
		cout << "                    \033[7m�ѿ����˻�����\033[0m" << endl;
		cout << "                   ��ϵ���ϡ����ϵ" << endl;
		cout << "              ��ϵ�հ����Է����Գơ����ݣ�" << endl;
		cout << "                     �ȼ۹�ϵ�ж�" << endl;
		cout << "                     ƫ���ϵ�ж�" << endl << endl;
		cout << "                         ����" << endl;
		cout << "                         �˳�" << endl << endl;
		break;
	}
	case 3:
	{
		cout << "            ��ϵ�Ĵ��漰�������㣨���������" << endl;
		cout << "                    �ѿ����˻�����" << endl;
		cout << "                   \033[7m��ϵ���ϡ����ϵ\033[0m" << endl;
		cout << "              ��ϵ�հ����Է����Գơ����ݣ�" << endl;
		cout << "                     �ȼ۹�ϵ�ж�" << endl;
		cout << "                     ƫ���ϵ�ж�" << endl << endl;
		cout << "                         ����" << endl;
		cout << "                         �˳�" << endl << endl;
		break;
	}
	case 4:
	{
		cout << "            ��ϵ�Ĵ��漰�������㣨���������" << endl;
		cout << "                    �ѿ����˻�����" << endl;
		cout << "                   ��ϵ���ϡ����ϵ" << endl;
		cout << "              \033[7m��ϵ�հ����Է����Գơ����ݣ�\033[0m" << endl;
		cout << "                     �ȼ۹�ϵ�ж�" << endl;
		cout << "                     ƫ���ϵ�ж�" << endl << endl;
		cout << "                         ����" << endl;
		cout << "                         �˳�" << endl << endl;
		break;
	}
	case 5:
	{
		cout << "            ��ϵ�Ĵ��漰�������㣨���������" << endl;
		cout << "                    �ѿ����˻�����" << endl;
		cout << "                   ��ϵ���ϡ����ϵ" << endl;
		cout << "              ��ϵ�հ����Է����Գơ����ݣ�" << endl;
		cout << "                     \033[7m�ȼ۹�ϵ�ж�\033[0m" << endl;
		cout << "                     ƫ���ϵ�ж�" << endl << endl;
		cout << "                         ����" << endl;
		cout << "                         �˳�" << endl << endl;
		break;
	}

	case 6:
	{
		cout << "            ��ϵ�Ĵ��漰�������㣨���������" << endl;
		cout << "                    �ѿ����˻�����" << endl;
		cout << "                   ��ϵ���ϡ����ϵ" << endl;
		cout << "              ��ϵ�հ����Է����Գơ����ݣ�" << endl;
		cout << "                     �ȼ۹�ϵ�ж�" << endl;
		cout << "                     \033[7mƫ���ϵ�ж�\033[0m" << endl << endl;
		cout << "                         ����" << endl;
		cout << "                         �˳�" << endl << endl;
		break;
	}


	case 7:
	{
		cout << "            ��ϵ�Ĵ��漰�������㣨���������" << endl;
		cout << "                    �ѿ����˻�����" << endl;
		cout << "                   ��ϵ���ϡ����ϵ" << endl;
		cout << "              ��ϵ�հ����Է����Գơ����ݣ�" << endl;
		cout << "                     �ȼ۹�ϵ�ж�" << endl;
		cout << "                     ƫ���ϵ�ж�" << endl << endl;
		cout << "                         \033[7m����\033[0m" << endl;
		cout << "                         �˳�" << endl << endl;
		break;
	}

	case 8:
	{
		cout << "            ��ϵ�Ĵ��漰�������㣨���������" << endl;
		cout << "                    �ѿ����˻�����" << endl;
		cout << "                   ��ϵ���ϡ����ϵ" << endl;
		cout << "              ��ϵ�հ����Է����Գơ����ݣ�" << endl;
		cout << "                     �ȼ۹�ϵ�ж�" << endl;
		cout << "                     ƫ���ϵ�ж�" << endl << endl;
		cout << "                         ����" << endl;
		cout << "                         \033[7m�˳�\033[0m" << endl << endl;
		break;
	}


	}	printf("=================================================================\n");

}
