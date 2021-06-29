#ifndef _CALCULATIONS_H_
#define _CALCULATIONS_H_

#include <iostream>
#include <vector>

const int ARR_CAPACITY = 50000;

class Calculations{
    private:
        double data[ARR_CAPACITY];
        std::vector<double> modes;
        int arrSize;
        double mean;
        double median;
        double mode;
        double variance;
        double standardDeviation;
        double Q3;
        double Q1;
        double IQR;

    public:
        Calculations();
        void calculations();
        void fillArray();
        void displaySortedData();
        double calculateMean();
        double calculateMedian();
        bool calculateMode();
        double calculateVariance();
        double calculateStandardDev();
        double calculateQ3();
        double calculateQ1();
        double calculateIQR();
};

#endif 