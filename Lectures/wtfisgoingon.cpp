#include <iostream>
#include <string>
using namespace std; 

int lengthOfLastWord(string s) {
    int len = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            len++;
        } else {
            return len;
        }
    }

    return len;
}

int main() {
    
}