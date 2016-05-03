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
extern int teamAbout(void);
extern int setting(void);

extern int lsbaseWindows(void);
extern int dkerWindows(void);
extern int gxbbWindows(void);
extern int complexWindows(void);
extern int equalWindows(void);
extern int partialWindows(void);
extern int inversionWindows(void);





int gameFlag=0;



const int CONX = GetSystemMetrics(SM_CXSCREEN) + 300,CONY = GetSystemMetrics(SM_CYSCREEN) + 300;
int menuMark = 0;

int main()
{
	printf("\33[?25l");
	
	//int *xxxMark = (int *)malloc(sizeof(int));
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - LSMATH LAB");
	

	//showItem(0, 2, 75, 1, smax, "进入实验室", "高级设置", "关于作者", "离开实验室");

	int flag = 1;
	int GUID=1000;

	while (flag)
	{
		switch (GUID)
		{
		case 1000://主菜单
			loginui();
			GUID=dealMenu(1000);
			break;

		case 11:
			GUID=dealMenu(11);
			
			break;

		case 111:
			GUID=lsbaseWindows();
			break;

		/*case 1111:
			printf("1111\n");
			break;

		case 1112:
			printf("1112\n");
			break;

		case 1113:
			printf("1113\n");
			break;*/



		case 112:
			GUID = dkerWindows();
			break;

		case 113:
			GUID = gxbbWindows();
			break;
/*
		case 1131:
			break;

		case 1132:
			break;

		case 1133:
			break;

			*/
		case 114:
			GUID = complexWindows();
			break;

		case 115:
			GUID = equalWindows();
			break;

		case 116:
			GUID = partialWindows();
			break;

		case 117:
			loginui();
			printf("此功能正在开发中。。。。\n");
			_getch();
			GUID = 11;
			loginui();
			break;

		case 118:
			GUID = inversionWindows();
			break;

		case 12:
			GUID=setting();
			break;

		case 13:
			GUID=teamAbout();
			break;

		case 14:
			flag = 0;
			break;


		default:
			break;
		}
	}






	/*














	loginui();
	int temp = 0;
	static int exitFlag = 1;
	while (exitFlag)
	{
		while (temp = , (temp == 0 || temp == -21))
		{
			CLS;
			loginui();
		}

	}
	*/
	return 0;
}
