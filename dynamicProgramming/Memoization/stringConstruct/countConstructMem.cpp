#include <bits/stdc++.h>

using namespace std;

int canConstruct(string target, vector<string> &wordBank,unordered_map<string,int> &memo)
{
    if(memo.find(target)!=memo.end()){
        return memo[target];
    }
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
            int countRest = canConstruct(target.substr(wordBank[i].size()), wordBank,memo);
            if (countRest!=0)
            {
                count = count + countRest;
            }
        }
    }
    memo[target]=count;
    return memo[target];
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

    unordered_map<string,int> memo;

    cout << "Count : " << canConstruct(target, wordBank,memo) << endl;

    // if ()
    // {
    //     cout << "True" << endl;
    // }
    // else
    // {
    //     cout << "False" << endl;
    // }
}