#include <iostream>
#include <string>
using namespace std;

int main() {
    //constants so don't have to replace every single variable
    const int FIRST_BRACKET = 55000;
    const int SECOND_BRACKET = 125000;
    const double LOW_RATE = 0.04;
    const double MED_RATE = 0.07;
    const double MED_SPEC_RATE = 0.05;
    const double HIGH_RATE = 0.093;
    const double CHILD_TAX_DEDUCTION = 200.00;
    string name;
    double income;
    string occupation;
    int numChild;
    double amtOwed = 0.00;

    //get the inputs, define variables
    cout << "Name: ";
    getline(cin, name);
    if (name == "") {
        cout << "---" << endl;
        cout << "You must enter a name" << endl;
        return 0;
    }
    cout << "Taxable income: ";
    cin >> income;
    if (0 > income) {
        cout << "---" << endl;
        cout << "The taxable income must not be negative" << endl;
        return 0;
    }
    cin.ignore(); //ignore whitespace after cin for integer
    cout << "Occupation: ";
    getline(cin, occupation);
    if (occupation == "") {
        cout << "---" << endl;
        cout << "You must enter an occupation" << endl;
        return 0;
    }
    cout << "Number of children: ";
    cin >> numChild;
    if (0 > numChild) {
        cout << "---" << endl;
        cout << "The number of children must not be negative" << endl;
        return 0;
    }
    cout << "---" << endl; //print the 3 -

    //calculate amtOwed
    if (FIRST_BRACKET >= income) {
        amtOwed = income * LOW_RATE;
    } else if (SECOND_BRACKET >= income) {
        if (occupation == "nurse" || occupation == "teacher") {
            amtOwed = (FIRST_BRACKET * LOW_RATE) + (income - FIRST_BRACKET) * MED_SPEC_RATE;
        } else {
            amtOwed = (FIRST_BRACKET * LOW_RATE) + (income - FIRST_BRACKET) * MED_RATE;
        }
    } else { //if income > SECOND_BRACKET
        if (occupation == "nurse" || occupation == "teacher") {
            amtOwed = (FIRST_BRACKET * LOW_RATE) + ((SECOND_BRACKET - FIRST_BRACKET) * MED_SPEC_RATE) + ((income - SECOND_BRACKET) * HIGH_RATE);
        } else {
            amtOwed = (FIRST_BRACKET * LOW_RATE) + ((SECOND_BRACKET - FIRST_BRACKET) * MED_RATE) + ((income - SECOND_BRACKET) * HIGH_RATE);
        }
    }

    //calculate child deduction
    if (SECOND_BRACKET > income) {
        amtOwed -= numChild * CHILD_TAX_DEDUCTION;
    }
    if (0 > amtOwed) { //can't go below 0
        amtOwed = 0;
    }

    //print final amt out
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << name << " would pay $" << amtOwed << endl;
}