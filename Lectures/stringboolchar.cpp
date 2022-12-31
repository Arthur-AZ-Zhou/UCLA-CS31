#include <iostream>
#include <string>
#include <cctype> //library for characters
#include <math.h> //library for math
using namespace std;

int main() {
    char isCharDigit = '1';
    cout << "isCharDigit a digit? " << (isdigit(isCharDigit)? "Yes" : "No") << endl; //check isCharDigit a digit

    //order of operations: (), !, arithmetic, < > <= >=, == !=, &&, ||
    //see 100522 for switch statements

    bool isSmart = true;
    bool isHandsome = true;
    if (isSmart && isHandsome) {
        cout << "You are probably talking about Arthur!" << endl;
    } else {
        cout << "ur weird" << endl;
    }

    //strings have values for upper and lowercase: A is 65, B is 66, a is 97, b is 98
    //Used for aphabetizing things
    //comparison begins at first index and continues down the string until one string is bigger or end of string is reached

    string sampleStr = "Sample String";
    cout << "index at sampleStr 4: " << sampleStr.at(4) << endl;
    sampleStr.at(4) = 'X';
    cout << "new sampleStr: " << sampleStr << endl;
    cout << "sampleStr length: " << sampleStr.length() << endl;
    string appendStr = "!!!";
    sampleStr.append(appendStr);
    cout << "appended sampleStr: " << sampleStr << endl;
    cout << "sampleStr.substr(3, 2): " << sampleStr.substr(3, 2) << endl;

    cout << "\n\n" << endl;

    //cctype library time
    cout << "isalpha(c) true if alphabetic: a-z or A-Z" << endl;
    cout << "isalpha('x') = true, isalpha('6') = false, isalpha('!') = false" << endl;

    cout << "isdigit(c) true if digit: 0-9" << endl;
    cout << "isdigit('x') = false, isdigit('6') = true" << endl;

    cout << "isspace(c) true if whitespace" << endl;
    cout << "isspace(' ') = true, isspace('\\n') = true, isspace('x') = false" << endl;

    cout << "toupper(c) gives uppercase version" << endl;
    cout << "toupper('a') = A, toupper('A') = A, toupper(3) = 3" << endl;

    cout << "tolower(c) gives lowercase version" << endl;
    cout << "tolower('A') = a, tolower('a') = a, tolower('3') = 3" << endl;

    cout << "\n\n" << endl;

    string userText = "Help me!";
    cout << "userText.find('p'): " << userText.find('p') << endl; //find(item) returns first occurrence of item, if can't find returns string::npos
    userText = "http://google.com";
    cout << "userText.substr(0, 7): " << userText.substr(0, 7) << endl; //substr(index, length) returns starting index and length of characters

    cout << "\n\n" << endl;

    string userName;
    string greetingText;
    int itemIndex;

    itemIndex = 0;

    cout << "Enter name: ";
    getline(cin, userName);

    // Combine strings using +
    greetingText = "Hello " + userName;

    // Append a period (could have used +)
    greetingText.push_back('.'); // '' not ""
    cout << greetingText << endl;

    // Insert Mr/Ms before user's name
    greetingText.insert(6, "Mr/Ms ");
    cout << greetingText << endl;

    // Replace occurrence of "Darn" by "@$#"
    if (greetingText.find("Darn") != string::npos) { // Found
        itemIndex = greetingText.find("Darn");
        greetingText.replace(itemIndex, 4, "@#$");
    }
    cout << greetingText << endl;

    //you know what ternary operators are
    cout << "\n\n" << endl;

    //hard to compare decimals because of limited memory space
    double x = 98.6;
    if (fabs(x - 98.6) < 0.0001) { //1. abs works but it's good practice for fabs 2. for doubles the difference threshhold or epison value is 0.0001
        cout << "x = 98.6" << endl;
    }
}