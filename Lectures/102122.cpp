#include <iostream>
#include <string>
using namespace std;

int reverse(int n);
int max3(int n1, int n2, int n3);
string reverseSentence(string sentence);
string toLowerCase(string str);

int main() {
    int num;
    cout << "Enter a number to reverse: ";
    cin >> num;
    cout << reverse(num) << endl;

    int n1, n2, n3;
    cout << "Enter student 1’s score: ";
    cin >> n1;
    cout << "Enter student 2’s score: ";
    cin >> n2;
    cout << "Enter student 3’s score: ";
    cin >> n3;
    cout << "The highest score out of these was " << max3(n1, n2, n3) << "!" 
        << ((max3(n1, n2, n3) > 100)? " Congratulations on your hard work!" : "") << endl;
    
    string sentence;
    cin.ignore();
    cout << "Enter a sentence to reverse: ";
    getline(cin, sentence);
    cout << reverseSentence(sentence) << endl;

    string str;
    cout << "Enter a string to make lower case: ";
    getline(cin, str);
    cout << toLowerCase(str) << endl;
}

int reverse(int n) {
    string nStr = to_string(n);
    string reverseNStr = "";

    for (int i = nStr.length() - 1; i >= 0; i--) {
        reverseNStr += nStr[i];
    }

    return stoi(reverseNStr);
}

int max3(int n1, int n2, int n3) {
    int max = n1;
    if (max < n2) {
        max = n2;
    } if (max < n3) {
        max = n3;
    }

    return max;
}

string reverseSentence(string sentence) {
    string returnSentence = "";
    string word = "";

    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' ' || i == sentence.length() - 1) { //find each word separator
            if (i == sentence.length() - 1) { //include final character
                word += sentence[i];
            }

            for (int j = word.length(); j >= 0; j--) {
                returnSentence += word[j];
            }
            returnSentence += " ";
            
            word = "";
            continue;
        }

        word += sentence[i];
    }

    return returnSentence;
}

string toLowerCase(string str) {
    string lowCaseStr = "";

    for (int i = 0; i < str.length(); i++) {
        lowCaseStr += tolower(str[i]);
    }

    return lowCaseStr;
}