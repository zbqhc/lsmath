#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include"lsmath.h"


extern void gameStart(void);
extern int dealMenu(int);
extern void loginui(void);
extern void gotoxy(int, int);

void teamAbout(void)
{
	int i;
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "��ɢ��ѧʵ���� - �Ŷ���Ϣ");

	
	loginui();
	printf("\n\n");
	printf("\t\t\t\t     ��������\n\n\t\t\t\t      �Ų�ǿ\n\n\t\t\t�������̼�����ѧ ���ѧԺ 15��9��\n\n\t\t\t\t    ");
	printf(DATENOW);
	printf("\n");
	printf("\n\t����������շ���ǰ�Թ��ܽ����˲��ԣ�ȷ�����ܶ�����׼ȷִ�У�����\n\t���Ŷ�ˮƽ�Ϳ����������ޣ��������©�������⣬������λ���ߴͽ̡�");
	gotoxy(0, 2);
	for (i = 0; i<MAXH + 5; i++)
		printf("\n");
	for (i = 0; i < 40; i++)
		printf("��");
	i = 1;
	while (_getch() == ' ')
	{
		i++;
		if (i > 8)
		{
			gameStart();
			CLS;
			loginui();
			dealMenu(1);
		}
	}
	CLS;
	loginui();
	dealMenu(1);
	
}