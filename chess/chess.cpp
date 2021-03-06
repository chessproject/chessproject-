#include <cmath>
#include <iostream>
#include "chess.h"

ColorChessPiece::ColorChessPiece(ChessPiece piece, Color color) {
    this->piece = piece;
    this->color = color;
}

Chess::Chess() : turn(WHITE) {
    initializeChessBoard();
}

Chess::Chess(Color turn) : turn(turn) {
    initializeChessBoard();
}

void Chess::initializeChessBoard() {
    for (int i = 0; i < 8; ++i) {
        ChessLine chessLine;
        for (int j = 0; j < 8; ++j) {
            Color color = i < 4 ? WHITE : BLACK;
            if (i == 0 || i == 7) {
                if (j == 0 || j == 7) {
                    chessLine.push_back(ColorChessPiece(ROOK, color));
                } else if (j == 1 || j == 6) {
                    chessLine.push_back(ColorChessPiece(KNIGHT, color));
                } else if (j == 2 || j == 5) {
                    chessLine.push_back(ColorChessPiece(BISHOP, color));
                } else if (j == 3) {
                    chessLine.push_back(ColorChessPiece(KING, color));
                } else {
                    chessLine.push_back(ColorChessPiece(QUEEN, color));
                }
            } else if (i == 1 || i == 6) {
                chessLine.push_back(ColorChessPiece(PAWN, color));
            } else {
                chessLine.push_back(ColorChessPiece(NONE, color));
            }
        }
        chessBoard.push_back(chessLine);
    }
}

ChessBoard Chess::getChessBoard() {
    return chessBoard;
}

bool Chess::validPosition(int x, int y) {
    return x > -1 && x < 8 && y > -1 && y < 8;
}

ChessPiece Chess::getPiece(int x, int y) {
    if (!validPosition(x, y)) return NONE;
    return chessBoard[x][y].piece;
}

Color Chess::getColor(int x, int y) {
    if (!validPosition(x, y)) return BLACK;
    return chessBoard[x][y].color;
}

Position Chess::getKing(Color player) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (getPiece(i, j) == KING && getColor(i, j) == player) return Position(i, j);
        }
    }
    return Position(-1, -1);
}

bool Chess::isOpponent(int x, int y) {
    return !isEmpty(x, y) && getColor(x, y) != turn;
}

bool Chess::isEmpty(int x, int y) {
    return getPiece(x, y) == NONE;
}

