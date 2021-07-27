#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> *allConstruct(string target, vector<string> &wordBank,unordered_map<string,vector<vector<string>>*> &memo)
{
    if(memo.find(target)!=memo.end()){
        return memo[target];
    }
    else if (target.empty())
    {
        return new vector<vector<string>>;
    }
    vector<vector<string>> *finalCombination = new vector<vector<string>>;
    for (int i = 0; i < wordBank.size(); ++i)
    {
        if (wordBank[i].size() <= target.size())
        {
            int index = target.find(wordBank[i]);
            if (index == 0)
            {
                auto suffix = allConstruct(target.substr(wordBank[i].size()), wordBank,memo);
                if (suffix != nullptr)
                {
                    if (suffix->empty())
                    {
                        vector<string> temp;
                        temp.push_back(wordBank[i]);
                        finalCombination->push_back(temp);
                    }
                    else
                    {
                        for (auto p = suffix->begin(); p != suffix->end(); ++p)
                        {
                            vector<string> temp;
                            temp.push_back(wordBank[i]);
                            for (auto x : *p)
                            {
                                temp.push_back(x);
                            }
                            finalCombination->push_back(temp);
                        }
                    }
                }
            }
        }
    }
    if (!finalCombination->empty())
    {
        memo[target]=finalCombination;
        return memo[target];
    }
    memo[target] = nullptr;
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

    vector<string> wordBank;

    string str;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        wordBank.push_back(str);
    }
    unordered_map<string,vector<vector<string>>*> memo;

    auto finalCombination = allConstruct(target, wordBank,memo);

    if (finalCombination != nullptr && !finalCombination->empty())
    {
        //cout << "ok"<<endl;
        for (auto p = finalCombination->begin(); p != finalCombination->end(); ++p)
        {
            for (auto x : *p)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "Not possible" << endl;
    }
    delete finalCombination;
}