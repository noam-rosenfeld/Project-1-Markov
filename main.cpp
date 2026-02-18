#include <iostream>
#include <vector>
#include <string>
#include "markov.h"

using namespace std;

int main() {
    string input;
    vector<string> words;

    // Prompting
    cout << "Write a few sentences to generate a Markov Chain: " << endl;
    getline(cin, input);

    int wordCount = 0;

    cout << "0";

    // Errors somewhere here
    string word = "";

    cout << "1";

    for(int i = 0; i <= input.length(); i++) {
        cout << "2";
        if(input[i] != ' ') {
            words[wordCount] = word;
        } else {
            word += input[i];
            wordCount++;
        }
    }

    for(int i = 0; i < sizeof(words); i++) {
        cout << words[i] << " ";
    }
}