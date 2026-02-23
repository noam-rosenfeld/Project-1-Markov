#ifndef MARKOV_H
#define MARKOV_H

#include <iostream>

using namespace std;

string joinWords(vector<string> words, int startIndex, int count);

int readWordsFromFile(string fileName, string words[], int maxWords);

int buildMarkovChain(const std::string words[], int numWords, 
                    int order,std::string prefixes[], 
                    std::string suffixes[], int maxChainSize);

std::string getRandomSuffix(const std::string prefixes[], const std::string suffixes[],
                            int chainSize, std::string currentPrefix);

#endif
