#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
void start(vouid)
{
	printf("�����������Ϸ��\n");
	Sleep(2000);
	printf("������\n");
	Sleep(3000);
	system("cls");
}

void mainmenu(void)
{
	printf("***********************************\n");
	printf("***********************************\n");
	printf("***********************************\n");
	printf("*********��1��һ��ҡ���ɣ�*********\n");
	printf("*********��0���õ��˳ͷ���*********\n");
	printf("***********************************\n");
	printf("***********************************\n");
	printf("***********************************\n");
	printf("\n");
	printf("\n");
}

void maingame(void)
{
	srand((unsigned int)time(NULL));//�ṩtime��Ϊrand���������������
	int num = rand() % 100 + 1;
	int guess;
	printf("��Ϸ��ʼ\n");
	printf("\n");
	while (1)
	{
		printf("���!\n");
		scanf("%d", &guess);
		if (guess > num)
		{
			printf("�´���\n");
			printf("\n");
		}
		else if (guess < num)
		{
			printf("��С��\n");
			printf("\n");
		}
		else
		{
			printf("�¶��ˣ�����%d\n",num);
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
		printf("���治�� \n");
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
			printf("��Ҫ����\n");
			break;
		}
		}
	}
		while (input);
		return 0;
	}