#include <deque>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Markov
{
    private:
        typedef deque<string> prefix;
        map<prefix, vector<string>> statelab;
        int NPREF = 2;
        int MAXGEN = 1000;

    public:
        Markov(vector<string>, int, int);
        Markov(map<prefix, vector<string>>, int);
        string TextGen();
};