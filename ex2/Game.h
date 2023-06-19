//
// Created by omerl on 08/12/2022.
//

#ifndef EX22023_GAME_H
#define EX22023_GAME_H

#include "Kube.h"

using namespace std;


class Game {
public:
    Game(int size);
    void print_board();
    void start();
    void sign_flag();
    void sign_kube();
    void check_win();


private:
    int size;
    bool flag = true;
    int numIndex1;
    int numIndex2;
    Kube** arryBoard;
    int countRed, countBlue;
    int countO =0;
};


#endif //EX22023_GAME_H
