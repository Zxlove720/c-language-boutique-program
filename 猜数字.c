#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
void start(vouid)
{
	printf("我们来玩个游戏？\n");
	Sleep(2000);
	printf("猜数字\n");
	Sleep(3000);
	system("cls");
}

void mainmenu(void)
{
	printf("***********************************\n");
	printf("***********************************\n");
	printf("***********************************\n");
	printf("*********扣1，一起摇滚吧！*********\n");
	printf("*********扣0，得到了惩罚！*********\n");
	printf("***********************************\n");
	printf("***********************************\n");
	printf("***********************************\n");
	printf("\n");
	printf("\n");
}

void maingame(void)
{
	srand((unsigned int)time(NULL));//提供time作为rand函数的随机数种子
	int num = rand() % 100 + 1;
	int guess;
	printf("游戏开始\n");
	printf("\n");
	while (1)
	{
		printf("请猜!\n");
		scanf("%d", &guess);
		if (guess > num)
		{
			printf("猜大了\n");
			printf("\n");
		}
		else if (guess < num)
		{
			printf("猜小了\n");
			printf("\n");
		}
		else
		{
			printf("猜对了，就是%d\n",num);
			Sleep(5000);
			system("cls");
			break;
		}
	}
	
}

int main()
{
	start();
	int input = 0;
	do
	{
		mainmenu();
		printf("你玩不玩 \n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			maingame();
			break;
		}
		case 0:
		{
			printf("gmae over\n");
			Sleep(2000);
			system("cls");
			Sleep(1000);
			break;
		}
		default:
		{
			printf("不要乱输\n");
			break;
		}
		}
	}
		while (input);
		return 0;
	}