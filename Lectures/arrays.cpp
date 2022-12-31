#include <iostream>
#include <string>
using namespace std; 

void doubleArray(int intArr[]) {
    for (int i = 0; i < 8; i++) {
        intArr[i] *= 2;
    }
}

int main() {
    int itemCounts[3]; //YOU CANNOT INCREASE ARRAY SIZE

    itemCounts[0] = 122;
    itemCounts[1] = 119;
    itemCounts[2] = 117;

    cout << "item at 1st index: " << itemCounts[1] << endl;

    for (int i = 0; i < sizeof(itemCounts)/sizeof(int); i++) { //have to divide by size of byte
        cout << itemCounts[i] << endl;
    }

    //can also initialize array like this:
    int myArray[3] = {5, 7, 11};
    int myValues[10]; //initializes empty array size 10

    cout << "\n"; //=======================================================================================================

    const int YEARS[3] = {1865, 1920, 1964}; //to prevent change to YEARS[]
    int yearSum = 0;

    for (int i = 0; i < sizeof(YEARS)/sizeof(int); i++) {
        yearSum += YEARS[i];
    }
    cout << "Sum of YEARS: " << yearSum << endl;

    int maxVal = YEARS[0];
    for (int i = 0; i < sizeof(YEARS)/sizeof(int); i++) {
        if (maxVal < YEARS[i])
            maxVal = YEARS[i];
    }
    cout << "Highest number in YEARS: " << maxVal << endl;

    cout << "\n"; //=======================================================================================================
    //don't do index out of bounds, or else weird things happen and apparently it can override the data of other variables

    //Reversing an array:
    const int NUM_ELEMENTS = 8; // Number of elements
    int userVals[NUM_ELEMENTS]; // User numbers
    int i;                      // Loop index
    int tempVal;                // Temp variable for swapping
    
    // Prompt user to input values
    cout << "Enter " << NUM_ELEMENTS << " integer values..." << endl;
    for (i = 0; i < NUM_ELEMENTS; ++i) {
        cout << "Value: ";
        cin >> userVals[i];
    }
    
    // Reverse array's elements
    for (i = 0; i < (NUM_ELEMENTS / 2); ++i) { //divide NUM_ELEMENTS/2 to prevent double swap (if odd number it won't swap middle bc 5/2 = 2)
        tempVal = userVals[i];                        // Temp for swap
        userVals[i] = userVals[NUM_ELEMENTS - 1 - i]; // First part of swap, minus 1 so not out of bounds
        userVals[NUM_ELEMENTS - 1 - i] = tempVal;     // Second complete
    }
    
    // Print numbers
    cout << endl << "New values: ";
    for (i = 0; i < NUM_ELEMENTS; ++i) {
        cout << userVals[i] << " ";
    }

    cout << "\n"; //=======================================================================================================

    // Initializing a 2D array
    int numVals1[2][3] = { {22, 44, 66}, {97, 98, 99} }; //2 is rows, 3 is columns
    int numVals2[2][3]; //if you want to make it empty

    // Use multiple lines to make rows more visible
    int numVals[2][3] = {
    {22, 44, 66}, // Row 0
    {97, 98, 99}  // Row 1
    };

    cout << "\n"; //=======================================================================================================

    //quite dangerous, because if you pass in an array into a function whose parameters require it, the parameter's array
    //is actually a pointer to the real array so you end up altering the real array
    //to prevent this from happening, you can pass in const int intArray[] to prevent it from being changed
    doubleArray(userVals); 
    for (i = 0; i < sizeof(userVals)/sizeof(int); i++) {
        cout << userVals[i] << " ";
    }
    cout << endl;
}