#include"lsmath.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>

extern int lsmath(int[], int, int[], int,int);									//0x00: ��ɢ��ѧ���ģ��ۺϷ�����ϵ����
extern int csort(int[], int, int);											//0x01: ��������
extern int isin(int[], int, int);											//0x02: �ж��Ƿ����ĳ����
extern int dker(int[], int, int[], int, int[], int);						//0x03: �ѿ�������
extern int denum(int [], int);												//0x05: ����������ȥ��
extern int base(int[], int, int[], int, int[], int);						//0x06: ��ɢ��ѧ��������
extern int iscf(int[], int);												//0x07: �жϸ��������Ƿ��ظ�
extern int inputdata(int[], int);											//0x08: ��ʽ����������
extern int outputdata(int[], int, int);										//0x09: ��ʽ���������
extern int gxfh(int[], int, int[], int, int[]);								//0x0a: ��ϵ��������
extern int msgbox(char[], char[], int,int,int, int, int,int,...);			//0x0b: �ı���Ϣ�Ի���
extern int analysisEqualClass(int[], int, int[]);							//0x0c: ��ϵ�����
extern void gameStart(void);												//0x0d: �ʵ�
extern int showItem(int,int,int,int, int, ...);								//0x0e: �˵�ģ��

extern void loginui(void);
extern int dealMenu(int);
extern int teamAbout(void);
extern int readFile(int);

extern int lsbaseWindows(void);
extern int dkerWindows(void);
extern int gxbbWindows(void);
extern int complexWindows(void);
extern int equalWindows(void);
extern int partialWindows(void);
extern int inversionWindows(void);
extern int equalclassWindows(void);






int gameFlag=0;
char *DIR;



const int CONX = GetSystemMetrics(SM_CXSCREEN) + 300,CONY = GetSystemMetrics(SM_CYSCREEN) + 300;
int menuMark = 0;

int main(int argc,char *argv[])
{
	DIR = argv[0];

	printf("\33[?25l");
	
	//int *xxxMark = (int *)malloc(sizeof(int));
	
		HWND hwnd = GetForegroundWindow();
		COORD size = { CONSOLEW, CONSOLEH };
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleScreenBufferSize(hOut, size);
		SMALL_RECT rc = { 0,0, CONSOLEW - 1, CONSOLEH - 1 };
		SetConsoleWindowInfo(hOut, true, &rc);
	
	SetWindowTextA(hwnd, "��ɢ��ѧʵ���� - LSMATH LAB");
	SetConsoleWindowInfo(hOut, true, &rc);

	int flag = 1;
	int GUID=1000;

	while (flag)
	{
		switch (GUID)
		{
		case 1000:
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
			
			equalclassWindows();
			GUID = 11;
			loginui();
			break;

		case 118:
			GUID = inversionWindows();
			break;

		case 12:
			GUID = dealMenu(12);
			break;
		case 121:
			readFile(0);
			GUID = 12;
			break;
		case 122:
			readFile(1);
			GUID = 12;
			break;
		case 123:
			readFile(2);
			GUID = 12;
			break;
		case 124:
			readFile(3);
			GUID = 12;
			break;
		case 125:
			readFile(4);
			GUID = 12;
			break;
		case 126:
			readFile(5);
			GUID = 12;
			break;
		case 127:
			readFile(6);
			GUID = 12;
			break;
		case 128:
			readFile(7);
			GUID = 12;
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
