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

    vector<int> table(target.size() + 1, 0);

    table[0] = 1;
    for (int i = 0; i <= target.size(); ++i)
    {
        if (table[i] > 0)
        {

            for (auto &word : wordBank)
            {

                // int index = target.find(word, i);
                // if (index != string::npos && index == i)
                // {
                //     index += word.size();
                //     table[index] += table[i];
                // }
                if (target.substr(i,word.length())==word)
                {
                    table[i+word.length()] += table[i];
                }
            }
        }
    }

    for (auto &x : table)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << "Count : " << table[target.size()] << endl;
}
