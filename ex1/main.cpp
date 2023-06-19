#include <iostream>
#include "DateBase.h"

using namespace std;



int main(int argc, char *argv[]) {
    int choice;

//    if(!(isNumeric(argv[1]) && isNumeric(argv[2]))){
//        cerr << "Invalid arguments <int> <int>." << endl;
//        exit(-1);

    if(argc != 3) {
        cerr << "Invalid arguments <int> <int>." << endl;
        exit(-1);
    }
//    stringstream s1(argv[1]); // convert arguments from string to int
//    stringstream s2(argv[2]);
//    int x = 0, y = 0;
//
//    s1 >> x;
//    s2 >> y;

    DataBase db(stoi(argv[2]), stoi(argv[1]));


    cout << "[1] New observation\n"
            "[2] Print observation\n"
            "[3] Expected value vector\n"
            "[4] Covariance matrix\n"
            "[5] Exit" << endl;
    while (cin >> choice) {

        if(choice == 1){
            db.add();
        }

        if (choice == 2){
            db.pull();
        }

        if(choice == 3){
            db.ex();
        }

        if(choice == 4){
            db.cov();
        }

        if (choice == 5){
            break;
        }
    }


    return 0;
}
