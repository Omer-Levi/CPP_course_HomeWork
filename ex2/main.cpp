#include <iostream>
#include "Game.h"

using namespace std;

int main(int argc, char *argv[]) {

    if(argc != 2) {
        cerr << "Invalid run arguments; run the game with board size.\n";
        exit(-1);
    }

    Game* bo;
    bo = new Game(stoi(argv[1]));
    bo->start();
    return 0;
}

