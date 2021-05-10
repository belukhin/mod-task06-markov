#include "textgen.h"
#include <fstream>
#include <iostream>

int main()
{
    ifstream file_in;
    ofstream file_out;
    vector<string> words;
    string word;

    file_in.open("text.txt");
    while (!file_in.eof()){
        file_in >> word;
        words.push_back(word);
    }
    file_in.close();

    Markov Gen(words, 2, 1000);
    string line = Gen.TextGen();

    
    file_out.open("output.txt");
    file_out.clear();
    file_out << line;
    file_out.close();

    return 1;
}