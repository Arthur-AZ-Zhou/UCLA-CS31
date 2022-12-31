#include <iostream>
#include <string>
using namespace std; 

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int split(string a[], int n, string splitter);

int main() {
    string people[5] = {"boris", "gordon", "rishi", "liz", "john"};
    cerr << "appendToAll(people, -4, \"!!!\") = " << appendToAll(people, -4, "!!!") << endl; //test negative
    cerr << "appendToAll(people, 5, \"!!!\") = " << appendToAll(people, 5, "!!!") << endl; //test normal cases
    for (int i = 0; i < sizeof(people)/sizeof(string); i++) {
        cerr << people[i] << " ";
    }
    cerr << "\n\n";

    string people1[6] = {"boris", "gordon", "rishi", "liz", "john", "gordon"};
    cerr << "lookup(people1, 6, \"gordon\") = " << lookup(people1, 6, "gordon") << endl; //find earliest gordon
    cerr << "lookup(people1, 6, \"arthur\") = " << lookup(people1, 6, "arthur") << endl; //what if target string doesn't exist
    cerr << "\n";

    string pm[7] = {"david", "liz", "margaret", "tony", "gordon", "boris", "tony"};
    cerr << "positionOfMax(pm, 7) = " << positionOfMax(pm, 7) << endl; //finds first instance of alphabetically-last name
    string pm1[0] = {};
    cerr << "positionOfMax(pm1, 0) = " << positionOfMax(pm1, 0) << endl; //if no interesting elements
    cerr << "\n";

    string mp[5] = {"john", "david", "liz", "theresa", "margaret"};
    cerr << "rotateLeft(mp, 5, 1) = " << rotateLeft(mp, 5, 1) << endl; //tests a normal scenario
    for (int i = 0; i < sizeof(mp)/sizeof(string); i++) { //look at new array
        cerr << mp[i] << " ";
    }
    cerr << endl;
    string mp1[5] = {"john", "david", "liz", "theresa", "margaret"};
    cerr << "rotateLeft(mp1, 5, -4) = " << rotateLeft(mp1, 5, -4) << endl; //check out of bounds negative pos
    cerr << "rotateLeft(mp1, 5, 10) = " << rotateLeft(mp1, 5, 10) << endl; //check out of bounds out of bounds pos
    cerr << "rotateLeft(mp1, -5, 3) = " << rotateLeft(mp1, -5, 3) << endl; //negative n
    cerr << "\n";

    string d[9] = {"tony", "boris", "rishi", "rishi", "gordon", "gordon", "gordon", "rishi", "rishi"};
    cerr << "countRuns(d, 9) = " << countRuns(d, 9) << endl; //counts 5 sequences
    cerr << "countRuns(d, -9) = " << countRuns(d, -9) << endl; //tests negative
    cerr << "\n";

    string leader[6] = {"boris", "rishi", "xD", "tony", "theresa", "david"}; 
    cerr << "flip(leader, 4) = " << flip(leader, 4) << endl; //tests first 4 swap
    for (int i = 0; i < sizeof(leader)/sizeof(string); i++) { //look at new array
        cerr << leader[i] << " ";
    }
    cerr << endl;
    string leader1[7] = {"boris", "rishi", "xD", "tony", "theresa", "david", "arthur"};
    cerr << "flip(leader1, 7) = " << flip(leader1, 7) << endl; //tests an odd-numbered array flip
    for (int i = 0; i < sizeof(leader1)/sizeof(string); i++) { //look at new array
        cerr << leader1[i] << " ";
    }
    cerr << "\n\n";

    string leader2[6] = {"boris", "rishi", "", "tony", "theresa", "david"};
    string politician[5] = {"boris", "rishi", "david", "", "tony"};
    cerr << "differ(leader2, 6, politician, 5) = " << differ(leader2, 6, politician, 5) << endl; //normal test, should return index 2
    cerr << "differ(leader2, 2, politician, 1) = " << differ(leader2, 2, politician, 1) << endl; //when boths n's run out
    cerr << "differ(leader2, -3, politician, 1) = " << differ(leader2, -3, politician, 1) << endl; //check negative n
    cerr << "\n";

    string names[10] = {"john", "margaret", "theresa", "rishi", "boris", "liz"};
    string names1[10] = {"margaret", "theresa", "rishi"};
    string names2[10] = {"john", "rishi"};
    string names3[0] = {};
    string names4[0] = {};
    cerr << "subsequence(names, 6, names1, 3) = " << subsequence(names, 6, names1, 3) << endl; //normal test, found a subsequence at index 1
    cerr << "subsequence(names, 5, names2, 2) = " << subsequence(names, 5, names2, 2) << endl; //test w/ no subsequence in names
    cerr << "subsequence(names, 6, names3, 0) = " << subsequence(names, 6, names3, 0) << endl; //test with names3 as an empty array
    cerr << "subsequence(names3, 0, names4, 0) = " << subsequence(names3, 0, names4, 0) << endl; //2 empty subsequences, should still return 0
    cerr << "subsequence(names3, 0, names2, 6) = " << subsequence(names3, 0, names2, 6) << endl; //test an empty array as man sequence and an actual array as subsequence, should return -1
    cerr << "\n";

    string names5[10] = {"john", "margaret", "theresa", "rishi", "boris", "liz"};
    string set1[10] = {"david", "boris", "rishi", "margaret"};
    string set2[10] = {"tony", "gordon"};
    string set3[0] = {};
    cerr << "lookupAny(names5, 6, set1, 4) = " << lookupAny(names5, 6, set1, 4) << endl; //normal test, should return 1
    cerr << "lookupAny(names5, 6, set2, 2) = " << lookupAny(names5, 6, set2, 2) << endl; //what if nothing from set2 exists in names5, returns -1
    cerr << "lookupAny(names5, 6, set3, 0) = " << lookupAny(names5, 6, set3, 0) << endl; //empty set, should return -1 
    cerr << "\n";

    string pm2[6] = {"david", "liz", "margaret", "tony", "gordon", "boris"};
    string pm3[4] = {"margaret", "theresa", "liz", "rishi"};
    cerr << "split(pm2, 6, \"john\") = " << split(pm2, 6, "john") << endl; //normal test
    for (int i = 0; i < sizeof(pm2)/sizeof(string); i++) {
        cerr << pm2[i] << " ";
    }
    cerr << endl;
    cerr << "split(pm3, 4, \"rishi\") = " << split(pm3, 4, "rishi") << endl; //includes the splitter itself in the string array
    for (int i = 0; i < sizeof(pm3)/sizeof(string); i++) {
        cerr << pm3[i] << " ";
    }
    cerr << "\n\n";
}

