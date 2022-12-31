#include <iostream>
using namespace std;

int main() {
    int choice;
    cin >> choice;

    switch (choice){ //if doesn't fall into any category, goes default. If no default you just skip the whole switch thing
        case 1:
            cout << "Do thing A" << endl;
            break;
        case 2: //case 2 and case 4 will be treated same, like or
        case 4: 
            cout << "Do thing B" << endl;
            break; //if you forget the break the switch falls through to the next case
        case 3: //case 3 and 5 will be treated same
        case 5:
            cout << "Do thing C" << endl;
            break;
        default: 
            cout << "Choice must be 1 to 5" << endl;
            cout << "I'll assume you wanted choice 1" << endl;
            cout << "Do thing A" << endl;
    }

    /*
    switch statements can only be used to test exact equality, you can't test with strings, greater than less than, doubles, etc.
    As a result switch is for very niche scenarios
    */

    int n = 100;
    while (n > 0){ //you can make infinite loops (duh)
        cout << n << " bottles of beer on the wall " << n << " bottles of beer! Take one down, pass it around, " 
        << n - 1 << " bottles of beer on the wall!" << endl;
        n--;
    }
    //Remember +=, *=, /=, ++, --, etc.

    for (int i = 1; i < 100; i++) { //you know for loops bruh
        cout << "Hello " << i << endl;
    }
}