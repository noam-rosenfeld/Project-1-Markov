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
    ifstream inputFile;
    inputFile.open(fileName);
    if(!inputFile.is_open()) { return -1; };

    int count = 0;

    while (count < maxWords && inputFile >> words[count]) {
        count++;
    }

    inputFile.close();

    return count;
}

int buildMarkovChain(const std::string words[], int numWords, 
                     int order,std::string prefixes[], 
                     std::string suffixes[], int maxChainSize) {
    int count = 0;
    for(int i = 0; i < numWords - order; i++) {
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

    //cout << "Matchcount: " << matchCount << endl;

    if(matchCount == 0) return "";

    int pick = rand() % matchCount;

    int count = 0;

    for(int i = 0; i < chainSize-1; i++) {
        if(prefixes[i] == currentPrefix) {
            //cout << "Pick: " << pick << endl;
            if(count == pick) {
                return suffixes[i];
            }
            count++;
        }
    }

    return "";
}

string getRandomPrefix(const std::string prefixes[], int chainSize) {
    int index = rand() % chainSize;
    return prefixes[index];
}

std::string generateText(const std::string prefixes[], const std::string suffixes[],
                         int chainSize, int order, int numWords) {
    string orderArr[3] = {"", "", ""};
    
    string currentPrefix = getRandomPrefix(prefixes, chainSize);
    string result = currentPrefix;

    string word = "";
    int count = 0;

    for(int i = 0; i < currentPrefix.length(); i++) {
        if(currentPrefix[i] == ' ') {
            cout << "did something";
            orderArr[count] = word;
            word = "";
            count++;
        } else {
            word += currentPrefix[i];
        }
    }

    for(int i = 0; i < numWords - order; i++) {
        string currentSuffix = getRandomSuffix(prefixes, suffixes, chainSize, currentPrefix);
        if(currentSuffix == "") break;

        result += " " + currentSuffix;
        if(order == 1) {
            currentPrefix = currentSuffix;
        } else if(order > 1) {
            for(int j = 0; j < 2; j++) orderArr[j] = orderArr[j+1];
            orderArr[order - 1] = currentSuffix;

            // Check order array, make sure there are no unneccacary spaces

            currentPrefix = joinWords(orderArr, 0, order);
            cout << currentPrefix << endl;
        }
    }

    return result;
}









