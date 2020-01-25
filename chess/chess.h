#include <vector>
using namespace std;

enum Color {
    WHITE,
    BLACK
};

enum ChessPiece {
    NONE,
    KING,
    QUEEN,
    BISHOP,
    KNIGHT,
    ROOK,
    PAWN
};

class ColorChessPiece {
public:
    ChessPiece piece;
    Color color;
    ColorChessPiece(ChessPiece piece, Color color);
};

typedef vector<ColorChessPiece> ChessLine;
typedef vector<ChessLine> ChessBoard;
typedef pair<int, int> Position;

class Chess {
private:
    ChessBoard chessBoard;
    Color turn;
    void initializeChessBoard();
public:
    Chess();
    bool validPosition(int x, int y);
    ChessBoard getChessBoard();
    ChessPiece getPiece(int x, int y);
    Color getColor(int x, int y);
    vector<Position> getPossibleMoves(int x, int y);
    bool isEmpty(int x, int y);
    bool canMove(int x, int y);
    bool canGo(char x,int y);
    void move(char x1,int y1,char x2,int y2);
    bool kish();
    bool mat();
};
