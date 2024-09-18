#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, char> createDecodingMap();
string decodeMessage(const string& , const map<char, char>& );

int main() 
{
    map<char, char> decodingMap = createDecodingMap();
    string input;
    while (getline(cin, input)) 
    {
        if (input.empty()) break;  
        cout << decodeMessage(input, decodingMap) << endl;
    }
    
    return 0;
}

map<char, char> createDecodingMap() {
    map<char, char> decodingMap;
    
    string rightRow = "WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";
    string leftRow  = "QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,";
    
    for (size_t i = 0; i < rightRow.length(); ++i) 
    {
        decodingMap[rightRow[i]] = leftRow[i];
    }
    string rightRowLower = "wertyuiop[]\\sdfghjkl;'xcvbnm,./";
    string leftRowLower  = "qwertyuiop[]asdfghjkl;zxcvbnm,";
    
    for (size_t i = 0; i < rightRowLower.length(); ++i) 
    {
        decodingMap[rightRowLower[i]] = leftRowLower[i];
    }
    
    return decodingMap;
}

string decodeMessage(const string& input, const map<char, char>& decodingMap) 
{
    string output;
    for (char c : input) 
    {
        if (decodingMap.find(c) != decodingMap.end()) 
        {
            output += decodingMap.at(c);
        } 
        else 
        {
            output += c;  
        }
    }
    return output;
}