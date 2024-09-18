#include <iostream>
#include <string>
using namespace std;

pair<int, string> findPalindrome(string);
bool isPalindrome(const string&);
string reverseString(const string&) ;
string addLargeNumbers(const string& , const string&) ;


int main() 
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string P;
        cin >> P;

        auto result = findPalindrome(P);
        if (result.first == -1) 
        {
            cout << "No palindrome found within 1000 iterations." << endl;
        } 
        else 
        {
            cout << result.first << " " << result.second << endl;
        }
    }

    return 0;
}

pair<int, string> findPalindrome(string num) 
{
    int iterations = 0;
    while (!isPalindrome(num) && iterations < 1000) 
    {
        string reversed = reverseString(num);
        num = addLargeNumbers(num, reversed);
        iterations++;
    }

    if (iterations == 1000) 
    {
        return {-1, ""};
    }

    return {iterations, num};
}

bool isPalindrome(const string& str) 
{
    return str == reverseString(str);
}

string reverseString(const string& str) 
{
    string reversed;
    for (int i = str.length() - 1; i >= 0; --i) 
    {
        reversed.push_back(str[i]);
    }
    return reversed;
}

string addLargeNumbers(const string& num1, const string& num2) 
{
    string result;
    int carry = 0;
    int sum = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry) 
    {
        sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    string reversedResult;
    for (int k = result.length() - 1; k >= 0; --k) 
    {
        reversedResult.push_back(result[k]);
    }

    return reversedResult;
}
