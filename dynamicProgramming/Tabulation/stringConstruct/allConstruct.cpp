#include <bits/stdc++.h>

using namespace std;

int main()
{

    string target;
    cout << "Enter the target string" << endl;
    cin >> target;

    cout << "Enter the Array Size" << endl;
    int n;
    cin >> n;
    cout << "Enter the Array Conntents" << endl;

    vector<string> wordBank;
    string str;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        wordBank.push_back(str);
    }
    vector<vector<vector<string>> *> table(target.size() + 1, nullptr);

    table[0] = new vector<vector<string>>;

    for (int i = 0; i <= target.length(); ++i)
    {

        if (table[i] != nullptr)
        {
            for (auto &word : wordBank)
            {
                if (target.substr(i, word.length()) == word)
                {
                    int index = i + word.length();

                    //table[index] = new vector<vector<string>>(*table[i]);
                    if (table[index] == nullptr)
                    {
                        table[index] = new vector<vector<string>>;
                    }
                    auto temp = new vector<vector<string>>(*table[i]);
                    if(i==0){
                        vector<string> temp1;
                        temp1.push_back(word);
                        temp->push_back(temp1);
                    }
                    else{
                        for(auto p=temp->begin();p!=temp->end();++p){
                            p->push_back(word);
                        }
                    }
                    for(auto p=temp->begin();p!=temp->end();++p){
                        table[index]->push_back(*p);
                    }

                }
            }
        }
    }

    if (table[target.length()] != nullptr)
    {
        for (auto p = table[target.length()]->begin(); p != table[target.length()]->end(); ++p)
        {
            cout << "[";
            for (auto &x : *p)
            {
                cout << x << " ";
            }
            cout << "]";
            cout << endl;
        }
    }
}