vector<Position> Chess::getPossibleMoves(int x, int y ,Color c) {
    vector<Position> possibleMoves;
    if (getColor(x, y) != c) return possibleMoves;
    switch (getPiece(x, y)) {
        case KING:
            for (int i = -1; i < 2; ++i) {
                for (int j = -1; j < 2; ++j) {
                    int x1 = x + i, y1 = y + j;
                    if (canGo(x1, y1,c)) {
                            possibleMoves.push_back(Position(x1, y1));
                    }
                }
            }
            break;
        case QUEEN:
            for (int i = 1; i < 8; ++i){
                int x1 = x + i;
                int y1 = y + i;
                if (canGo(x1, y1,c)) {
                        possibleMoves.push_back(Position(x1, y1));
                    }
                if (!isEmpty(x1,y1)) break;
            }
            for (int i = 1; i < 8; ++i){
                int x1 = x - i;
                int y1 = y - i;
                if (canGo(x1, y1,c)) {
                        possibleMoves.push_back(Position(x1, y1));
                }
                if (!isEmpty(x1,y1)) break;
            }
            for (int i = 1; i < 8; ++i){
                int x1 = x - i;
                int y1 = y + i;
                if (canGo(x1, y1,c)) {
                        possibleMoves.push_back(Position(x1, y1));
                }
                if (!isEmpty(x1,y1)) break;
            }
            for (int i = 1; i < 8; ++i){
                int x1 = x + i;
                int y1 = y - i;
                if (canGo(x1, y1,c)) {
                        possibleMoves.push_back(Position(x1, y1));
                }
                if (!isEmpty(x1,y1)) break;
            }
            //like bishop


            for (int i = 1; i < 8 ; ++i) {
                int x1 = x;
                int y1 = y-i;
                if (canGo(x1, y1,c)) {
                        possibleMoves.push_back(Position(x1, y1));
                }
                if(!isEmpty(x1,y1)) break;
            }
            for (int i = 1; i < 8 ; ++i) {
                int x1 = x;
                int y1 = y+i;
                if (canGo(x1, y1,c)) {
                        possibleMoves.push_back(Position(x1, y1));
                }
                if(!isEmpty(x1,y1)) break;
            }
            for (int i = 1; i < 8 ; ++i) {
                int x1 = x-i;
                int y1 = y;
                if (canGo(x1, y1,c)) {
                        possibleMoves.push_back(Position(x1, y1));
                }
                if(!isEmpty(x1,y1)) break;
            }
            for (int i = 1; i < 8 ; ++i) {
                int x1 = x+i;
                int y1 = y;
                if (canGo(x1, y1,c)) {
                        possibleMoves.push_back(Position(x1, y1));
                }
                if(!isEmpty(x1,y1)) break;
            }//like rook
            break;
        case BISHOP:
            for (int i = 1; i < 8; ++i){
                    int x1 = x + i;
                    int y1 = y + i;
                    if (canGo(x1, y1,c)) {
                            possibleMoves.push_back(Position(x1, y1));
                    }
                    if (!isEmpty(x1,y1)) break;
                }
            for (int i = 1; i < 8; ++i){
                int x1 = x - i;
                int y1 = y - i;
                if (canGo(x1, y1,c)) {
                        possibleMoves.push_back(Position(x1, y1));
                }
                if (!isEmpty(x1,y1)) break;
            }
            for (int i = 1; i < 8; ++i){
                int x1 = x - i;
                int y1 = y + i;
                if (canGo(x1, y1,c)) {
                        possibleMoves.push_back(Position(x1, y1));
                }
                if (!isEmpty(x1,y1)) break;
            }
            for (int i = 1; i < 8; ++i){
                    int x1 = x + i;
                    int y1 = y - i;
                    if (canGo(x1, y1,c)) {
                            possibleMoves.push_back(Position(x1, y1));
                    }
                    if (!isEmpty(x1,y1)) break;
                }
            break;
        case KNIGHT:
            for (int i = 0; i < 8; ++i) {
                int x1 = x + (2 - (i % 2)) * pow(-1, i / 4);
                int y1 = y + (2 - ((i + 1) % 2)) * pow(-1, i / 2);
                if (canGo(x1, y1,c)) {
                        possibleMoves.push_back(Position(x1, y1));
                }
            }
            break;
        case ROOK:
            for (int i = 1; i < 8 ; ++i) {
                int x1 = x;
                int y1 = y-i;
                if (canGo(x1, y1,c)) {
                        possibleMoves.push_back(Position(x1, y1));
                }
                if(!isEmpty(x1,y1)) break;
            }
            for (int i = 1; i < 8 ; ++i) {
                int x1 = x;
                int y1 = y+i;
                if (canGo(x1, y1,c)) {
                        possibleMoves.push_back(Position(x1, y1));
                }
                if(!isEmpty(x1,y1)) break;
            }
            for (int i = 1; i < 8 ; ++i) {
                int x1 = x-i;
                int y1 = y;
                if (canGo(x1, y1,c)) {
                        possibleMoves.push_back(Position(x1, y1));
                }
                if(!isEmpty(x1,y1)) break;
            }
            for (int i = 1; i < 8 ; ++i) {
                int x1 = x+i;
                int y1 = y;
                if (canGo(x1, y1,c)) {
                        possibleMoves.push_back(Position(x1, y1));
                }
                if(!isEmpty(x1,y1)) break;
            }
            break;
        case PAWN:
            int x1 = x + (getColor(x, y) == WHITE ? 1 : -1);
            int y1 = y;
            if (isEmpty(x1, y1))
                possibleMoves.push_back(Position(x1, y1));
            if (isOpponent(x1, y1=y + 1))//zadan harif
                possibleMoves.push_back(Position(x1, y1));
            if (isOpponent(x1, y1=y - 1))//zadan harif
                possibleMoves.push_back(Position(x1, y1));
            break;
    }
    return possibleMoves;
}

bool Chess::isPossibleMove(int x1, int y1, int x2, int y2) {
    for (Position position : getPossibleMoves(x1, y1 ,turn)) {
        if (position.first == x2 && position.second == y2) return true;
    }
    return false;
}

bool Chess::canMove(int x, int y) {
    return validPosition(x, y) && !isEmpty(x, y) && getColor(x, y) == turn;
}

bool Chess::canMove(int x1, int y1, int x2, int y2) {
    return canMove(x1, y1) && isPossibleMove(x1, y1, x2, y2);
}

void Chess::move(int x1, int y1, int x2, int y2) {
     chessBoard[x2][y2] = chessBoard[x1][y1];
        chessBoard[x1][y1].piece = NONE;
        if (getPiece(x2, y2) == PAWN &&
            ((getColor(x2, y2) == WHITE && x2 == 7) || (getColor(x2, y2) == BLACK && x2 == 0))) {
            chessBoard[x2][y2].piece = QUEEN;
        }
}

bool Chess::canGo(int x, int y,Color co) {
    return validPosition(x, y) && !(!isEmpty(x, y) && getColor(x, y) == co) ;
}

bool Chess::kish(Color col) {
    Position kingpos;
    kingpos = getKing(col);
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
                for (Position position:getPossibleMoves(i, j, col==WHITE?BLACK:WHITE)) {
                    if (position.first == kingpos.first && position.second==kingpos.second)
                        return true;
                }
        }
    }
    return false;
}

bool Chess::maat_or_paat(Color col) {
    Position kingpos;
    kingpos = getKing(col);
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j) {
            if (getColor(i, j) == col) {
                    if(!getPossibleMoves(i,j,col).empty()) return false;
            }
        }
    return true;
}