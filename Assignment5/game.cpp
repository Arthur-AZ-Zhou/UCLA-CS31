#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 6262)
#include "utilities.h" //UTILITIES.CPP OR H?
#include <iostream>
#include <cstring>
using namespace std; 

const char WORDFILENAME[] = "/mnt/c/Users/arthu/OneDrive/Desktop/Code/CS31/listOfWords.txt"; //C:\Users\arthu\OneDrive\Desktop\Code\CS31

int playOneRound(const char words[][7], int nWords, int wordnum) { //list of possible words, getWords(), location of random word
    int tries = 0;
    char answer[7];

    strcpy(answer, words[wordnum]);
    // cout << "REVEALED ANSWER: " << answer << endl; //REVEAL ANSWER FOR TESTING PURPOSES

    if (nWords < 1 || wordnum < 0 || nWords <= wordnum) {
        return -1;
    }

    while (true) {
        char probeWord[100];
        bool validWord = true;
        strcpy(answer, words[wordnum]); //reset word

        cout << "Probe word: ";
        cin >> probeWord;

        //make sure valid probeWord
        if (strlen(probeWord) < 4 || strlen(probeWord) > 6) { 
            cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
            continue;
        }
        for (int i = 0; i < strlen(probeWord); i++) {
            if (!islower(probeWord[i])) {
                validWord = false;
            }
        }
        if (!validWord) {
            cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
            continue;
        }
        validWord = false;
        for (int i = 0; i < nWords; i++) {
            if (strcmp(words[i], probeWord) == 0) {
                validWord = true;
            }
        }
        if (!validWord) {
            cout << "I don't know that word." << endl;
            continue;
        }

        //where wordle actually begins if all else works
        int golds = 0;
        int silvers = 0;
        tries++;
        if (strcmp(probeWord, answer) == 0) { //you found the word
            break;
        } 

        for (int i = 0; i < strlen(probeWord); i++) { //FIND GOLDS
            if (probeWord[i] == answer[i]) { // can break if probeword longer
                golds++;
                probeWord[i] = '1'; //pop it
                answer[i] = '1'; //pop it
            }
        }

        for (int i = 0; i < strlen(probeWord); i++) { //FIND SILVERS
            for (int j = 0; j < strlen(answer); j++) {
                if (probeWord[i] != '1') { //not popped so can check
                    if (probeWord[i] == answer[j]) {
                        silvers++;
                        probeWord[i] = '1';
                        answer[j] = '1';
                    }
                }
            }
        }
        // cout << "probeWord: " << probeWord << ", answer: " << answer << endl; //for testing purposes
        cout << "Golds: " << golds << ", Silvers: " << silvers << endl;
    }

    return tries;
}

int main() {
    const int MAXWORDS = 9000;
    const int MAXWORDLEN = 7;
    int numRounds;
    char wordList[MAXWORDS][MAXWORDLEN]; //maxwords is the size, wordlen is each string's char is an element
    
	int nWords = getWords(wordList, MAXWORDS, WORDFILENAME);
    if (nWords < 1) { //if returns int greater than maxWords
        cout << "No words were loaded, so I can't play the game." << endl;
        return 0;
    }
    /*testing getWords
    for (int i = 0; i < nWords; i++) {
        cout << wordList[i] << endl;
    }
    */

    cout << "How many rounds do you want to play? ";
    cin >> numRounds;
    if (numRounds <= 0) {
        cout << "The number of rounds must be positive." << endl;
        return 0;
    }

    int minTries, maxTries;
    double totalTries = 0;
    for (int i = 1; i <= numRounds; i++) {
        int tries = 0;
        int indexOfWord = randInt(0, nWords - 1);

        cout << "\nRound " << i << endl;
        cout << "The hidden word is " << strlen(wordList[indexOfWord]) << " letters long." << endl;
        tries = playOneRound(wordList, nWords, indexOfWord);

        //after each round
        cout << "You got it in " << tries << ((tries == 1)? " try." : " tries.") << endl;
        if (i == 1) { //for min max if its round 1 dont do other stuff just set it to the round 1 stats
            minTries = tries;
            maxTries = tries;
            totalTries += tries;
        } else { //not first round
            totalTries += tries;
            if (tries < minTries) {
                minTries = tries;
            } if (tries > maxTries) {
                maxTries = tries;
            }
        }
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Average: " << totalTries / i << ", minimum: " << minTries << ", maximum: " << maxTries << endl;
    }
}

