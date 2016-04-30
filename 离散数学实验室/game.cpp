#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>



#define INITX 35
#define INITY 25
#define CLS system("cls")

#define BLOCK (struct block *)
#define SBLOCK sizeof(struct block)
int  level=7;


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
unsigned int score = 0;





void gotoxy(int, int);
void createGround(int, int);
int initSnake(int, int,int);
int readSnake(block *first,int);
int runSnake(block *);
int deleteSnake(block *first);
void nailMove(block **first,block **latest);
int addSnake(block **latest);
int setSnakeFood(int);
int produceRandNumber(int,int,int);









int produceRandNumber(int nmin, int nmax,int flag)
{
	static unsigned int randnum1 = time(NULL)/13, randnum2 = time(NULL)/23;
	if (flag)
		srand((unsigned int)time(NULL)*(randnum1 +=7) / 37);
	else
		srand((unsigned int)time(NULL)*(randnum2 -=19)/ 61);
	return rand() % (nmax - nmin + 1) + nmin;
}
void gotoxy(int x, int y)//位置函数
{
	COORD pos;

	pos.X = 2*x;

	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
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
	printf("\33[?25l");
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

	snakeGround[wi][hi] = 10;

	
	
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
	local = first;
	while (local != NULL)
	{
		//mode = 0;
		if (mode)
		{
			gotoxy(local->x, local->y);
			int x=local->x, y =local->y ;
			printf("●");
			gotoxy(nailx, naily);
			snakeGround[nailx][naily] = 0;
			printf(" ");
			gotoxy(local->next->x, local->next->y);
			printf("■");

			
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
	while (1)
	{
		gotoxy(0, 27);
		printf("坐标：(%d,%d)\t得分：%d",head->x,head->y,score);
		
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
					ver = -1;
					break;

				}
				if (keyEvent == 80)
				{
					hor = 0;
					ver = 1;
					break;
				}
				if (keyEvent == 75)
				{
					hor = -1;
					ver = 0;
					break;
				}
				if (keyEvent == 77)
				{
					hor = 1;
					ver = 0;
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
	while (local != NULL)
	{
		link = local->next;
		free(local);
		local = link;
	}
	return 0;
}
void nailMove(block **first, block **latest)
{
	nailx = (*latest)->x;
	naily = (*latest)->y;
	((*latest)->last)->next = NULL;
	(*latest)->next = *first;
	(*first)->last = *latest;
	*first = *latest;
	*latest = (*first)->last;
	(*first)->last = NULL;

	
	
	
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
		snakeGround[(*first)->x][(*first)->y] = 0;
		setSnakeFood(1);
		addSnake(&nail);
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
	int x, y,tmp,flag=1;
	do
	{
		x = produceRandNumber(1, INITX -1,1);
		y = produceRandNumber(1, INITY - 1, 0);
		
	} while (0);
	
	
	gotoxy(x,y);
	printf("★");
	snakeGround[x][y] = 1;
	return 1-mode;
}


void gameStart(void)
{
	


	
	CLS;
	createGround(INITX, INITY);
	initSnake(25,12 ,3);
	//readSnake(head);
	
	
	setSnakeFood(1);
	runSnake(head);
	
	

	deleteSnake(head);

}