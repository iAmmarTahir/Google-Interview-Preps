#include <iostream>
#include <string>
#include <locale>
using namespace std;

string getString()
{
    string s;
    getline(cin, s);
    return s;
}

void urlify(string &s, int chars)
{
    int size = s.length();
    int j = chars - 1;
    for (int i = size - 1; i >= 0 && i != j;)
    {
        if (isalpha(s[j]))
        {
            s[i] = s[j];
            i--;
            j--;
        }
        else
        {
            s[i] = '0';
            s[i - 1] = '2';
            s[i - 2] = '%';
            i -= 3;
            j--;
        }
    }
}

int main()
{
    string s = getString();
    urlify(s, 13);
    cout << s;
    return 0;
}