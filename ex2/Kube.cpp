//
// Created by omerl on 08/12/2022.
//


#include "Kube.h"


Kube::Kube() {
    this->kube = 'O';
    this->redFlag = false;
    this->blueFlag = false;

}

bool Kube::isRedFlag() const {
    return redFlag;
}

void Kube::setRedFlag(bool redFlag) {
    Kube::redFlag = redFlag;
}

bool Kube::isBlueFlag() const {
    return blueFlag;
}

void Kube::setBlueFlag(bool blueFlag) {
    Kube::blueFlag = blueFlag;
}

char Kube::getKube() const {
    return kube;
}

void Kube::setKube(char kube) {
    Kube::kube = kube;
}