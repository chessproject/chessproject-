#include <stdio.h>
#include <iostream>
#include "chess.h"
#include "writeboard.h"
int main() {
    char a;
    int b;
    char c;
    int d;
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
    writeboard();
    cout << "mat!";
    return 0;
}
