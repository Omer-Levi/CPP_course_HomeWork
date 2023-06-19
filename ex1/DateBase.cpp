//
// Created by omerl on 23/11/2022.
//

#include <sstream>
#include "DateBase.h"

DataBase::DataBase(int size, int dim) : count(0) {

    this->dim = dim;
    this->size = size;

    arryName = new string[this->size];
    arrayVector = new double* [this->size];
    for (int i = 0; i < this->size ; i++) {
        arrayVector[i] = new double [dim];
    }
}

//DataBase::~DataBase() {
//    for (int i = 0; i < size ; i++) {
//            delete []arrayVector[i];
//        }
//    delete []arrayVector;
//}

void DataBase::add() {
    double temp;
    bool flag = false;
    string inVec;
    stringstream s;
    string inName;
    
    cout << "Enter observation name:" << endl;
    cin >> inName;

    int j = 0;
    for (; j < count; j++) {
        if (inName == arryName[j]) {
            flag = true;
            break;
        }
    }

    if(!flag)
        arryName[count] = inName;

    cin.ignore();    // clear the cin buff
    cout << "Enter observation values:" << endl;
    getline(cin, inVec);

    int space = 0;
    for (char i : inVec) {
        if (i == ' ')
            space++;
    }

    if ((space+1) != this->dim){
        cerr << "Invalid observation." << endl;
        arryName[j] = "";
        return;
    }

    s << inVec;
    for (int i = 0; i < dim ; i++) {
        s >> temp;
        if (!flag)
            arrayVector[count][i] = temp;
        else
            arrayVector[j][i] = temp;
    }

    if (!flag)
    count++;
}


void DataBase::pull() {
    string name;
    cout << "Enter observation name:" << endl;
    cin >> name;

    for(int i=0; i<=count; i++){
        if(name == arryName[i]){
            cout << name << " = [";
            for(int j =0; j<dim; j++){
                cout << " " << arrayVector[i][j];
            }
            cout << "]\n";
            return;
        }
    }
    cerr << "Invalid or nonexistent observation.\n";


}

void DataBase::ex() {
    if(count == 0) {
        cerr << "Empty calculator.\n";
        return;
    }

    double* sum = new double[dim];

    for(int i = 0; i<count; i++){
        for(int j = 0; j<dim; j++ ){
            sum[j] += arrayVector[i][j];
        }
    }

    double* sumCov = new double [dim];
    for(int j =0; j<dim; j++){
        sumCov[j] = sum[j]/count;
    }

    cout << "mean = [";
    for(int j =0; j<dim; j++){
        cout << " " << sumCov[j];
    }
    cout << "]" << endl;

//    delete []sum;
//    delete []sumCov;
}


//void DataBase::exPrint() {
//    if(count == 0) {
//        cerr << "Empty calculator.\n";
//        return;
//    }
//
//    double * sumCov = ex();
//
//    cout << "mean = [";
//    for(int j =0; j<dim; j++){
//        cout << " " << sumCov[j];
//    }
//    cout << "]" << endl;
//}

void DataBase::cov() {

    if(count == 0) {
        cerr << "Empty calculator.\n";
        return;
    }

    double *sum = new double [dim];

    for(int i = 0; i<count; i++){
        for(int j = 0; j<dim; j++ ){
            sum[j] += arrayVector[i][j];
        }
    }

    double* sumCov = new double [dim];
    for(int j =0; j<dim; j++){
        sumCov[j] = sum[j]/count;
    }

    float **matrix = new float *[dim];

    for (int i = 0; i < dim; i++) {
        matrix[i] = new float[dim];
    }
    double s = 0;
    for (int i = 0; i < dim ; i++) {


        for (int j = 0; j < dim ; j++) {
            for (int k = 0; k < count; k++) {
                s += (arrayVector[k][i] - sumCov[i]) * (arrayVector[k][j] - sumCov[j]);
                }
            if(count > 1){
                matrix[i][j] = s/(count - 1);
            } else{
                matrix[i][j] = s/count;
            }
            s = 0;
            }


        }

    cout << "cov = [" << endl ;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim ; j++) {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
    cout << "]";
 }

DataBase::DataBase() {

}