int appendToAll(string a[], int n, string value) {
    if (n < 0) { //checks if n is negative
        return -1;
    }

    for (int i = 0; i < n; i++) {
        a[i] += value;
    }

    return n;
}

int lookup(const string a[], int n, string target) {
    if (n < 0) { //checks if n is negative
        return -1;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            return i;
        }
    }

    return -1;
}

int positionOfMax(const string a[], int n) { //ELEMENTS OF INTEREST??? what does that mean?
    if (n <= 0) { //check if n is negative or empty bc then there is no elements of interest
        return -1;
    }

    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > a[maxIndex]) {
            maxIndex = i;
        }
    }

    return maxIndex;
}

int rotateLeft(string a[], int n, int pos) {
    if (n < 0 || pos < 0 || n <= pos) { //check if n is negative or if position is out of bounds from 0 to n
        return -1;
    }

    string temp = a[pos];
    for (int i = pos; i < n - 1; i++) { //change the newer elements
        a[i] = a[i + 1];
    }
    a[n - 1] = temp;

    return pos;
}

int countRuns(const string a[], int n) {
    if (n < 0) { //checks if n is negative
        return -1;
    } 

    int numOfSequences = 0;
    for (int i = 0; i < n - 1; i++) {
        if(a[i] != a[i + 1]) {
            numOfSequences++;
        }
    }

    return numOfSequences + 1; //we only count the changes, so we have to add one more for last sequence
}

int flip(string a[], int n) {
    if (n < 0) { //checks if n is negative
        return -1;
    }

    for (int i = 0; i < n/2; i++) { //prevent double swap
        string temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }

    return n;
}

int differ(const string a1[], int n1, const string a2[], int n2) {
    if (n1 < 0 || n2 < 0) { //check for negative n value
        return -1;
    }

    for (int i = 0; i < n1; i++) {
        if (a1[i] != a2[i]) {
            return i;
        }
    }

    return (n1 < n2)? n1 : n2;
}

int subsequence(const string a1[], int n1, const string a2[], int n2) {
    if (n1 < 0 || n2 < 0) { //check for negative n value
        return -1;
    }

    if (n2 == 0) { //an empty subsequence can always be found, even when n1 is empty too
        return 0;
    }

    for (int i = 0; i < n1 - n2; i++) {
        int n2Stack = 0; //has to add up to n2 to be considered a full sequence

        for (int j = 0; j < n2; j++) {
            if (a2[j] == a1[i + j]) {
                n2Stack++;
            }
        }

        if (n2Stack == n2) {
            return i;
        }
    }

    return -1;
}

int lookupAny(const string a1[], int n1, const string a2[], int n2) {
    if (n1 < 0 || n2 < 0) { //check for negative n value
        return -1;
    }

    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n1; j++) {
            if (a2[i] == a1[j]) {
                return i;
            }
        }
    }

    return -1;
}

int split(string a[], int n, string splitter) {
    if (n < 0) { //checks if n is negative
        return -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                string temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    int returnNum = 0;
    for (returnNum = 0; returnNum < n; returnNum++) {
        if (a[returnNum] >= splitter) {
            break;
        }
    }

    return returnNum;
}