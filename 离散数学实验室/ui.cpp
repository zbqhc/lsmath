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
		cout << "关系的存储相关模块";
		break;
	case 1:
		uiselect(0, 2);
		cout << "笛卡尔乘积相关模块";
		break;
	case 2:
		uiselect(0, 2);
		cout << "关系复合相关模块";
		break;
	case 3:
		uiselect(0, 2);
		cout << "关系闭包相关模块";
		break;
	case 4:
		uiselect(0, 2);
		cout << "等价关系相关模块";
		break;
	case 5:
		uiselect(0, 2);
		cout << "偏序关系相关模块";
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
	cout << "离散数学实验室" << endl;
	cout << "By 确定格式化" << endl;
	cout << "Version: 0.1" << endl << endl;
	cout << "=================================================================" << endl << endl;

	switch (item)
	{
	case 0:
	{
		cout << "            关系的储存及基本运算（交、并、差）" << endl;
		cout << "                    笛卡尔乘积运算" << endl;
		cout << "                   关系复合、逆关系" << endl;
		cout << "              关系闭包（自反、对称、传递）" << endl;
		cout << "                     等价关系判断" << endl;
		cout << "                     偏序关系判断" << endl << endl;
		cout << "                         关于" << endl;
		cout << "                         退出" << endl << endl;
		break;
	}
	case 1:
	{
		cout << "            \033[7m关系的储存及基本运算（交、并、差）\033[0m" << endl;
		cout << "                    笛卡尔乘积运算" << endl;
		cout << "                   关系复合、逆关系" << endl;
		cout << "              关系闭包（自反、对称、传递）" << endl;
		cout << "                     等价关系判断" << endl;
		cout << "                     偏序关系判断" << endl << endl;
		cout << "                         关于" << endl;
		cout << "                         退出" << endl << endl;
		break;
	}
	case 2:
	{
		cout << "            关系的储存及基本运算（交、并、差）" << endl;
		cout << "                    \033[7m笛卡尔乘积运算\033[0m" << endl;
		cout << "                   关系复合、逆关系" << endl;
		cout << "              关系闭包（自反、对称、传递）" << endl;
		cout << "                     等价关系判断" << endl;
		cout << "                     偏序关系判断" << endl << endl;
		cout << "                         关于" << endl;
		cout << "                         退出" << endl << endl;
		break;
	}
	case 3:
	{
		cout << "            关系的储存及基本运算（交、并、差）" << endl;
		cout << "                    笛卡尔乘积运算" << endl;
		cout << "                   \033[7m关系复合、逆关系\033[0m" << endl;
		cout << "              关系闭包（自反、对称、传递）" << endl;
		cout << "                     等价关系判断" << endl;
		cout << "                     偏序关系判断" << endl << endl;
		cout << "                         关于" << endl;
		cout << "                         退出" << endl << endl;
		break;
	}
	case 4:
	{
		cout << "            关系的储存及基本运算（交、并、差）" << endl;
		cout << "                    笛卡尔乘积运算" << endl;
		cout << "                   关系复合、逆关系" << endl;
		cout << "              \033[7m关系闭包（自反、对称、传递）\033[0m" << endl;
		cout << "                     等价关系判断" << endl;
		cout << "                     偏序关系判断" << endl << endl;
		cout << "                         关于" << endl;
		cout << "                         退出" << endl << endl;
		break;
	}
	case 5:
	{
		cout << "            关系的储存及基本运算（交、并、差）" << endl;
		cout << "                    笛卡尔乘积运算" << endl;
		cout << "                   关系复合、逆关系" << endl;
		cout << "              关系闭包（自反、对称、传递）" << endl;
		cout << "                     \033[7m等价关系判断\033[0m" << endl;
		cout << "                     偏序关系判断" << endl << endl;
		cout << "                         关于" << endl;
		cout << "                         退出" << endl << endl;
		break;
	}

	case 6:
	{
		cout << "            关系的储存及基本运算（交、并、差）" << endl;
		cout << "                    笛卡尔乘积运算" << endl;
		cout << "                   关系复合、逆关系" << endl;
		cout << "              关系闭包（自反、对称、传递）" << endl;
		cout << "                     等价关系判断" << endl;
		cout << "                     \033[7m偏序关系判断\033[0m" << endl << endl;
		cout << "                         关于" << endl;
		cout << "                         退出" << endl << endl;
		break;
	}


	case 7:
	{
		cout << "            关系的储存及基本运算（交、并、差）" << endl;
		cout << "                    笛卡尔乘积运算" << endl;
		cout << "                   关系复合、逆关系" << endl;
		cout << "              关系闭包（自反、对称、传递）" << endl;
		cout << "                     等价关系判断" << endl;
		cout << "                     偏序关系判断" << endl << endl;
		cout << "                         \033[7m关于\033[0m" << endl;
		cout << "                         退出" << endl << endl;
		break;
	}

	case 8:
	{
		cout << "            关系的储存及基本运算（交、并、差）" << endl;
		cout << "                    笛卡尔乘积运算" << endl;
		cout << "                   关系复合、逆关系" << endl;
		cout << "              关系闭包（自反、对称、传递）" << endl;
		cout << "                     等价关系判断" << endl;
		cout << "                     偏序关系判断" << endl << endl;
		cout << "                         关于" << endl;
		cout << "                         \033[7m退出\033[0m" << endl << endl;
		break;
	}


	}	printf("=================================================================\n");

}
