#include <iostream>
#include "chess.h"
void writeBoard(const ChessBoard& chessBoard);

int main() {
    int y1,y2;
    char q1,q2;
    int x1,x2;
    Chess chess(BLACK);
    while (/*!chess.maat_or_paat()*/true) {
        writeBoard(chess.getChessBoard());
        cin >> q1>> y1 >> q2 >> y2;
        switch (q1) {
            case 'a':
                x1 = 0;
                break;
            case 'b':
                x1 = 1;
                break;
            case 'c':
                x1=2;
                break;
            case 'd':
                x1=3;
                break;
            case 'e':
                x1=4;
                break;
            case 'f':
                x1=5;
                break;
            case 'g':
                x1=6;
                break;
            case 'h':
                x1=7;
                break;



        }
        switch (q2) {
            case 'a':
                x2 = 0;
                break;
            case 'b':
                x2 = 1;
                break;
            case 'c':
                x2=2;
                break;
            case 'd':
                x2=3;
                break;
            case 'e':
                x2=4;
                break;
            case 'f':
                x2=5;
                break;
            case 'g':
                x2=6;
                break;
            case 'h':
                x2=7;
                break;
        }



        if (chess.canMove(y1-1,x1 ,y2-1 ,x2 )) {
            chess.move( y1-1,x1 ,y2-1 ,x2 );
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
    cout << "  A    B   C   D   E   F   G   H "<<endl;
    int i=1;
    for (const ChessLine& chessLine : chessBoard) {
        cout << i;
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
        cout<<i;
        i++;

        cout << endl;
    }
    cout << "  A    B   C   D   E   F   G   H " << endl;
}
