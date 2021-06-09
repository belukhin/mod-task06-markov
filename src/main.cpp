#include "textgen.h"
#include <fstream>
#include <iostream>

int main()
{
    ifstream myFile;
    myFile.open("fst.txt");

    vector<string> words;
    string Word;
    while (!myFile.eof())
    {
        myFile >> Word;
        words.push_back(Word);
    }
    myFile.close();

    GenMarkov Gen(words, 2, 1000);
    string line = Gen.GenText();

    ofstream myOut;
    myOut.open("sec.txt");
    myOut.clear();
    myOut << line;
    myOut.close();

    return 1;
}
