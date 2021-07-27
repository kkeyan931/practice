#include <bits/stdc++.h>

using namespace std;

bool canConstruct(string target, vector<string> &wordBank,unordered_map<string,bool> &memo)
{
    if(memo.find(target)!=memo.end()){
        return memo[target];
    }
    else if (target.empty())
    {
        return true;
    }
    for (int i = 0; i < wordBank.size(); ++i)
    {
        int index = target.find(wordBank[i]);
        if (wordBank[i].size() <= target.size() && index == 0)
        {

            if (canConstruct(target.substr(wordBank[i].size()), wordBank,memo))
            {
                memo[target]=true;
                return memo[target];
            }
        }
    }
    memo[target] = false;
    return memo[target];
}

int main()
{
    string target;

    cout << "Enter the target String" << endl;
    cin >> target;

    cout << "Enter the number of string in the wordBank" << endl;
    int n;
    cin >> n;

    unordered_map<string,bool> memo;
    vector<string> wordBank;

    string str;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        wordBank.push_back(str);
    }

    if (canConstruct(target, wordBank,memo))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}