#include <iostream>
using namespace std;

int main() {
    const double PAYRATE_THRESHOLD = 18.00; //const is basically final in java
    const double HIGH_WITHHOLDING_RATE = 0.10;
    const double LOW_WITHHOLDING_RATE = 0.05;
    
    //gather input data
    cout << "How many hours did you work? ";
    double hoursWorked;
    cin >> hoursWorked;
    cout << "What's your hourly rate of pay? ";
    double payRate;
    cin >> payRate;

    //compute and print earnings
    double amtEarned = hoursWorked * payRate;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "You earned $" << amtEarned << endl;

    //compute and print withholding
    double withholdingRate;
    if (payRate > PAYRATE_THRESHOLD) {
        withholdingRate = HIGH_WITHHOLDING_RATE;
    } else {
        withholdingRate = LOW_WITHHOLDING_RATE;
    }
    cout << "$" << (withholdingRate * amtEarned) << " will be withheld." << endl;


    //==============================================================================================================================================
    int x = 10;
    if (x > 0) {
        cout << "Hello" << endl;
        cout << x << endl;
    } else {
        cout << "wow!" << endl;
        cout << x << endl;
    }


    //==============================================================================================================================================
    cout << "What's your name? ";
    string name;
    cin.ignore();
    getline(cin, name);
    if (name == "") {
        cout << "woops you forgot to enter in a name!" << endl;
    } else { 
        cout << "hello " << name << "!" << endl;
    }


    //==============================================================================================================================================
    string citizenship;
    int age;
    cout << "What's your citizenship? ";
    getline(cin, citizenship);
    cout << "What's your age? ";
    cin >> age;
    cin.ignore(10000, '\n');

    if (citizenship == "US") {
        if (age >= 18) {
            cout << "You can vote in US elections" << endl;
        } else {
            cout << "You can't vote in US elections" << endl;
        }
    } else {
        cout << "You aren't a us citizen" << endl;
    }

    /*
    || is or, && is and, && has higher priority than || so the and is calculated first rather than the or
    you can chain multiple && and/or ||'s together
    
    in && chains, the moment the program detects a false nothing else is compiled and it moves on, called "short circuit AND"
    so if (b != 0 && d != 0 && a/b + c/d < 10) prevents division by 0
    in || chains, the moment the program detects a true nothing else is compiled and it moves on, called "short circuit OR"

    in if statements, 0 is false and non-zero is true
    strings will compile to true as long as it isn't null, even ""

    you can use not or ! to reverse a boolean
    */

    //also the moment there are no more else statements in the original if statement, it's a new if/else statement
}