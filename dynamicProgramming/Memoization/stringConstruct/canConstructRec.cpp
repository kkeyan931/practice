#include <bits/stdc++.h>

using namespace std;

bool canConstruct(string target, vector<string> &wordBank)
{
    if (target.empty())
    {
        return true;
    }
    for (int i = 0; i < wordBank.size(); ++i)
    {
        int index = target.find(wordBank[i]);
        if (wordBank[i].size() <= target.size() && index == 0)
        {

            if (canConstruct(target.substr(wordBank[i].size()), wordBank))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    string target;

    cin >> target;

    cout << "Enter the number of string in the wordBank" << endl;
    int n;
    cin >> n;

    vector<string> wordBank;

    string str;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        wordBank.push_back(str);
    }

    if (canConstruct(target, wordBank))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}