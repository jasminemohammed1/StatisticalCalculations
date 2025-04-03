

#ifndef PROBLEM5_STATISTICALCALCULATIONS_H
#define PROBLEM5_STATISTICALCALCULATIONS_H
using namespace std;
#include<iostream>

template <typename T>
class StatisticalCalculations{
private:
    int size;
    T*data;
    bool readfromfile;
    ifstream *inputfilestream;
public:
    StatisticalCalculations(int sz);
    ~StatisticalCalculations();
    void Sort();
    void setfile(ifstream*fileStream);
    double Findmedian();
    T FindMin();
    T FindMax();
    double FindMean();
    T Findsummation();
    void displayArray();
    void inputData();
    void StatisticalMenue();




};



#endif //PROBLEM5_STATISTICALCALCULATIONS_H
