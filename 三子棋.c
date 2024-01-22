#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
void menu()
{
	printf("*****************************\n");
	printf("*****************************\n");
	printf("********1.play 0.exit********\n");
	printf("*****************************\n");
	printf("\n");
}
void intboard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//��Ϊ�����ж����ˣ�����˵�����������д����ֻ��д3*3
/*void Displayboard(char board[ROW][COL], int row, int col)
{
	int i;
	for (i = 0; i < row; i++)
	{
		//��ӡ����
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		//��ӡ�ָ�
		if (i < row - 1)
		printf("---|---|---\n");
	}
}*/
void Displayboard(char board[ROW][COL], int row, int col)
{
	int i;
	for (i = 0; i < row; i++)
	{
		//��ӡ����
		int j;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//��ӡ�ָ�
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void playermove(char board[ROW][COL], int row, int col)
{
	printf("����������:(����ǰ�����ں����ÿո��س�����)\n");
	printf("AlphaGO��1s��˼��ʱ�䣬��Ҫ����\n");
	printf("���������>\n");
	int x, y;
	scanf("%d%d", &x, &y);
	while (1)
	{
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("\n");
				printf("�Ѿ���ռ����\n");
				printf("\n");
				break;
			}
		}
		else
		{
			printf("\n");
			printf("����Ƿ�\n");
			printf("\n");
			break;
		}
	}
}
void AlphaGO(char board[ROW][COL], int row, int col)
{
	printf("Alpha go->\n");

	while (1)
	{
		int x, y;
		x = rand() % row;
		y = rand() & col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '$';
			break;
		}
	}
}
int Full(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char result(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	int j;
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	if (Full(board, row, col))
	{
		return 'Q';
	}
	return 'c';
}
void board_game()
{
	char board[ROW][COL];
	intboard(board, ROW, COL);
	Displayboard(board, ROW, COL);
	char ret;
	while (1)
	{
		playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = result(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		AlphaGO(board, ROW, COL);
		Sleep(1000);
		Displayboard(board, ROW, COL);
		ret = result(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��Ӯ��\n");
		Displayboard(board, ROW, COL);
		Sleep(2000);
		system("cls");

	}
	else if (ret == '$')
	{
		system("cls");
		printf("you loss\n");
		printf("fvv\n");
		Sleep(2000);
		Displayboard(board, ROW, COL);
		system("cls");

	}
	else
		printf("ƽ��\n");
	Displayboard(board, ROW, COL);
	Sleep(2000);
	system("cls");
}
int main()
{
	srand((unsigned int)time(NULL));
	int input;
	do
	{
		menu();
		printf("do you want to play it?");
		printf("\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			system("cls");
			printf("�㽫��սAlphaGO�����������ڻ���������\n");
			board_game();
			break;
		}
		case 0:
		{
			system("cls");
			printf("game over\n");
			Sleep(1000);
			system("cls");
			printf("fvv\n");
			Sleep(1000);
			break;
		}
		default:
		{
			system("cls");
			printf("error\n");
			Sleep(2000);
			system("cls");
			break;
		}
		}
	} while (input);
	return 0;
}