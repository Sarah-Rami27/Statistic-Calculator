#include <iostream>
#include <string>
#include "../header/Calculations.h"

using namespace std;


int main(){

    cout << "\nThis calculator will sort your data, find mean, median, mode, Standard Deviation, Variance, IQR, and quartiles." << endl;
    Calculations userData;
    cout << "\nEnter your data, enter d when done\n" << endl;
    userData.fillArray();

    return 0;
}

