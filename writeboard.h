#include <stdio.h>
void writeboard(void )
{

	char board[8][8]={{'♜','♞ ','♝','♛','♚','♝','♞ ','♜'}
						,{'♙','♙','♙','♙','♙','♙','♙','♙'}
						,{' ',' ',' ',' ',' ',' ',' ',' '}
						,{' ',' ',' ',' ',' ',' ',' ',' '}
						,{' ',' ',' ',' ',' ',' ',' ',' '}
						,{' ',' ',' ',' ',' ',' ',' ',' '}
						,{'♙','♙','♙','♙','♙','♙','♙','♙'}
						,{'♖','♘','♗','♕','♔','♗','♘','♖'}};


int i,j;
for (i=0;i<8;i++)
{

	for (j=0;j<8;j++)
	{
		printf("%c  ",board[i][j]);
	}
	printf("\n");

}








}
