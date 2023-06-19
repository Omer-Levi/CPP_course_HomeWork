//
// Created by omerl
//

#ifndef HW4_UNIVERSEVIRUS_H
#define HW4_UNIVERSEVIRUS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "CVirus.h"
#include "SerchLinkedList.h"

class UniverseVirus {
public:
    static CVirus* goal;
    static int dim;
    static int Pm;
    UniverseVirus(const std::string& file1, const std::string& file2);
    UniverseVirus(const UniverseVirus& other);
    UniverseVirus& operator=(const UniverseVirus& other);
    ~UniverseVirus();
    void init();


private:
    SerchLinkedList* community;
    int popSize;
    CVirus* excell;

    static int* strToArray(const std::string& values);
    void erors();
    void printBest();


};


#endif //HW4_UNIVERSEVIRUS_H
