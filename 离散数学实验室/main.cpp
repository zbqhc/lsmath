#include"lsmath.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>

extern int lsmath(int[], int, int[], int);									//0x00: ��ɢ��ѧ���ģ��ۺϷ�����ϵ����
extern int csort(int[], int, int);											//0x01: ��������
extern int isin(int[], int, int);											//0x02: �ж��Ƿ����ĳ����
extern int dker(int[], int, int[], int, int[], int);						//0x03: �ѿ�������
extern int ui(int);															//0x04: �û�����ӿ�
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


int DEBUG_MODE = 1;
int gameFlag=0;



const int CONX = GetSystemMetrics(SM_CXSCREEN) + 300,CONY = GetSystemMetrics(SM_CYSCREEN) + 300;


int main()
{
	printf("\33[?25l");
	
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "��ɢ��ѧʵ���� - LSMATH LAB");
	


	
	loginui();
	int temp = 0;

	while (temp=dealMenu(1),(temp == 0|| temp== -21))
	{
		CLS;
		loginui();
	}
		
	
	
	return 0;
}
