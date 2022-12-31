#include <iostream>
#include <string>
using namespace std;

int main() {
    //you know while and for loops
    int maxSoFar;
    int currValue;
    int numValues;
   
    cin >> numValues;
   
    for (int i = 0; i < numValues; i++) {
        cin >> currValue;
        
        if (i == 0) { // First iteration
            maxSoFar = currValue;
        } else if (currValue > maxSoFar) {
            maxSoFar = currValue;
        }
    }
    
    if (numValues > 0) {
        cout << "Max: " << maxSoFar << endl;
    }
    
    char letter1;
    char letter2;
   
    cout << "Two-letter domain names:" << endl;
   
    letter1 = 'a';
    while (letter1 <= 'z') {
        letter2 = 'a';
        while (letter2 <= 'z') {
            cout << letter1 << letter2 << ".com" << endl;
            letter2++;
        }

        letter1++;
   }

   //break breaks loop completely (only breaks INSIDE loop if nested loop, outside loop still happens), continue brings you to next loop iteration
}