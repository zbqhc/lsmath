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
	  { "��ϵ�Ļ�������.txt",
		"�ѿ����˻�����.txt",
		"�жϹ�ϵ�հ�.txt",
		"��ϵ��������.txt",
		"�жϵȼ۹�ϵ.txt",
		"�ж�ƫ���ϵ.txt",
		"�����ȼ���.txt",
		"���ϵ����.txt" };

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