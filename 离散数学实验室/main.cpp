#include<stdio.h>
extern int lsmath(int[], int, int[], int);					//0x00: 离散数学核心，综合分析关系性质
extern int csort(int[], int, int);							//0x01: 数据排序
extern int isin(int[], int, int);							//0x02: 判断是否存在某数据
extern int dker(int[], int, int[], int, int[], int);		//0x03: 笛卡尔运算
extern int ui(int);											//0x04: 用户界面接口
extern int denum(int [], int);								//0x05: 将给定数据去重
extern int base(int[], int, int[], int, int[], int);		//0x06: 离散数学基本运算
extern int iscf(int[], int);								//0x07: 判断给定数据是否重复
extern int inputdata(int[], int, int);						//0x08: 格式化输入数据
extern int outputdata(int[], int, int);						//0x09: 格式化输出数据
extern int gxfh(int[], int, int[], int, int[]);				//0x0a: 关系复合运算

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