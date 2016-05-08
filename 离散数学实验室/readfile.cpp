#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>
extern void loginui(void);

extern char *DIR;
int readFile(int n)
{
	int len = strlen(DIR);
	int i,tmp;
	char *str;
	
	loginui();
	char notecmd[22] = "cmd /c start notepad ";
	char fileName[8][30] =
	  { "关系的基本运算.txt",
		"笛卡尔乘积运算.txt",
		"判断关系闭包.txt",
		"关系复合运算.txt",
		"判断等价关系.txt",
		"判断偏序关系.txt",
		"分析等价类.txt",
		"逆关系运算.txt" };

	for (i = len - 1 ; i > 0 && DIR[i] != '\\'; i--);
	str = (char *)malloc((i + 50) * sizeof(char));
	for (len = 0; len < strlen(notecmd); len++)
		str[len] = notecmd[len];
	tmp = len;
	for (; len - tmp < i+1; len++)
		str[len] = DIR[len - tmp];
	tmp = len;
	i = strlen(fileName[n]);
	for (; len - tmp < i; len++)
		str[len] = fileName[n][len-tmp];
	str[len] = 0;
	//printf("%s", str);
	system(str);
	return 1000;
}