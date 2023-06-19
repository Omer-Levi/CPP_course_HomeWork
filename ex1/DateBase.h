//
// Created by omerl on 17/11/2022.
//


#ifndef HW1CPP_DATABASE_H
#include <iostream>
using std::string;
using namespace std;



#define HW1CPP_DATABASE_H


class DataBase {


public:

    DataBase();

    DataBase(int size, int dim);
    void add();
    void pull();
    void ex();
    void cov();
//    ~DataBase();


private:
    string* arryName;
    double** arrayVector;


    int count;
    int dim;
    int size;
};


#endif //HW1CPP_DATABASE_H
