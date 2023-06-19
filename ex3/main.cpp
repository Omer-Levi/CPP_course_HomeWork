#include <iostream>
#include <string>
#include "UniverseVirus.h"


int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cerr << "Usage: run the program with <init file name> <location file name>" << std::endl;
        exit(-1);
    }
    auto *u = new UniverseVirus(argv[1], argv[2]);
    u->init();

    delete u;

    return 0;
}
