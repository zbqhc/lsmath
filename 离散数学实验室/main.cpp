#include<stdio.h>
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

int DEBUG_MODE = 0;

int main()
{
	int a[] = { 1,2,3,4,5,6,11,32 };
	int b[] = { 1,2,3,4 };
	int c[13];
	int i;
	int size;
	size=base(a, 8, b, 4, c, 2);
	for (i = 0; i < size; i++)
		printf("%d\n", c[i]);
	//ui(0);


	return 0;
}