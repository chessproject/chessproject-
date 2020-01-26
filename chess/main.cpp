#include <iostream>
#include "chess.h"
void writeBoard(const ChessBoard& chessBoard);
int main() {
    int x1,y1,x2,y2;
    Chess chess(BLACK);
    while (!chess.maat_or_paat()) {
        writeBoard(chess.getChessBoard());
        cin >> x1 >> y1 >> x2 >> y2;
        if (chess.canMove(x1, y1, x2, y2)) {
            chess.move(x1, y1, x2, y2);
            chess.turn = chess.turn == WHITE ? BLACK : WHITE;
        }
        //cout << chess.getPossibleMoves(0, 0).size() << endl;
        //cout << chess.getPossibleMoves(1, 0).size() << endl;
        cout << chess.turn << endl;
    }
    if (chess.kish()) {
        cout << "maat" << endl;
    } else {
        cout << "paat" << endl;
    }
    return 0;
}
void writeBoard(const ChessBoard& chessBoard) {
    for (const ChessLine& chessLine : chessBoard) {
        for (ColorChessPiece colorChessPiece : chessLine) {
            cout << "[";
            switch (colorChessPiece.piece) {
                case NONE:
                    cout << "  ";
                    break;
                case KING:
                    cout << (colorChessPiece.color == WHITE ? "Kb" : "Kw");
                    break;
                case QUEEN:
                    cout << (colorChessPiece.color == WHITE ? "Qb" : "Qw");
                    break;
                case BISHOP:
                    cout << (colorChessPiece.color == WHITE ? "Bb" : "Bw");
                    break;
                case KNIGHT:
                    cout << (colorChessPiece.color == WHITE ? "Kb" : "Kw");
                    break;
                case ROOK:
                    cout << (colorChessPiece.color == WHITE ? "Rb" : "Rw");
                    break;
                case PAWN:
                    cout << (colorChessPiece.color == WHITE ? "Pb" : "Pw");
                    break;
            }
            cout << "]";
        }
        cout << endl;
    }
}