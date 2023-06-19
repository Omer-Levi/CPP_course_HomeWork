//
// Created by omerl on 08/12/2022.
//

#include "Game.h"
#include <iostream>
#include <sstream>
#include "Kube.h"


using namespace std;

Game::Game(int size) : numIndex1(0), numIndex2(0) ,countRed(0), countBlue(0){
    this-> size = size;

    arryBoard = new Kube* [this->size];
    for (int i = 0; i < this->size; i++){
        arryBoard[i] = new Kube[this->size];

    }
}

void Game::print_board() {
    check_win();
    countO = 0;
    cout << "Red count: " << countRed << "\tBlue count: "<< countBlue <<"\n";
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size ; j++) {
            cout << arryBoard[i][j].getKube() << "\t";
            if(arryBoard[i][j].getKube() != 'O'){
                countO++;
            }
        }
        cout << "\n";
    }

}



void Game::start() {
    print_board();

    while (true){
        if(countO == size*size){
            if(countBlue == countRed){
                cout << "The game ended with a tie\n";
                return;
            }
            if(countRed > countBlue){
                cout << "Red won\n";
                return;
            }
            if (countRed < countBlue){
                cout << "Blue won\n";
                return;
            }
        }
        countRed = 0;
        countBlue = 0;
        int num1 = 0, num2 = 0;
        if(flag){
            cout << "R:\n";
        } else{
            cout<<"B:\n";
        }
        string inNum;
        stringstream s;
        getline(cin, inNum);
        s<<inNum;
        s>>num1;
        s>>num2;
        numIndex1 = num1 -1;
        numIndex2 = num2 -1;

        if((num1 <= size) && (num2 <= size)) {
            if ((arryBoard[num1 - 1][num2 - 1].getKube() == 'O')) {

                if (flag) {
                    arryBoard[num1 - 1][num2 - 1].setKube('R');
                } else {
                    arryBoard[num1 - 1][num2 - 1].setKube('B');
                }
                sign_kube();
                sign_flag();
                print_board();

                flag = !flag;
            } else{
                cerr << "Invalid row/col index or non free cell\n";
            }
        }
        else{
            cerr << "Invalid row/col index or non free cell\n";
        }

    }



}

void Game::sign_flag() {
    numIndex1 = numIndex1 +1;
    numIndex2 = numIndex2 +1;

    for (int i = 0; i < 3; i++) {
        if(numIndex1 < 0){
            break;
        }
        for (int j = 0; j < 3; j++) {
            if ((numIndex1 - i) < 0 || (numIndex2 - j) < 0 || (numIndex1 - i) >= size || (numIndex2 - j) >= size){
                continue;
            }
            if(numIndex2 < 0){
                break;
            }
            if(arryBoard[numIndex1-i][numIndex2-j].getKube() != 'R' && arryBoard[numIndex1-i][numIndex2-j].getKube() != 'B') {
                if (flag) {
                    arryBoard[numIndex1 - i][numIndex2 - j].setRedFlag(true);
                } else {
                    arryBoard[numIndex1 - i][numIndex2 - j].setBlueFlag(true);
                }
            }

        }
    }
    numIndex1 = numIndex1 -1;
    numIndex2 = numIndex2 -1;
}



void Game::sign_kube() {
    numIndex1 = numIndex1 +1;
    numIndex2 = numIndex2 +1;



    for (int i = 0; i < 3; i++) {
        if(numIndex1 < 0){
            break;
        }
        for (int j = 0; j < 3; j++) {
            if ((numIndex1 - i) < 0 || (numIndex2 - j) < 0 || (numIndex1 - i) >= size || (numIndex2 - j) >= size) {
                continue;
            }
            if(numIndex2 < 0){
                break;
            }
            if(arryBoard[numIndex1 - i][numIndex2 - j].getKube() == 'b' || arryBoard[numIndex1 - i][numIndex2 - j].getKube() == 'r'){
                arryBoard[numIndex1 - i][numIndex2 - j].setKube('X');
            }

            if(flag){
                if(arryBoard[numIndex1 - i][numIndex2 - j].isRedFlag() && arryBoard[numIndex1 - i][numIndex2 - j].getKube() == 'O'){
                    arryBoard[numIndex1 - i][numIndex2 - j].setKube('X');
                }
                if(arryBoard[numIndex1 - i][numIndex2 - j].isBlueFlag() && arryBoard[numIndex1 - i][numIndex2 - j].getKube() == 'O'){
                    arryBoard[numIndex1 - i][numIndex2 - j].setKube('r');
                }
            } else{
                if(arryBoard[numIndex1 - i][numIndex2 - j].isBlueFlag() && arryBoard[numIndex1 - i][numIndex2 - j].getKube() == 'O'){
                    arryBoard[numIndex1 - i][numIndex2 - j].setKube('X');
                }
                if(arryBoard[numIndex1 - i][numIndex2 - j].isRedFlag() && arryBoard[numIndex1 - i][numIndex2 - j].getKube() == 'O'){
                    arryBoard[numIndex1 - i][numIndex2 - j].setKube('b');
                }
            }


        }
    }
    numIndex1 = numIndex1 -1;
    numIndex2 = numIndex2 -1;
}

void Game::check_win() {
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size ; j++) {
            if(arryBoard[i][j].getKube() == 'r'){
                countRed++;
            }
            if(arryBoard[i][j].getKube() == 'b'){
                countBlue++;
            }
        }
    }
}




