#include <stdio.h>


void show_board(int board[3][3]);
int player_wins(int board[3][3]);
int win= -1;
int board[3][3];


void show_board(int board[3][3])
{
   for (int i=0;i<3;i++ )
   {
      for (int j=0;j<3;j++ )
      {
         printf("%d\t",board[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}

int player_wins(int board [3][3])
{
   if ((board[0][0]==1 && board[0][1]==1 && board[0][2]==1)||board[0][0]==2 && board[0][1]==2 && board[0][2]==2)
   {
      return 1;
   }
   else if ((board[1][0]==1 && board[1][1]==1 && board[0][2]==1)||(board[1][0]==2 && board[1][1]==2 && board[0][2]==2))
   {
      return 1;
   }
   else if ((board[2][0]==1 && board[2][1]==1 && board[2][2]==1)||(board[2][0]==2 && board[2][1]==2 && board[2][2]==2))
   {
      return 1;
   }
   else if ((board[0][0]==1 && board[1][1]==1 && board[2][2]==1)||(board[0][0]==2 && board[1][1]==2 && board[2][2]==2))
   {
      return 1;
   }
   else if ((board[0][2]==1 && board[1][1]==1 && board[2][0]==1)||(board[0][2]==2 && board[1][1]==2 && board[2][0]==2))
   {
      return 1;
   }
   else if ((board[0][0]==1 && board[1][0]==1 && board[2][0]==1)||(board[0][0]==2 && board[1][0]==2 && board[2][0]==2))
   {
      return 1;
   }
   else if ((board[0][1]==1 && board[1][1]==1 && board[2][1]==1)||(board[0][1]==2 && board[1][1]==2 && board[2][1]==2))
   {
      return 1;
   }
   else if ((board[0][2]==1 && board[1][2]==1 && board[2][2]==1)||(board[0][2]==2 && board[1][2]==2 && board[2][2]==2))
   {
      return 1;
   }
   else
   {
      return -1;
   }
}


int main()
{
   int n,m;
   int board [3][3],k=1;

   printf("Instructions:\n\nEnter the cell no as address of the matrix element\n(Eg:Enter 1 1 if you want to select the first cell)\n\n");
   for (int i=0;i<3;i++ )
   {
      for (int j=0;j<3;j++ )
      {
         board[i][j]=0;
      printf("%d\t",board[i][j]);
      }
      printf("\n");
   }
   printf("\n");

   while (k<8)
   {
      if (k%2!=0)
      {
         printf("Player 1 play your turn!\n\n");
         scanf("%d %d" ,&n,&m);
         printf("\n");
         board[n-1][m-1]=1;
         show_board(board);
         win=player_wins(board);
         if (win==1)
         {
            printf("Player1 wins\n\n");
            break;
         }
      }

      else
      {
         printf("Player 2 play your turn!\n\n");
         scanf("%d %d" ,&n,&m);
         board[n-1][m-1]=2;
         show_board(board);
         win=player_wins(board);
         if (win==1)
         {
            printf("Player2 wins\n\n");
            break;
         }
      }
      k++;

      if (k>=8)
      {
         printf("Match Draw\n");
      }
   }

   return 0;
}
