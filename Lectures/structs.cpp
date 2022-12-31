#include <iostream>
#include <string>
using namespace std; 

struct Birthday {
    int month;
    int day;
}; //you need ; after struct

struct PatientData {
    int heightInches;
    int weightPounds;
};

struct TimeHrMin {
    int hourValue;
    int minuteValue;
};

TimeHrMin ConvHrMin(int totalTime) { //can return a struct, even parameters can be structs
    TimeHrMin timeStruct;

    timeStruct.hourValue  = totalTime / 60;
    timeStruct.minuteValue = totalTime % 60;

    return timeStruct;
}

int main() {
    //a struct is almost a class but all variables are public by default instead of private
        //same applies to their children aka member structs/classes
    //classes are used for data abstraction and inheritance while structs are used for data grouping

    Birthday annBirthday;
    annBirthday.month = 5;
    annBirthday.day = 10;

    cout << "Ann: " << annBirthday.month << "/" << annBirthday.day << endl;

    PatientData lunaLovegood;
    cout << "enter height in inches: ";
    cin >> lunaLovegood.heightInches;
    cout << "enter weight in lbs: ";
    cin >> lunaLovegood.weightPounds;

    cout << "Patient data: " << lunaLovegood.heightInches << " in, " << lunaLovegood.weightPounds << " lbs" << endl;

    int inTime;
    TimeHrMin travelTime;
    cout << "Enter total minutes: ";
    cin >> inTime;

    travelTime = ConvHrMin(inTime); //returns a struct
    cout << "Equals: ";
    cout << travelTime.hourValue << " hrs ";
    cout << travelTime.minuteValue << " mins" << endl;
}