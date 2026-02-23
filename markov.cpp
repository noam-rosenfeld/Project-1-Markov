#include <iostream>
#include <ofstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Merges 2 words into 1 string
string joinWords(vector<string> words, int startIndex, int count) {
    string joinedWords = ""

    for(i = 0; i < count; i++) {
        joinedWords += words[startIndex + i];
        if(i != count - 1) {
            joinedWords += " "
        }
    }
}

int readWordsFromFile(string fileName, string words[], int maxWords) {
    ifstream inputFile.open(fileName);
    if(!inputFile.is_open()) { return -1; };

    int count = 0;

    while (count < maxWords && inFile >> words[counter]) {
        count++
    }

    inputFile.close()

    return count;
}

int buildMarkovChain(const std::string words[], int numWords, 
                     int order,std::string prefixes[], 
                     std::string suffixes[], int maxChainSize) {
    int count = 0;
    for(i = 0; i < numWords - order - 1; i++) {
        prefixes[count] = joinWords(words, i, order);
        suffixes[count] = words[i + order];

        count++;
        if (count == maxChainSize) { break; }
    }
    
    return count;
}

std::string getRandomSuffix(const std::string prefixes[], const std::string suffixes[],
                            int chainSize, std::string currentPrefix) {
    int matchCount = 0;

    for(i = 0; i < chainSize-1; i++) {
        if(prefixes[i] == currentPrefix) {
            matchCount++;
        }
    }

    if(matchCount == 0) { return ""; }

    srand(time(0));
    int pick = rand() % matchCount;

    int count;

    for(i = 0; i < chainSize-1; i++) {
        if(prefixes[i] == currentPrefix) {
            if(i == pick) {
                return suffixes[i];
            }
            count++;
        }
    }

    return "";
}







