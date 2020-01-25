#include "chess.h"
#include <cmath>

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

vector<Position> Chess::getPossibleMoves(int x, int y) {
    vector<Position> possibleMoves;
    if (getColor(x, y) != turn) return possibleMoves;
    switch (getPiece(x, y)) {
        case KING:
            for (int i = -1; i < 2; ++i) {
                for (int j = -1; j < 2; ++j) {
                    int x1 = x + i, y1 = y + j;
                    if (canGo(x1, y1))
                        possibleMoves.push_back(Position(x1, y1));
                }
            }
            break;
        case QUEEN:
            for (int j = 0; j < 4; ++j) {
                for (int i = 0; i < 8; ++i) {
                    int x1 = x + i * (j % 2) * pow(-1, j / 2);
                    int y1 = y + ((j + 1) % 2) * pow(-1, j / 2);
                    if (canGo(x1, y1)) {
                        possibleMoves.push_back(Position(x1, y1));
                    } else {
                        break;
                    }
                    if (!isEmpty(x1, y1)) break;
                }
            }
            for (int j = 0; j < 4; ++j) {
                for (int i = 1; i < 8; ++i) {
                    int x1 = x + i * pow(-1, j % 2);
                    int y1 = y + i * pow(-1, j % 2 + 1);
                    if (canGo(x1, y1)) {
                        possibleMoves.push_back(Position(x1, y1));
                    } else {
                        break;
                    }
                    if (!isEmpty(x1, y1)) break;
                }
            }
            break;
        case BISHOP:
            for (int j = 0; j < 4; ++j) {
                for (int i = 1; i < 8; ++i) {
                    int x1 = x + i * pow(-1, j % 2);
                    int y1 = y + i * pow(-1, j % 2 + 1);
                    if (canGo(x1, y1)) {
                        possibleMoves.push_back(Position(x1, y1));
                    } else {
                        break;
                    }
                    if (!isEmpty(x1, y1)) break;
                }
            }
            break;
        case KNIGHT:
            for (int i = 0; i < 8; ++i) {
                int x1 = x + (2 - (i % 2)) * pow(-1, i / 4);
                int y1 = y + (2 - ((i + 1) % 2)) * pow(-1, i / 2);
                if (canGo(x1, y1))
                    possibleMoves.push_back(Position(x1, y1));
            }
            break;
        case ROOK:
            for (int j = 0; j < 4; ++j) {
                for (int i = 1; i < 7; ++i) {
                    int x1 = x + i * (j % 2) * pow(-1, j / 2);
                    int y1 = y + i * ((j + 1) % 2) * pow(-1, j / 2);
                    if (canGo(x1, y1)) {
                        possibleMoves.push_back(Position(x1, y1));
                    } else {
                        break;
                    }
                    if (!isEmpty(x1, y1)) break;
                }
            }
            break;
    }
    return possibleMoves;
}

bool Chess::cangGo(char x, int y) {
    return validPosition(x, y) && !canMove(x, y) && getPiece(x, y) != KING;

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
