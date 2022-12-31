#include <iostream>
#include <string> //string is not included in built-in language
using namespace std;

int main() {
    cout << "How many hours did you work? ";
    double hoursWorked;
    cin >> hoursWorked; //cin is just to read numbers

    cout << "How much is your pay? ";
    double payRate;
    cin >> payRate;

    //just checks if the code works
    cout << "hours worked: " << hoursWorked << endl; //move cursor to beginning of next line
    cout << "pay rate: $" << payRate << endl;

    double amountEarned = hoursWorked * payRate;
    cout.setf(ios::fixed); //will set 2 decimal figures, rounds 
    cout.precision(2);
    cout << "you earned $" << amountEarned << endl;
    cout << "$" << amountEarned/10 << " will be withheld" << endl;

    /* 
    14.3/5.0 = 2.86, as long as you have one float, you will get float answer
    14.3/5 = 2.86
    14/5.0 = 2.8
    14/5 = 2, will drop the decimal bc int/int = int

    14%5 = 4, mod

    follows pemdas rules, mod is same precedence as / and *
    */

    int a = 10;
    int b = a*a;
    //int c = 25/(b-100); //if you divide by 0, result depends on computer. Floating point exception for me
    cout << "a: " << a << endl << "b: " << b << endl;

    int d = 1000;
    int e = d * d * d;
    int f = d * e; //will give some random integer based on how binary numbers represented
    cout << "d: " << d << endl << "e: " << e << endl << "f: " << f << endl;


    //dummy getline because getline reads whitestrings
    /*string sample;
    getline(cin, sample);*/
    cin.ignore(); //or you can just ignore it

    cout << "What's your name? ";
    string yourName;
    getline(cin, yourName); //second argument has to be string, getline used to read strings

    cout << "How old are you? ";
    int age;
    cin >> age;
    cin.ignore(10000, '\n'); //there's a problem if you accept an integer then a string

    cout << "What's your quest? ";
    string quest;
    getline(cin, quest);

    cout << "\nHello, brave " << yourName << "!" << endl << "You want " << quest << endl << "You are " << age << " years old" << endl;
}

// #include <iostream>
// #include <algorithm>
// #include <stdio.h>
// using namespace std;

// int main() {
//     int size = 10;
//     char arr1[] = {'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'};
//     char arr2[size];
//     // char* arr2 = arr1; //a pointer

//     for (int i = 0; i < sizeof(arr1); i++) {
//         printf("%c", arr1[i]);
//     }

//     copy (arr1, arr1+size, arr2); //deep copy

//     arr2[3] = 'E';
//     printf("\n%s\n", arr1);
//     printf("%s\n", arr2);

//     return 0;
// }