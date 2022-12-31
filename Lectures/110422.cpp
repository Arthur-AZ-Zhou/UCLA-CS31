#include <iostream>
#include <string>
#include <cstring>
using namespace std; 

bool charInsert(char str[], int n, int ind, char c);

int main() {
    const int N = 6;
    const int INDEX = 1;
    const char C = 'b';

    char initialString[N] = "aaaaa";

    cout << ((charInsert(initialString, N, INDEX, C) == 1)? "true" : "false") << " " << initialString << endl;
}

bool charInsert(char str[], int n, int ind, char c) {
    if (ind < 0 || n <= ind || (strlen(str) + 1) >= n) { //if ind negative or greater than n, or if no space to shift right
        return false;
    }

    for (int i = strlen(str); i > ind; i--) {
        str[i + 1] = str[i];
    }

    str[ind] = c;
    return true;
}