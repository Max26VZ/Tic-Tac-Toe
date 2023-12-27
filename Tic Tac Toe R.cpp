//���Q��10/6 
#include <stdio.h>

void print(char board[5][5]);
void game(char board[5][5]);
void restart(char board[5][5]);

int main(void)
{
    int i, j;
    char board[5][5];

    // ��l�ƴѽL
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (j % 2 == 1 && i % 2 == 0)
                board[i][j] = '|';
            else if (i % 2 == 0 && j % 2 == 0)
                board[i][j] = ' ';
            if (i % 2 == 1 && j % 2 == 0)
                board[i][j] = '-';
            else if (i % 2 == 1 && j % 2 == 1)
                board[i][j] = '+';
        }
    }

    while (1)
    {
        printf("�п�J��ӼƦr�}�l�C���A�d��b 0��2�AO����A�Ҧp�G0 0\n");
        game(board);

        printf("\n�A���@���ܡH�]��J1�~��A��J0�h�X�^: ");
        int playAgain;
        scanf("%d", &playAgain);

        if (playAgain != 1)
        {
            break;
        }
        else
        {
            restart(board);
        }
    }

    printf("�A���I\n");

    return 0;
}

void print(char board[5][5])
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%c", board[i][j]);
        printf("\n");
    }
}

void game(char board[5][5])
{
    int turn, count = 0, n1, n2, legal = 0, i, j, ans = 0, n;
    for (turn = 0; turn < 9; turn++)
    {
        scanf("%d%d", &n1, &n2);
        n1 *= 2;
        n2 *= 2;
        legal = 0;
        printf("���� %d:\n", turn + 1);

        if (board[n1][n2] == ' ')
        {
            legal = 1;
        }
        else
        {
            turn -= 1;
            printf("�����b�o�C�п�ܥt�@�Ӧ�m�C\n");
        }

        if (turn % 2 == 0 && legal == 1)
        {
            printf("O ��m����m�G%d %d\n", n1 / 2, n2 / 2);
            board[n1][n2] = 'O';
        }
        else if (turn % 2 == 1 && legal == 1)
        {
            printf("X ��m����m�G%d %d\n", n1 / 2, n2 / 2);
            board[n1][n2] = 'X';
        }

        print(board);

        // �ˬd�O�_�����aĹ�F
        for (i = 0; i < 5; i += 2)
            if (board[i][0] == board[i][2] && board[i][2] == board[i][4] && board[i][2] != ' ')
            {
                printf("���a %c ��ӡI\n", board[i][0]);
                ans = 1;
                break;
            }

        for (j = 0; j < 5; j += 2)
            if (board[0][j] == board[2][j] && board[2][j] == board[4][j] && board[2][j] != ' ')
            {
                printf("���a %c ��ӡI\n", board[0][j]);
                ans = 1;
                break;
            }

        if (board[0][0] == board[2][2] && board[2][2] == board[4][4] && board[2][2] != ' ')
        {
            printf("���a %c ��ӡI\n", board[0][0]);
            ans = 1;
            break;
        }

        if (board[0][4] == board[2][2] && board[2][2] == board[4][0] && board[2][2] != ' ')
        {
            printf("���a %c ��ӡI\n", board[0][4]);
            ans = 1;
            break;
        }

        if (turn == 8)
        {
            printf("����I\n");
            ans = 1;
        }

        if (ans == 1)
        {
            printf("��J 0 �����A��J��L�Ʀr���s�}�l: ");
            scanf("%d", &n);
            if (n == 0)
                break;
            else
            {
                ans = 0;
                restart(board);
            }
        }
    }
}

void restart(char board[5][5])
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (j % 2 == 1 && i % 2 == 0)
                board[i][j] = '|';
            else if (i % 2 == 0 && j % 2 == 0)
                board[i][j] = ' ';
            if (i % 2 == 1 && j % 2 == 0)
                board[i][j] = '-';
            else if (i % 2 == 1 && j % 2 == 1)
                board[i][j] = '+';
        }
    }
}

