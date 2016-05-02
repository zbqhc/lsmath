#include"lsmath.h"
#include<stdio.h>
#include<stdlib.h>

extern int selectItem(int);
extern int setting(void);
extern void teamAbout(void);
extern int msgbox(char title[], char text[], int x, int y, int W, int H, int mode, int counter, ...);

int dealMenu(int n)
{
	static int item;
	item = selectItem(n);
	if (n == 1)
		switch (item)
		{
		case 1:
			item = dealMenu(2);
			break;
		case 2:
			setting();
			break;
		case 3:
			teamAbout();
			break;
		case 4:
			exit(0);
		case -1:
			if (msgbox("提示", "您真的要离开实验室么", 12, 5, 50, 8, LS_YESNO, 0) == 1)
				exit(0);
			else
			{
				return 0;
			}
		}
	else if (n == 2)
		switch (item)
		{
		case 1:

		case 2:

		case 3:

		case 4:

		case 5:

		case 6:

		case 7:

		case -1:
			item = -21;
		}
	return item;

}