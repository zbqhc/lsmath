#include"lsmath.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>

extern int lsmath(int[], int, int[], int);									//0x00: 离散数学核心，综合分析关系性质
extern int csort(int[], int, int);											//0x01: 数据排序
extern int isin(int[], int, int);											//0x02: 判断是否存在某数据
extern int dker(int[], int, int[], int, int[], int);						//0x03: 笛卡尔运算
extern int ui(int);															//0x04: 用户界面接口
extern int denum(int [], int);												//0x05: 将给定数据去重
extern int base(int[], int, int[], int, int[], int);						//0x06: 离散数学基本运算
extern int iscf(int[], int);												//0x07: 判断给定数据是否重复
extern int inputdata(int[], int);											//0x08: 格式化输入数据
extern int outputdata(int[], int, int);										//0x09: 格式化输出数据
extern int gxfh(int[], int, int[], int, int[]);								//0x0a: 关系复合运算
extern int msgbox(char[], char[], int,int,int, int, int,int,...);			//0x0b: 文本消息对话框
extern int analysisEqualClass(int[], int, int[]);							//0x0c: 关系类分析
extern void gameStart(void);												//0x0d: 彩蛋
extern int showItem(int,int,int,int, int, ...);								//0x0e: 菜单模块

extern void loginui(void);
extern int dealMenu(int);


int DEBUG_MODE = 1;
int gameFlag=0;



const int CONX = GetSystemMetrics(SM_CXSCREEN) + 300,CONY = GetSystemMetrics(SM_CYSCREEN) + 300;


int main()
{
	printf("\33[?25l");
	
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - LSMATH LAB");
	


	
	loginui();
	int temp = 0;

	while (temp=dealMenu(1),(temp == 0|| temp== -21))
	{
		CLS;
		loginui();
	}
		
	
	
	return 0;
}
