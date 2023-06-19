//
// Created by omerl on 08/12/2022.
//

#ifndef EX22023_KUBE_H
#define EX22023_KUBE_H


using namespace std;


class Kube {
public:
    Kube();
    char getKube() const;
    void setKube(char kube);

    bool isRedFlag() const;

    void setRedFlag(bool redFlag);

    bool isBlueFlag() const;

    void setBlueFlag(bool blueFlag);


private:
    char kube;
    bool redFlag;
    bool blueFlag;


};


#endif //EX22023_KUBE_H
