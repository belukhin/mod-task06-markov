#include <time.h>
#include "textgen.h"

Markov::Markov(vector<string> all_words, int prfx_c, int gen_c)
{
    NPREF = prfx_c;
    MAXGEN = gen_c;

    for (int i = 0; i < all_words.size() - NPREF + 1; i++){
        prefix prfx;
        for (int j = 0; j < NPREF; j++)
            prfx.push_back(all_words.at(i + j));
        if (i == all_words.size() - NPREF)
            statelab[prfx].push_back("<Last_Prefix>");
        else
            statelab[prfx].push_back(all_words.at(i + NPREF));
    }
}

Markov::Markov(map<prefix, vector<string>> Gen, int gen_c)
{
    statelab = Gen;
    NPREF = statelab.begin()->first.size();
    MAXGEN = gen_c;
}

string Markov::TextGen()
{
    srand(time(NULL));
    string output;
    deque<string> all_words;
    auto it = statelab.begin();

    advance(it, rand() % statelab.size());
    for (int i = 0; i < NPREF; i++)
        all_words.push_back(it->first.at(i));

    while (output.size() < MAXGEN){
        prefix prfx;
        for (int i = 0; i < NPREF; i++)
            prfx.push_back(all_words.at(i));
        int random = rand() % statelab.find(prfx)->second.size();
        if (statelab.find(prfx)->second.at(random) == "<Last_Prefix>"){
            for (int i = 0; i < NPREF; i++)
                output += all_words.at(i) + ' ';
            break;
        }
        all_words.push_back(statelab.find(prfx)->second.at(random));

        output += all_words.at(0) + ' ';
        all_words.pop_front();
    }

    return output;
}