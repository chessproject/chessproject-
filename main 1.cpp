#include <stdlib.h>
#include"board.h"
#include"print.h"
using namespace std;

int main() {
	bool isend=false;
	int playernumber=1;
	char workboard[8][8]={
    {'r','n','b','k','q','b','n','r'}\
    ,{'s','s','s','s','s','s','s','s'}\
    ,{' ',' ',' ',' ',' ',' ',' ',' '}\
    ,{' ',' ',' ',' ',' ',' ',' ',' '}\
    ,{' ',' ',' ',' ',' ',' ',' ',' '}\
    ,{' ',' ',' ',' ',' ',' ',' ',' '}\
    ,{'S','S','S','S','S','S','S','S'}\
    ,{'R','N','B','Q','K','B','N','R'}};
	
	
	char board[24][40];
	
	
fillboard(board);
printBoard(board);
	return 0;
}
