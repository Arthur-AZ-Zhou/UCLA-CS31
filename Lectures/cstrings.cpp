#include <iostream>
#include <string>
#include <cstring>
using namespace std; 

void StrSpaceToHyphen(char modString[]);

int main() {
    char movieTitle[20] = "Star Wars"; //10 characters, last one is null
    cout << "strlen(movieTitle): " << strlen(movieTitle) << endl;
    cout << "strlen loop: ";
    for (int i = 0; i < strlen(movieTitle); i++) {
        cout << movieTitle[i];
    }
    cout << endl << "normal print: " << movieTitle << endl; //printing stops when it reaches null character at end

    //assigning null character to another character is a problem bc the program might keep printing
    movieTitle[10] = '!';
    cout << "assigning null char something else: " << movieTitle << endl;

    //ERROR: DO NOT CONTINUE PRINTING AT NULL CHARACTER, MAY PRINT CHARS IT SHOULDN'T (machine and compiler dependent)
    //ERROR: ALSO DO NOT ASSIGN A STRING GREATER THAN THE SIZE OF THE ARRAY, THE PROGRAM MIGHT WORK DEPENDING ON MEMORY ASSIGNMENTS BUT...
    cout << "continue after null: ";
    for (int i = 0; i < 20; i++) {
        cout << movieTitle[i];
    }
    cout << "\n";
    cout << "out of index: ";
    for (int i = 0; i < 30; i++) { //AND ESPECIALLY DON'T CONTINUE PRINTING AFTER THE ACCESSIBLE INDEX
        cout << movieTitle[i];
    }
    cout << "\n";

    //movieTitle = "Pacific Rim"; //you cannot assign cstrings like this

    char orgName[100] = "United Nations"; 
    char userText[20] = "UNICEF"; 
    char targetText[10];

    //strcpy(destStr, sourceStr); Copies sourceStr (up to and including null character) to destStr.
        //strcpy(targetText, userText); Copies "UNICEF" + null char to targetText
        //strcpy(targetText, orgName); Error: "United Nations" has > 10 chars
        //targetText = orgName; Error: Strings can't be copied this way
    //strncpy(destStr, sourceStr, numChars); Copies up to numChars characters.
        //strncpy(orgName, userText, 6); // orgName is "UNICEF Nations"
    //strcat(destStr, sourceStr); Copies sourceStr (up to and including null character) to end of destStr (starting at destStr's null character).
        //strcat(orgName, userText); // orgName is "United NationsUNICEF"
    //strncat(destStr, sourceStr, numChars); Copies up to numChars characters to destStr's end, then appends null character.	
        //strcpy(targetText, "abc"); // targetText is "abc"
        //strncat(targetText, "123456789", 3); // targetText is "abc123"
    //strchr(sourceStr, searchChar); Returns NULL if searchChar does not exist in sourceStr, otherwise returns index of first occurence
        //strchr(orgName, 'U'); // returns true
    //strlen(sourceStr); returns length of string up to the first null character
    //strcmp(str1, str2); returns 0 if str1 and str2 are equal

    //isalnum(c) -- Returns true if c is alphabetic or a numeric digit
    //isspace(c) -- Returns true if character c is a whitespace.	
    //islower(c) -- Returns true if character c is a lowercase letter a-z.
    //isupper(c) -- Returns true if character c is an uppercase letter A-Z.	
    //isblank(c) -- Returns true if character c is a blank character. Blank characters include spaces and tabs.	
    //isxdigit(c) -- Returns true if c is a hexadecimal digit: 0-9, a-f, A-F.	
    //ispunct(c) -- Returns true if c is a punctuation character. Punctuation characters include: !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~	
    //isprint(c) -- Returns true if c is a printable character. Printable characters include alphanumeric, punctuation, and space characters.	
    //iscntrl(c) -- Returns true if c is a control character. Control characters are all characters that are not printable.	

    char userStr[] = "Hi my name is arthur";
    StrSpaceToHyphen(userStr);
    cout << userStr << endl;
}

void StrSpaceToHyphen(char modString[]) { //modString is actually a string, not a character. ALSO A POINTER TO STRING
   int i;      // Loop index
   
   for (i = 0; i < strlen(modString); ++i) {
      if (modString[i] == ' ') {
         modString[i] = '-';
      }
   }
}