//
// Created by omerl
//


#include "UniverseVirus.h"
#include "CVirus.h"


int UniverseVirus::dim;
int UniverseVirus::Pm;
CVirus* UniverseVirus::goal = nullptr;

UniverseVirus::UniverseVirus(const std::string &file1, const std::string &file2) {
    std::string line;
    std::ifstream outfile(file1);
    if(outfile.is_open()) {
        std::getline(outfile, line);
        dim = stoi(line);

        std::getline(outfile, line);
        Pm = stoi(line);
        std::getline(outfile, line);
        outfile.close();
    }
    else {
        std::cerr << "File not found." << std::endl;
    }
    std::string targetName = "goal";
    goal = new CVirus(targetName, strToArray(line));
    goal->setErrors(0);
    this->community = new SerchLinkedList();
    std::string line2;
    std::ifstream outfile2(file2);

    if(outfile2.is_open()) {
        std::getline(outfile2, line2);
        this->popSize = stoi(line2);
        std::string name;
        std::stringstream ss;
        while(std::getline(outfile2, line2)) {
            ss.str(line2);
            ss >> name;
            auto* v = new CVirus(name, strToArray(ss.str().erase(0, name.size()+1)));
            v->setErrors(v->errorsCalc());
            this->community->add(v);
        }
        outfile2.close();
    }
    else {
        std::cerr << "File not found." << std::endl;
    }
    this->excell = new CVirus(*this->community->get(0));
}

UniverseVirus::UniverseVirus(const UniverseVirus &other) {
    this->community = other.community;
    this->popSize = other.popSize;
    this->excell = other.excell;
}

UniverseVirus &UniverseVirus::operator=(const UniverseVirus &other) {
    if(this == &other) {
        return *this;
    }
    this->community = other.community;
    this->popSize = other.popSize;
    this->excell = other.excell;
    return *this;
}

UniverseVirus::~UniverseVirus() {
    delete goal;
    delete this->community;
    delete this->excell;
}

void UniverseVirus::init() {
    int num;
    std::cin >> num;
    for(int i = 0; i < num; i++) {
        if(community->get(0)->getErrors() == 0) {
            break;
        }
        (*community)++;
        erors();
    }
    community->print();
    printBest();
}

int *UniverseVirus::strToArray(const std::string &values) {
    std::stringstream ss(values);
    std::string val;
    int* arr = new int[dim];
    int i = 0;
    while(ss >> val) {
        arr[i] = stoi(val);
        i++;
    }
    if(i != dim) {
        std::cerr << "Invalid input." << std::endl;
        exit(-1);
    }
    return arr;
}

void UniverseVirus::erors() {
    auto *new_pop = new SerchLinkedList();
    for(int i = 0; i < community->size(); i++) {
        CVirus *v = community->get(i);
        *(*v);
        new_pop->add(v);
    }
    community = new_pop;
    if(new_pop->get(0)->getErrors() < excell->getErrors()) {
        excell = new CVirus(*new_pop->get(0));
    }

}

void UniverseVirus::printBest() {
    std::cout << "\n" << this->excell->getName();
    if(excell->getVersion() != 0) {
        std::cout << "_" + std::to_string(excell->getVersion());
    }
    std::cout << "\t";
    for(int i = 0; i < this->excell->getDim(); i++) {
        std::cout << this->excell->getValues()[i] << " ";
    }
    std::cout << std::endl;
}
