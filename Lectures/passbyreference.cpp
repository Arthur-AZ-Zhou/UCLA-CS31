#include <iostream>
#include <string>
using namespace std;

void ConvHrMin(int timeVal, int& hrVal, int& minVal) { //if you put a & it's a pass by reference, refers to variable's memory location
    hrVal  = timeVal / 60;  
    minVal = timeVal % 60;
}

//pass by references should be used sparingly bc it can get confusing

int main() {
    int totTime;
    int usrHr;
    int usrMin;

    totTime = 0;
    usrHr = 0;
    usrMin = 0;

    cout << "Enter total minutes: ";
    cin >> totTime;

    ConvHrMin(totTime, usrHr, usrMin);

    cout << "Equals: ";
    cout << usrHr << " hrs ";
    cout << usrMin << " mins" << endl;

    int usrValInt;
    int& usrValRef = usrValInt;  // Refers to usrValInt, usrValRef points to usrValInt

    cout << "Enter an integer: ";
    cin  >> usrValInt;

    cout << "We wrote your integer to usrValInt." << endl;
    cout << "usrValInt is: " << usrValInt << "." << endl;
    cout << "usrValRef refers to usrValInt, and is: " << usrValRef << "." << endl;

    usrValInt = 99;
    cout << endl << "We assigned usrValInt with 99." << endl;
    cout << "usrValInt is now: " << usrValInt << "." << endl;
    cout << "usrValRef is now: " << usrValRef << "." << endl;
    cout << "Note that usrValRef refers to usrValInt, so it changed too." << endl;
}