//
// Created by omerl
//

#include "CVirus.h"
#include <utility>
#include "UniverseVirus.h"


CVirus::CVirus(std::string name, int *values) {
    this->name = std::move(name);
    this->dim = UniverseVirus::dim;
    this->values = values;
    this->errors = 1;
    this->version = 0;
    this->counter = 0;
    this->id = &counter;
}

CVirus::CVirus(const CVirus &other) {
    this->name = other.name;
    this->errors = other.errors;
    this->dim = other.dim;
    this->counter = other.counter;
    this->version = other.version;
    this->id = other.id;
    this->values = new int[dim];
    for(int i = 0; i < dim; i++) {
        this->values[i] = other.values[i];
    }
}

CVirus &CVirus::operator=(const CVirus &other) {
    if(this == &other) {
        return *this;
    }
    this->name = other.name;
    this->errors = other.errors;
    this->dim = other.dim;
    this->counter = other.counter;
    this->version = other.version;
    this->id = other.id;
    delete[] this->values;
    this->values = new int[dim];
    for(int i = 0; i < dim; i++) {
        this->values[i] = other.values[i];
    }
    return *this;
}

CVirus::~CVirus() {
    delete[] this->values;
    delete this->id;
}

CVirus::CVirus(CVirus &&other) noexcept {
    this->name = other.name;
    this->errors = other.errors;
    this->values = other.values;
    this->dim = other.dim;
    this->counter = other.counter;
    this->version = other.version;
    this->id = other.id;
}

CVirus &CVirus::operator=(CVirus &&other) noexcept{
    if(this == &other) {
        return *this;
    }
    this->name = other.name;
    this->errors = other.errors;
    this->dim = other.dim;
    this->counter = other.counter;
    this->version = other.version;
    this->id = other.id;
    delete[] this->values;
    this->values = other.values;
    return *this;
}
void CVirus::operator*() {
    int index1 = rand() % dim;
    int index2 = rand() % dim;
    int * arr = this->getValues();
    for(int j = 0; j < UniverseVirus::Pm; j++) {
        std::swap(arr[index1], arr[index2]);
    }
    this->setValues(arr);
    this->setErrors(this->errorsCalc());
}

bool CVirus::compareTo(CVirus *v) {
    if(this->name == v->getName() && this->version == v->getVersion()) {
        return true;
    }
    return false;
}

const std::string &CVirus::getName() const {
    return name;
}

int *CVirus::getValues() const {
    return values;
}

double CVirus::getErrors() const {
    return errors;
}

int CVirus::getVersion() const {
    return version;
}

int CVirus::getDim() const {
    return dim;
}

int *CVirus::getId() const {
    return id;
}

void CVirus::setValues(int *value) {
    CVirus::values = value;
}

void CVirus::setErrors(double error) {
    CVirus::errors = error;
}

void CVirus::setVersion(int versio) {
    CVirus::version = versio;
}

void CVirus::incrementId() {
    (*this->id)++;
}

double CVirus::errorsCalc() const {
    int* targetVec = UniverseVirus::goal->getValues();
    int* vVec = this->getValues();
    int size = this->getDim();
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(targetVec[i] == vVec[i]) {
            count++;
        }
    }
    double errorss = 1;
    errorss -= (double)count / size;
    return errorss;
}

