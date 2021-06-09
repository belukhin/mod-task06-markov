#include <time.h>
#include "textgen.h"

GenMarkov::GenMarkov(vector<string> words, int prfx_k, int gen_k)
{
    NPREF = prfx_k;
    MAXGEN = gen_k;

    int i = 0;
    while ( i < words.size() - NPREF + 1)
    {
        prefix prfx;
        for (int j = 0; j < NPREF; j++)
            prfx.push_back(words.at(i + j));
        if (i == words.size() - NPREF)
            statelab[prfx].push_back("<Last_Prefix>");
        else
            statelab[prfx].push_back(words.at(i + NPREF));
        i++;
    }
}


string GenMarkov::GenText()
{
    srand(time(NULL));
    string output;
    deque<string> words;

    auto it = statelab.begin();
    advance(it, rand() % statelab.size());
    int i = 0;
    while (i < NPREF)
    {
        words.push_back(it->first.at(i));
        i++;
    }

    while (output.size() < MAXGEN)
    {
        prefix prfx;
        for (int i = 0; i < NPREF; i++)
            prfx.push_back(words.at(i));
        int random = rand() % statelab.find(prfx)->second.size();
        if (statelab.find(prfx)->second.at(random) == "<Last_Prefix>")
        {
            for (int i = 0; i < NPREF; i++)
                output += words.at(i) + ' ';
            break;
        }
        words.push_back(statelab.find(prfx)->second.at(random));

        output += words.at(0) + ' ';
        words.pop_front();
    }

    return output;
}


GenMarkov::GenMarkov(map<prefix, vector<string>> Gen, int gen_k)
{
    statelab = Gen;
    NPREF = statelab.begin()->first.size();
    MAXGEN = gen_k;
}
