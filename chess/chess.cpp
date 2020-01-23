#include "chess.h"

bool Chess::validPosition(int x, int y) {
    return x > -1 && x < 8 && y > -1 && y < 8;
}

ChessBoard Chess::getChessBoard(){
    return chessBoard;
}

ChessPiece Chess::getPiece(int x, int y) {
    if (!validPosition(x, y)) return NONE;
    return chessBoard[x][y].piece;
}

Color Chess::getColor(int x, int y) {
    if (!validPosition(x, y)) return BLACK;
    return chessBoard[x][y].color;
}

bool Chess::isEmpty(int x, int y) {
    return getPiece(x, y) == NONE;
}

bool Chess::cango(char x, int y) {

}

bool Chess::canMove(int x, int y) {

    return validPosition(x, y) && !isEmpty(x, y) && getColor(x, y) == turn;//incomplete
}

void Chess::move(char x1, int y1, char x2, int y2) {

}

bool Chess::kish() {

}

bool Chess::mat() {

}
