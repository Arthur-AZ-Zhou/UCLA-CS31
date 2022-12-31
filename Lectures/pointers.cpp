#include <iostream>
#include <string>
#include <cstring>
using namespace std; 

void PrintValue(int* valuePointer) {
   if (valuePointer == nullptr) {
      cout << "Pointer is null" << endl;
   }
   else {
      cout << *valuePointer << endl;
   }
}

int main() {
    //*&x = x, * and & cancel each other out
    //&array[i] + j = &array[i + j], works with other arithmetic like &a[i] - &a[j] = i - j
        //you can do pointerToArr - arr to find the index of pointerToArr in the array
        //you can also do arr + i to point to arr[i]
    //same works with arrayPointer++, points to next index
    //in an array, &array[i] < &array[j] if i < j, same for all operation symbols
    //you can have a double array called double da[] with 5 indexes, can loop thru using for(double* dp = &da[0]; dp < &da[5]; dp++) {}
    //if you set a pointer to an array, it will point to &array[0] (arrayPointer = array = &array[0])
        //arrayPointer = array, arrayPointer + 5 is arrayPointer[0 + 5] = arrayPointer[5]
    //even functions take pointers themselves, if you pass in an array into a function like double da[] the function reads it as &da[0]
        //if you have something like da[k] = 0, it's actually *(da + k) = 0
        //if you passed da[] into a function and parameter was named b[], b[k] = *(b + k) = *(&da[0] + k) = *&da[0 + k] = *&da[k] = da[k]
    //you can literally do pointer = array; and then do pointer[x] = another value to change the array[x] itself 
    //if let's say cat pointer currently points to array[2], and you want to change cat's current element, do cat[0] because it adds 0 to current index
    //double mean(const double* scores, int numScores), can send scores as pointer to first element of array

    int someInt;
    int* valPointer; //declare to hold a memory address

    someInt = 5;
    cout << "someInt address is " << &someInt << endl; //& obtains a variable's address
    valPointer = &someInt; //assigned memory address of someInt, so valPointer points to someInt  
    cout << "valPointer is " << valPointer << endl;
    cout << "*valPointer is " << *valPointer << endl; //derefence address, turns to *&someInt = someInt to show integer itself
    *valPointer = 10;   // Changes someInt to 10
    cout << "someInt is " << someInt << endl;
    cout << "*valPointer is " << *valPointer << endl;
    someInt = 13;   // Changes someInt to 13
    cout << "someInt is " << someInt << endl;
    cout << "*valPointer is " << *valPointer << endl; //follows and points 13 too

    //DO NOT DEREFERENCE A NULL OR UNINITIALIZED POINTER
    //int* valPointer1, valPointer2; declares valPointer1 a pointer but the 2nd is still an integer because no * exists before it

    int someIntNew = 5;
    int* valPointerNew = nullptr;

    PrintValue(valPointerNew);
    valPointerNew = &someIntNew;        
    PrintValue(valPointerNew);

    //int strcmp(const char* str1, const char* str2);
    //char* strcpy(char* destination, const char* source);

    int cmp1, cmp2;
    char string1[10] = "abcxyz";
    char string2[10] = "xyz";
    char newText[10];
    char* subStr = nullptr;

    cmp1 = strcmp(string1, string2);
    cout << "strcmp of \"" << string1 << "\" and \"";
    cout << string2 << "\" returned " << cmp1 << endl;

    subStr = &string1[3]; //copies from index 3 to end?

    cmp2 = strcmp(subStr, "xyz");
    cout << "strcmp of \"" << subStr;
    cout << "\" and \"xyz\" returned ";
    cout << cmp2 << endl;

    strcpy(newText, subStr); //copies subStr (and therefore string1) from its index (3) to end
    cout << "newText is now \"" << newText << "\"";
    cout << endl;

    //Cstring search functions:
    //strchr(sourceStr, searchChar); Returns a null pointer if searchChar does not exist in sourceStr. Else, returns pointer to first occurrence.
    //strrchr(sourceStr, searchChar); Returns a null pointer if searchChar does not exist in sourceStr. Else, returns pointer to LAST occurrence.
    //strstr(str1, str2); Returns a null pointer if str2 does not exist in str1. Else, returns a char pointer pointing to first occurrence of string str2 within string str1.
    //OK SO: how I think char pointers work is that it it points to the index to the end? If you dereference it you see that it's just the index itself

    const int MAX_USER_INPUT = 100;       // Max input size
    char userInput[MAX_USER_INPUT];       // User defined string
    char* stringPos = nullptr;            // Index into string
    
    // Prompt user for input
    cout << "Enter a line of text: ";
    cin.getline(userInput, MAX_USER_INPUT);
    
    // Locate exclamation point, replace with period
    stringPos = strchr(userInput, '!');
    
    cout << stringPos << endl; //points to first exclamation mark to end
    cout << *stringPos << endl; //if dereferenced just points to exclamation mark

    if (stringPos != nullptr) {
        *stringPos = '.';
    }
    
    // Locate "Boo" replace with "---"
    stringPos = strstr(userInput, "Boo");
    
    if (stringPos != nullptr) {
        strncpy(stringPos, "---", 3); //replace Boo with --- but only for next 3 characters
    }
    
    // Output modified string
    cout << "Censored: " << userInput << endl;
}