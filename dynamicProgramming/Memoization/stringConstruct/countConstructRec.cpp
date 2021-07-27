#include <bits/stdc++.h>

using namespace std;

int canConstruct(string target, vector<string> &wordBank)
{
    if (target.empty())
    {
        return 1;
    }
    int count=0;
    for (int i = 0; i < wordBank.size(); ++i)
    {
        int index = target.find(wordBank[i]);
        if (wordBank[i].size() <= target.size() && index == 0)
        {
            int countRest = canConstruct(target.substr(wordBank[i].size()), wordBank);
            if (countRest!=0)
            {
                count = count + countRest;
            }
        }
    }
    return count;
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

    cout << "Count : " << canConstruct(target, wordBank) << endl;

    // if ()
    // {
    //     cout << "True" << endl;
    // }
    // else
    // {
    //     cout << "False" << endl;
    // }
}