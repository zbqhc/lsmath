#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include"lsmath.h"


extern void gameStart(void);
extern int dealMenu(int);
extern void loginui(void);
extern void gotoxy(int, int);

int teamAbout(void)
{
	int i;
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "��ɢ��ѧʵ���� - �Ŷ���Ϣ");

	
	loginui();
	printf("\n\n");
	printf("\t\t\t\t     ��������\n\n\t\t\t\t      �Ų�ǿ\n\n\t\t\t�������̼�����ѧ ���ѧԺ 15��9��\n\n\t\t\t\t    ");
	//printf("\t\t\t\t     �Ŷ���Ϣ\n\n\t\t\t    �Ų�ǿ����꿡����ط塢����\n\n\t\t\t�������̼�����ѧ ���ѧԺ 15��9��\n\n\t\t\t\t    ");
	printf("\n\t\t\t\t     ָ����ʦ\n\n\t\t\t\t      ������\n\n");

	printf("\n\n");
	printf("\n\t����������շ���ǰ�Թ��ܽ����˲��ԣ�ȷ�����ܶ�����׼ȷִ�У�����\n\t���Ŷ�ˮƽ�Ϳ����������ޣ��������©�������⣬������λ���ߴͽ̡�\n");
	printf("\n\t\t\t\t\t\t\t  ");
	printf(DATENOW);
	
	i = 1;
	while (_getch() == ' ')
	{
		i++;
		if (i > 7)
		{
			gameStart();
			break;
		}
	}
	

	return 1000;
	
	
}