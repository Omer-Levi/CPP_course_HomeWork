//
// Created by omerl
//

#ifndef HW4_CVIRUS_H
#define HW4_CVIRUS_H

#include <iostream>
#include <string>


class CVirus {
public:
    CVirus(std::string name, int* values);
    CVirus(const CVirus& other);
    CVirus& operator = (const CVirus& other);
    ~CVirus();
    CVirus(CVirus&& other) noexcept;
    CVirus& operator = (CVirus&& other) noexcept;
    void operator*();
    bool compareTo(CVirus* v);
    const std::string &getName() const;
    int *getValues() const;
    double getErrors() const;
    int getVersion() const;
    int getDim() const;
    int *getId() const;
    void setValues(int *values);
    void setErrors(double errors);
    void setVersion(int version);
    void incrementId();
    double errorsCalc() const;


private:
    std::string name;
    int* values;
    double errors;
    int dim;
    int version;
    int counter;
    int* id;




};




#endif //HW4_CVIRUS_H
