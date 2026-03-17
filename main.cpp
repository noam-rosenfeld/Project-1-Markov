#include <iostream>
#include <vector>
#include <string>
#include "markov.h"

int main() {
    int order;
    int length;
    std::string fileName;
    std::string words[10000];
    std::string suffixes[10000];
    std::string prefixes[10000];

    srand(time(NULL));

    // Prompting
    std::cout << "Declare the file name: ";
    std::cin >> fileName;

    std::cout << "Declare the order (1-3): ";
    std::cin >> order;
    
    if(order != 1 && order != 2 && order != 3) order = 1;

    std::cout << "Declare the length of the markov chain: ";
    std::cin >> length;

    // Call Functions
    int count1 = readWordsFromFile(fileName, words, 1000);
    std::cout << "\n- Read " << count1 << " words" << std::endl;

    int count2 = buildMarkovChain(words, count1, order, prefixes, suffixes, count1);
    std::cout << "- Built markov chain\n" << std::endl;

    // for (int i = 0; i < 20 && i < count2; i++) {
    //     std::cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << std::endl;
    // }

    std::cout << std::endl;

    std::string chain = generateText(prefixes, suffixes, count2, order, length);
    std::cout << chain << std::endl;
}