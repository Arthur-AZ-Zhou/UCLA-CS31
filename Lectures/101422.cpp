#include <iostream>
#include <string>
using namespace std;

int main() {
    int count = 0; 

    while (count < 5) {
        cout << count++ << endl;
    }

    int i = 2;
    do { //do while will do it while the condition is true, will do at least once even if condition is false because do is first
        cout << "Hello World" << endl;
        i++;
    }
    while (i < 1);

    string str = "Hello";
    char exclamationMark = '!';
    string newStr = str + exclamationMark;
    cout << newStr << endl;

    cout << "\nFiboacci Time!" << endl;
    
    int fibNum;
    cout << "What Fibonacci number do you want? ";
    cin >> fibNum;

    int n1 = 0;
    int n2 = 1;
    int iter = 0;
    do {
        int temp = n1;
        n1 = n2;
        n2 += temp;
        iter++;
    } while (iter < fibNum);
    cout << n1;

    cout << "\nNxN Box Time" << endl;

    int N;
    cout << "Give N for NxN box: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j > i) {
                cout << "  ";
            } else {
                cout << i + j << " ";
            }
        }
        cout << endl;
    }

    cout << "\nAverage Number List Time" << endl;

    int numOfAvg;
    int sum = 0;

    cout << "How many numbers do you want to average? ";
    cin >> numOfAvg;
    for (int i = 0; i < numOfAvg; i++) {
        int newNum; 
        cout << "Number: ";
        cin >> newNum;
        sum += newNum;
    }

    cout << "Average: " << double(sum) / numOfAvg << endl;
}