#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
extern int lsmath(int[], int, int[], int);					//0x00: ��ɢ��ѧ���ģ��ۺϷ�����ϵ����
extern int csort(int[], int, int);							//0x01: ��������
extern int isin(int[], int, int);							//0x02: �ж��Ƿ����ĳ����
extern int dker(int[], int, int[], int, int[], int);		//0x03: �ѿ�������
extern int ui(int);											//0x04: �û�����ӿ�
extern int denum(int [], int);								//0x05: ����������ȥ��
extern int base(int[], int, int[], int, int[], int);		//0x06: ��ɢ��ѧ��������
extern int iscf(int[], int);								//0x07: �жϸ��������Ƿ��ظ�
extern int inputdata(int[], int, int);						//0x08: ��ʽ����������
extern int outputdata(int[], int, int);						//0x09: ��ʽ���������
extern int gxfh(int[], int, int[], int, int[]);				//0x0a: ��ϵ��������
extern int msgbox(char[], char[], int, int, int);			//0x0b: �ı���Ϣ�Ի���
extern int analysisEqualClass(int[], int, int[]);			//0x0c: ��ϵ�����
extern void gameStart(void);

int DEBUG_MODE = 1;

#define LS_OK 0
#define LS_YESNO 1
#define LS_ABORTIGNORE 2

#define CLS system("cls");


int main()
{
	gameStart();


	return 0;
}
