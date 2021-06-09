#include <vector>
#include <string>
#include <deque>
#include <map>

using namespace std;

class GenMarkov
{
    typedef deque<string> prefix;
public:
    string GenText();
    GenMarkov(vector<string> allwords, int prfx_k, int gen_k);
    GenMarkov(map<prefix, vector<string>> Gen, int gen_k);
private:
    map<prefix, vector<string>> statelab;
    int NPREF = 2;
    int MAXGEN = 1000;
};
