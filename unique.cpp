#include <iostream>
#include <string>
using namespace std;

string getString()
{
    string s;
    getline(cin, s);
    return s;
}

bool checkAndsetBit(int &alphabets, char letter)
{
    int n = (int)letter - 97;
    int mask = 1 << n;
    if ((alphabets & (1 << n)) == 0)
    {
        alphabets = alphabets | mask;
        return false;
    }
    else
    {
        return true;
    }
}

bool checkUnique(string s)
{
    int alphabets = 0;
    for (auto letter : s)
    {
        if (checkAndsetBit(alphabets, letter))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = getString();
    cout << checkUnique(s);
    return 0;
}