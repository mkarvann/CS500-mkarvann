#include "randWord.h"
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

vector<string> dictionary;

string trim(const string& );

void InitDictionary(const string& filename) 
{
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        line = trim(line);

        if (!line.empty()) {
            size_t colonPos = line.find(':');
            if (colonPos != string::npos) 
            {
                string word = line.substr(0, colonPos);
                word = trim(word);

                if (!word.empty())
                {
                    dictionary.push_back(word);
                }
            }
        }
    }

    srand(static_cast<unsigned>(time(nullptr)));
}

string ChooseRandomWord() 
{
    if (dictionary.empty()) return "";
    return dictionary[rand() % dictionary.size()];
}

string trim(const string& str) 
{
    size_t first = str.find_first_not_of("\" ");
    size_t last = str.find_last_not_of("\" ");
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, last - first + 1);
}