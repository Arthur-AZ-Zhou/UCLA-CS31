#include <iostream>
#include <string>
using namespace std;

double calcCircleArea(double diameter) {
    double radius = diameter / 2;
    double pi = 3.14159265;

    double area = pi * radius * radius;
    return area;
}

double calcCylinderVol(double diameter, double height); //function declaration, can define after

int main() {
    double diameter;
    cout << "What diameter of cylinder do you want (in)? " << endl;
    cin >> diameter;
    cout << "The base/circle area is " << calcCircleArea(diameter) << " square inches" << endl;

    double height;
    cout << "What height of cylinder do you want (in)? " << endl;
    cin >> height;
    cout << "The volume is " << calcCylinderVol(diameter, height) << " cubic inches" << endl;

    //void means no return, usually used for just printing text

    //modular functions are when you call another function in another function, like calling calcCircleArea() in calcCylinderVol()

    //testing a small part of the program (typicaly a function) is called unit testing
    //the testbench/test harness is a separate program used to check that a function returns correct output values 
    //each unique test is called a test vector

    //variables defined in functions local variables, variables defined outside any function is global variable
    //when a function alters a global variable, you might get unwanted side effects 
}

double calcCylinderVol(double diameter, double height) { 
    return calcCircleArea(diameter) * height;
}