#include <iostream>
#include "chess.h"
void writeBoard(const ChessBoard& chessBoard);

int main() {
    Chess chess(BLACK);
    int a;
    int b;
    int c;
    int d;
    cin >> a >> b >> c >> d;
    if (chess.canMove(a, b, c, d)){
        chess.move(a, b, c, d);
        chess.turn = chess.turn == WHITE ? BLACK : WHITE;
}
//    while (!mat()) {
//        writeboard()
//        cin >> a >> b;
//        if (!canmove(a, b)) {
//            cout << "this ... cannot move\nchose something else" << a << "\n" << b;
//            cin >> a >> b;
//        }
//        cin >> c >> d;
//        if (!cango(c, d)) {
//            cout << "chose somewhere else";
//            cin >> c >> d;
//        }
//        move(a, b, c, d);
//    }
    writeBoard(chess.getChessBoard());

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
