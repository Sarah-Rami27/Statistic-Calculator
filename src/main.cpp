#include <iostream>
#include <string>
#include "Calculations.h"

using namespace std;


int main(){

    cout << "\nThis calculator will sort your data, find mean, median, mode, Variance, Standard Deviation, IQR, and quartiles." << endl;
    Calculations userData;
    cout << "\nEnter your data, enter q when done\n" << endl;
    userData.fillArray();

    return 0;
}

