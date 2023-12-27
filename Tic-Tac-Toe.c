//姜貴豐-10/6
#include <stdio.h>
void print(char board[10][10]);
void game(char board[10][10]);

int main(void)
{
	int i,j;
	char board[10][10];
	for(i=0;i<5;i++)
	{
		for(j=0;j<=5;j++)
		{
			if(j%2==1&&i%2==0)
				board[i][j]='|';
			else if(i%2==0&&j%2==0)
				board[i][j]=' ';
			if(i%2==1&&j%2==0)
				board[i][j]='-';
			else if(i%2==1&&j%2==1)
				board[i][j]='+';
		}
	}
	printf("Type two numbers from 0~2 ex:0 0\n");
	game(board);
	return 0;
}
void print(char board[10][10])
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		printf("%c",board[i][j]);
		printf("\n");
	}
}
void game(char board[10][10])
{
	int turn,count=0,n1,n2,legal=0,i,j,ans=0,n;
	for(turn=0;turn<9;turn++)
	{
		scanf("%d%d",&n1,&n2);
		n1*=2;
		n2*=2;
		legal=0;
		printf("第%d次\n",turn+1);
		if(board[n1][n2]==' ')
		{
			legal=1;
		}
		else
		{
			turn-=1;
			printf("change another number:\n");
		}
		if(turn%2==0&&legal==1)
		{
			printf("Place to put O:%d %d\n",n1/2,n2/2);
			
			if(n1==0)
			{
				board[n1][n2]='O';
			}
			else if(n1==2)
			{
				board[n1][n2]='O';
			}
			else if(n1==4)
			{
				board[n1][n2]='O';
			}
		}
		else if(turn%2==1&&legal==1)
		{	
			printf("Place to put X:%d %d\n",n1/2,n2/2);
			if(n1==0)
			{
				
				board[n1][n2]='X';
			}
			else if(n1==2)
			{
			
				board[n1][n2]='X';
			}
			else if(n1==4)
			{
				board[n1][n2]='X';
			}
		}
		if(legal==1)
		for(i=0;i<5;i++)
		{	
			for(j=0;j<5;j++)
			printf("%c",board[i][j]);
			printf("\n");	
		}
		for(i=0;i<5;i+=2)
			if(board[i][0]==board[i][2]&&board[i][2]==board[i][4]&&board[i][2]!=' ')
			{
				printf("Player %c win!",board[i][0]);
				ans=1;
				break;
			}
		for(j=0;j<5;j+=2)
			if(board[0][j]==board[2][j]&&board[2][j]==board[4][j]&&board[2][j]!=' ')
			{
				printf("Player %c win!",board[0][j]);
				ans=1;
				break;
			}
		if(board[0][0]==board[2][2]&&board[2][2]==board[4][4]&&board[2][2]!=' ')
		{
			printf("Player %c win!",board[0][0]);
			ans=1;
			break;
		}
		if(board[0][4]==board[2][2]&&board[2][2]==board[4][0]&&board[2][2]!=' ')
		{
			printf("Player %c win!",board[0][4]);
			ans=1;
			break;
		}
		if(turn==9)
		{
			printf("Equal!");
			ans=1;
			
		}
		if(ans==1)
		{
			printf("\n讀入數字0結束，數字1重新開始\n");
			scanf("%d",&n);
			if(n==0)
				break;
			else 
			{
				ans=0;
				restart(board);
			}
		}
	}

	
}
return 0;
