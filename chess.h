
#ifndef PROJECT_CHESS_H
#define PROJECT_CHESS_H
#endif //PROJECT_CHESS_H

using namespace std;

class chess {
public:
    bool canmove(char x, int y);
    bool cango(char x,int y);
    void move(char x1,int y1,char x2,int y2);
    bool kish();
    bool mat();
};