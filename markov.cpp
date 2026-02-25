#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Merges 2 words into 1 string
string joinWords(const string words[], int startIndex, int count) {
    string joinedWords = "";

    for(int i = 0; i < count; i++) {
        joinedWords += words[startIndex + i];
        if(i != count - 1) {
            joinedWords += " ";
        }
    }
    return joinedWords;
}

int readWordsFromFile(string fileName, string words[], int maxWords) {
    ifstream inputFile(fileName);
    inputFile.open(fileName);
    if(!inputFile.is_open()) { return -1; };

    int count = 0;

    cout << count << endl;

    while (count < maxWords /*&& inputFile >> words[count]*/) {
        count++;
        cout << count << endl;
    }

    inputFile.close();

    return count;
}

int buildMarkovChain(const std::string words[], int numWords, 
                     int order,std::string prefixes[], 
                     std::string suffixes[], int maxChainSize) {
    int count = 0;
    for(int i = 0; i < numWords - order - 1; i++) {
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

    for(int i = 0; i < chainSize-1; i++) {
        if(prefixes[i] == currentPrefix) {
            matchCount++;
        }
    }

    if(matchCount == 0) { return ""; }

    srand(time(0));
    int pick = rand() % matchCount;

    int count;

    for(int i = 0; i < chainSize-1; i++) {
        if(prefixes[i] == currentPrefix) {
            if(i == pick) {
                return suffixes[i];
            }
            count++;
        }
    }

    return "";
}

string getRandomPrefix(const std::string prefixes[], int chainSize) {
    srand(time(0));
    int index = rand() % chainSize;
    return prefixes[index];
}

std::string generateText(const std::string prefixes[], const std::string suffixes[],
                         int chainSize, int order, int numWords) {
    int arr[3] = {0, 0, 0};
    
    string currentPrefix = getRandomPrefix(prefixes, chainSize);
    string result = currentPrefix;
    for(int i = 0; i < numWords - order; i++) {
        string currentSuffix = getRandomSuffix(prefixes, suffixes, chainSize, result);
        if(currentSuffix == "") { break; }

        result += " " + currentSuffix;
        if(order == 1) {
            currentPrefix = currentSuffix;
        } else if(order > 1) {
            currentPrefix = arr[order];
        }
    }

    return result;
}









