#include <iostream>
#include <vector>
#include <string>
#include "markov.h"

using namespace std;

int main() {
    string input;
    string words[1000];

    int count = readWordsFromFile("test.txt", words, 1000);
    std::cout << "Read " << count << " words" << endl;

    for (int i = 0; i < 10 && i < count; i++) {
        std::cout << "- " << words[i] << std::endl;
    }


    cout << joinWords(words, 0, 2) << std::endl;
    cout << joinWords(words, 1, 3) << std::endl;

    // Prompting
    // cout << "Write a few sentences to generate a Markov Chain: " << endl;
    // getline(cin, input);

    // int wordCount = 0;

    // cout << "0";

    // // Errors somewhere here
    // string word = "";

    // cout << "1";

    // for(int i = 0; i <= input.length(); i++) {
    //     cout << "2";
    //     if(input[i] != ' ') {
    //         words[wordCount] = word;
    //     } else {
    //         word += input[i];
    //         wordCount++;
    //     }
    // }

    // for(int i = 0; i < sizeof(words); i++) {
    //     cout << words[i] << " ";
    // }
}