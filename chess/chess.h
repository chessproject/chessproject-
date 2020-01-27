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
    void initializeChessBoard();
public:
    Chess();
    Color turn;
    ChessBoard chessBoard;
    explicit Chess(Color turn);
    ChessBoard getChessBoard();
    static bool validPosition(int x, int y);
    ChessPiece getPiece(int x, int y);
    Color getColor(int x, int y);
    Position getKing(Color player);
    bool isOpponent(int x, int y);
    bool isEmpty(int x, int y);
    bool canGo(int x, int y,Color co);
    vector<Position> getPossibleMoves(int x, int y, Color c);
    bool isPossibleMove(int x1, int y1, int x2, int y2);
    bool canMove(int x, int y);
    bool canMove(int x1, int y1, int x2, int y2);
    void move(int x1, int y1, int x2, int y2);
    bool kish(Color col);
    bool maat_or_paat(Color col);
    //void addtoPossibleMoves(int x,int y);
};