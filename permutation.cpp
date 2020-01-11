#include <iostream>
#include <string>
using namespace std;

string getString()
{
    string s;
    getline(cin, s);
    return s;
}

void populateHash(string s1, int alphabets[])
{
    int size = s1.length();
    for (int i = 0; i < size; i++)
    {
        int letter = (int)s1[i] - 97;
        alphabets[letter] += 1;
    }
}

void initializeAlphabets(int alphabets[])
{
    for (int i = 0; i < 26; i++)
    {
        alphabets[i] = 0;
    }
}

bool compareThem(string s2, int alphabets[])
{
    int size = s2.length();
    for (int i = 0; i < size; i++)
    {
        int letter = (int)s2[i] - 97;
        alphabets[letter] -= 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (alphabets[i] != 0)
            return false;
    }
    return true;
}

bool isPermutation(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    int alphabets[26];
    initializeAlphabets(alphabets);
    populateHash(s1, alphabets);
    return compareThem(s2, alphabets);
}

int main()
{
    string s1 = getString();
    string s2 = getString();
    cout << isPermutation(s1, s2);
}