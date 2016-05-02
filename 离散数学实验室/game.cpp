//notes:
//
//head:null
//body:10
//red star:2
//normal star:1
//null:0
//==============================================================
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>

#define INITX 34
#define INITY 26
#define CLS system("cls")
#define BLOCK (struct block *)
#define SBLOCK sizeof(struct block)

struct block
{
	int x;
	int y;
	struct block *last;
	struct block *next;
};

struct block *head, *link, *nail, *local;

int **snakeGround = (int**)malloc(INITX * sizeof(int*));
int hor = 1, ver = 0;
int nailx, naily;
extern int gameFlag;
unsigned int score = 0,counter=0,timesCounter=INITX;
int  level=8;
int globalFlag = 1;



extern void gotoxy(int, int);
extern int msgbox(char[], char[], int, int, int, int, int,int,...);

void createGround(int, int);
int initSnake(int, int,int);
int readSnake(block *first,int);
int runSnake(block *);
int deleteSnake(block *first);
void foodCountDown(int);
void nailMove(block **first,block **latest);
int addSnake(block **latest);
int setSnakeFood(int);
void snakeDeath(int);
int produceRandNumber(int,int,int);
void snakeGroundType(int);




int produceRandNumber(int nmin, int nmax,int flag)
{
	static unsigned int randnum1 = time(NULL)/(flag+31), randnum2 = time(NULL)/(flag-17);
	srand((unsigned int)time(NULL)*(randnum1 +=7) / flag);
	return rand() % (nmax - nmin + 1) + nmin;
}
void snakeGroundType(int type)
{
	char map[INITY - 2][INITX - 2] = { "1111110000000000000000000111111","" };
	switch (type)
	{
	case 1:
		
	default:
		break;
	}
}
void createGround(int WL, int HL)
{
	int x, y;
	printf("┌");
	for (x = 0; x < WL-1; x++)
		printf("─");
	printf("┐\n");

	for (y = 0; y < HL-1; y++)
	{
		printf("│");
		for (x = 0; x < WL-1; x++)
			printf("  ");
		printf("│\n");
	}
	printf("└");
	for (x = 0; x < WL-1; x++)
		printf("─");
	printf("┘\n");
}
int initSnake(int wi, int hi,int length)
{
	int x, y;
	hor = 1;
	ver = 0;
	nailx = 0;
	naily=0;
	score = 0;
	counter = 0;
	timesCounter = INITX;
	globalFlag = 1;

	for (x = 0; x < INITX; x++)
		snakeGround[x] = (int *)malloc(INITY * sizeof(int));
	for (x = 0; x<INITX; x++)
		for (y = 0; y < INITY; y++)
		{
			snakeGround[x][y] = 0;
		}

	head = BLOCK malloc(SBLOCK);

	if (head == NULL)
		return -1;
	head->x = wi;
	head->y = hi;
	gotoxy(wi, hi);
	printf("●");

	head->last = NULL;
	link = head;

	//snakeGround[wi][hi] = 19;

	
	
	for (int i = 0; i < length-1; i++)
	{
		local = BLOCK malloc(SBLOCK);
		if (local == NULL)
			return -1;
		link->next = local;
		local->x = --wi;
		local->y = hi ;
		gotoxy(wi, hi);
		printf("■");
		local->next = NULL;
		local->last = link;
		link = local;
		snakeGround[wi][hi] = 10;
	}
	nailx = wi;
	naily = hi;

	nail = local;
	return 1;
}
int readSnake(block *first,int mode)
{
	int flag=0;
	local = first;


	



	while (local != NULL)
	{
		//mode = 0;
		if (mode)
		{
			gotoxy(37, 0);
			
			if (snakeGround[local->x][local->y] < 9)
				snakeGround[local->x][local->y] = 13;
			else
				flag = 1;
			gotoxy(local->x, local->y);
			printf("●");

			gotoxy(nailx, naily);
			snakeGround[nailx][naily] = 0;
			printf(" ");

			gotoxy(local->next->x, local->next->y);
			snakeGround[local->x][local->y] = 10;
			printf("■");
			//printf("%d %d %d\n",local->x ,local->y ,snakeGround[local->x][local->y]);
			if (flag)
				snakeDeath(snakeGround[local->x][local->y]);
			
			break;
		}
		else
		{
			
			printf("\tx=%d,y=%d\n", local->x, local->y);
		}
		local = local->next;
	}
	if (!mode)
		printf("\n");
	return 0;
}
int runSnake(block *first)
{
	int speed;
	gotoxy(0, INITY+2);
		printf("得分：%d",score);
	switch (level)
	{
	case 1:
		speed = 1000;
		break;
	case 2:
		speed = 800;
		break;
	case 3:
		speed = 600;
		break;
	case 4:
		speed = 450;
		break;
	case 5:
		speed = 300;
		break;
	case 6:
		speed = 200;
		break;
	case 7:
		speed = 100;
		break;
	case 8:
		speed = 50;
		break;
	}
	_getch();
	while (globalFlag)
	{
		gotoxy(0, INITY+2);
		printf("得分：%d",score);
		
		nailMove(&head, &nail);
		readSnake(head, 1);
		Sleep(speed);
		if (_kbhit())
		{
			int keyEvent;
			while (1) {
				keyEvent = _getch();
				if (keyEvent == 0)
					keyEvent = _getch(); 
				if (keyEvent == 72)
				{
					hor = 0;
					if (!ver)
						ver = -1;
					break;

				}
				if (keyEvent == 80)
				{
					hor = 0;
					if (!ver)
						ver = 1;
					break;
				}
				if (keyEvent == 75)
				{
					ver = 0;
					if (!hor)
						hor = -1;
					break;
				}
				if (keyEvent == 77)
				{
					
					ver = 0;
					if (!hor)
						hor = 1;
					break;
				}
			}
		}
	}
	return 0;
}
int deleteSnake(block *first)
{
	local = first;
	int x, y;
	while (local != NULL)
	{
		link = local->next;
		free(local);
		local = link;
	}

	for (x = 0; x < INITX; x++)
		free(snakeGround[x] );
	//free(snakeGround);
	return 0;
}
void foodCountDown(int markNumber)
{
	int i;
	gotoxy(0, INITY+1);
	for (i = 0; i < markNumber; i++)
		printf("\033[31m■\033[0m");
	for (i = 0; i < INITX - markNumber && markNumber>-1; i++)
		printf(" ");

}
void nailMove(block **first, block **latest)
{
	static int flag = 0;
	nailx = (*latest)->x;
	naily = (*latest)->y;
	((*latest)->last)->next = NULL;
	(*latest)->next = *first;
	(*first)->last = *latest;
	*first = *latest;
	*latest = (*first)->last;
	(*first)->last = NULL;
	if (score < 4 * level)
		flag = 0;
	if (flag)
	{
		foodCountDown(timesCounter--);
		if (timesCounter <= 0)
		{
			setSnakeFood(-1);
			flag = 0;
		}
	}
	
	(*first)->x = (((*first)->next)->x) + hor;
	if ((*first)->x ==  INITX )
		(*first)->x = 1;
	else if ((*first)->x == 0)
		(*first)->x = INITX -1;



	(*first)->y = (((*first)->next)->y) + ver;
	if ((*first)->y ==  INITY )
		(*first)->y = 1;
	else if ((*first)->y == 0)
		(*first)->y = INITY -1;

	if (snakeGround[(*first)->x][(*first)->y] == 1)
	{
		score += level;
		counter++;
		if (counter != 0 && counter % 5 == 0)
		{
			timesCounter = INITX;
			setSnakeFood(2);
			
			flag = 1;
			
		}
		snakeGround[(*first)->x][(*first)->y] = 0;
		
		setSnakeFood(1);
		addSnake(&nail);
	}
	else if (snakeGround[(*first)->x][(*first)->y] == 2)
	{
		score += level*5;
		gotoxy(0, INITY + 1);
		for (int i = 0; i<INITX; i++)
			printf("  ");
		timesCounter = -1;
	}
		
		
	
	
	
}
int addSnake(block **latest)
{
	struct block *addition = BLOCK malloc(SBLOCK);
	if (addition == NULL)
		return -1;
	(*latest)->next = addition;
	addition->last = *latest;
	addition->next = NULL;
	addition->x = nailx;
	addition->y = naily;
	*latest = addition;
	return 1;
}
int setSnakeFood(int mode)
{
	static int markx, marky;
	int x, y,flag=1;
	do
	{
		x = produceRandNumber(1, INITX -1,56);
		y = produceRandNumber(1, INITY - 1,29);
		
	} while (snakeGround[x][y]);
	
	
	gotoxy(x,y);
	if (mode == 1)
	{
		printf("★");
		snakeGround[x][y] = 1;
	}
	else if (mode==2)
	{
		printf("\033[31m★\033[0m");
		markx = x;
		marky = y;
		snakeGround[x][y] = 2;
	}
	else if (mode==-1)
	{
		gotoxy(markx, marky);
		printf(" ");
		gotoxy(0, INITY + 1);
		printf(" ");
		snakeGround[markx][marky]=0;
	}

	
	return 1-mode;
}
void snakeDeath(int mode)
{
	int i,x,y;
	hor = 0;
	ver = 0;
	for (i = 0; i < 10; i++)
	{
		gotoxy(local->x, local->y);
		printf("\033[0m●");
		Sleep(50);
		gotoxy(local->x, local->y);
		printf("\033[35m●");
		Sleep(100);
	}
	

	msgbox("游戏结束", "最高分：%d分", 5,5,50, 8, 0,1,score);
	
	globalFlag = 0;
	

}
void gameStart(void)
{


	gameFlag = 1;
	globalFlag = 1;
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "离散数学实验室 - ( ≧ V ≦ ) /");

	
	CLS;
	createGround(INITX, INITY);
	initSnake(25,12 ,3);
	//readSnake(head);
	
	
	setSnakeFood(1);
	runSnake(head);
	
	

	deleteSnake(head);
	gameFlag = 0;
	
	

}