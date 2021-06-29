#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include "../header/Calculations.h"

using namespace std;

Calculations::Calculations(){
    arrSize = 0;
    mean = 0;
    median = 0;
    mode = 0;
    variance = 0;
    standardDeviation = 0;
    Q3 = 0;
    Q1 = 0;
    IQR = 0;
}

void Calculations::fillArray(){
    string dataNum;

    cin >> dataNum;
    while(dataNum != "d"){
        data[arrSize] = stod(dataNum);
        ++arrSize;
        cin >> dataNum;
    }
    calculations();
}

void Calculations::calculations(){
    cout << setw(37);
    cout << endl << endl;
    cout << "Your Data" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Data Size: " << arrSize << endl;

    cout << "\nSorted Data: ";
    displaySortedData();

    mean = calculateMean();
    cout << "\nMean: " << mean << endl;

    median = calculateMedian();
    cout << "\nMedian: " << median << endl;

    mode = calculateMode(); //mode given is the "smallest" mode (e.g. 1 1 1 2 2 2 -- 1 would be mode here)
    cout << "\nMode: ";
    if(mode == false){
        cout << "This data set contains no mode." << endl;
    }
    else{
        for(int i = 0; i < modes.size(); ++i){
            cout << modes.at(i) << " ";
        }
        cout << endl;
    }

    standardDeviation = calculateStandardDev();
    cout << "\nStandard Deviation: " << standardDeviation << endl;

    variance = calculateVariance();
    cout << "\nVariance: " << variance << endl;

    Q1 = calculateQ1();
    cout << "\nQ1: " << Q1 << endl;

    cout << "\nQ2: " << median << endl;

    Q3 = calculateQ3();
    cout << "\nQ3: " << Q3 << endl;

    IQR = calculateIQR();
    cout << "\nIQR: " << IQR << endl;
    cout << endl;

}

double Calculations::calculateMean(){
   double total = 0.0;
   double average = 0.0;

   for(int i = 0; i < arrSize; ++i){
        total += data[i];
    } 
    average = total / arrSize;
    return average;
}

double Calculations::calculateMedian(){
    if(arrSize % 2 != 0){
        return data[arrSize / 2];
    }
    return (data[(arrSize - 1) / 2] + data[arrSize / 2]) / 2.0;
}

bool Calculations::calculateMode(){ //only gives one mode (for now) -- now gives more than one!!
    double dataNum = data[0];
    double Mode = dataNum;
    int counter = 1;
    int modeCounter = 1;
    bool modePresent = false;

    for(int i = 1; i < arrSize; ++i){
        if(dataNum == data[i]){
            ++counter;
        }
        else{
            if(counter > modeCounter){
                modeCounter = counter;
                Mode = dataNum;
                modes.clear();
                modes.push_back(Mode);
                modePresent = true;
            }
            else if(counter == modeCounter){
                modes.push_back(dataNum);
                modePresent = true;
            }
            counter = 1;
            dataNum = data[i];
        }
    }
    //the above code does not give the correct mode if the mode is the last element
    //the code below checks that the last element is/is not the mode
    if(data[arrSize - 2] == data[arrSize - 1]){
        if(counter > modeCounter){
            Mode = dataNum;
            modes.clear();
            modes.push_back(data[arrSize - 1]); 
            modePresent = true;
        }
        else{
            modes.push_back(dataNum);
            modePresent = true;
        }
    }

    if(modeCounter == 1){ //there is no mode
        modePresent = false;
    }

    return modePresent;
}

double Calculations::calculateVariance(){
    double sumSquared = 0;//(x^2)
    double squaredSum = 0;//(x)^2
    double Variance = 0;

    for(int i = 0; i < arrSize; ++i){
        sumSquared = sumSquared + pow(data[i], 2);
        squaredSum = squaredSum + data[i];
    }
    squaredSum = pow(squaredSum, 2);

    Variance = (sumSquared - (squaredSum / arrSize)) / (arrSize - 1);
    return Variance;
}

double Calculations::calculateStandardDev(){
    double stanDev = 0;
    stanDev = sqrt(calculateVariance());
    return stanDev;
}

double Calculations::calculateQ3(){
    double position = 0;
    double decimal = 0;
    double q3 = 0;
    double q3Position = 0;

    position = (3.0 / 4.0) * (arrSize + 1); 
    decimal = modf(position, &q3Position);

    q3 = data[(int)q3Position - 1] +  decimal * (data[(int)q3Position] - data[(int)q3Position - 1]);

    return q3;
}

double Calculations::calculateQ1(){
    double position = 0;
    double decimal = 0;
    double q1 = 0;
    double q1Position = 0;

    position = (1.0 / 4.0) * (arrSize + 1); 
    decimal = modf(position, &q1Position);

    q1 = data[(int)q1Position - 1] +  decimal * (data[(int)q1Position] - data[(int)q1Position - 1]);

    return q1;
}

double Calculations::calculateIQR(){
    return calculateQ3() - calculateQ1();
}

void Calculations::displaySortedData(){
    sort (data, data + arrSize);
    for(int i = 0; i < arrSize; ++i){
        cout << data[i] << "  ";
    }
    cout << endl;
}