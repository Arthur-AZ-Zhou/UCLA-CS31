#include <iostream>
#include <string> //string is not included in built-in language
using namespace std;

int main() {
    int x;
    cin >> x; //reads integers is most common use
    cout << "integer entered: " << x << endl; 

    //cin.ignore(10000, '\n'); //have to ignore the white string, 10k is how many characters ignored and \n is the newline, can use cin.ignore();
    string s;
    cin.ignore();
    getline(cin, s); //reads strings
    cout << "string entered: " << s << endl;

    cout << ((x == 13)? "integer is 13" : "integer is not 13") << endl;

    string sumNum;
    int sum = 0;
    getline(cin, sumNum);
    for (int i = 0; i < sumNum.length(); i++) {
        cout << sum << " " << sumNum[i] << endl;
        sum += sumNum[i] - '0';
    }
    cout << "sum: " << sum << endl;
}