#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> longestPalin(string S)
{

    int n = S.length();
    vector<vector<int>> table(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
    {
        table[i][i] = 1;
    }
    for (int i = 0, j = 1; j < n; ++i, j++)
    {
        if (S[i] == S[j])
        {
            table[i][j] = 1;
        }
    }
    int start = 0, maxLength = 1;
    for (int gap = 2; gap < n; ++gap)
    {
        for (int l = 0, h = gap; h < n; ++l, ++h)
        {
            if (S[l] == S[h] && table[l + 1][h - 1] == 1)
            {
                table[l][h] = 1;

                if (maxLength < h)
                {
                    start = l;
                    maxLength = h;
                }
            }
        }
    }

    // return S.substr(start, maxLength);
    return table;
}
int main()
{

    string str;

    cin >> str;

    // cout << longestPalin(str) << endl;

    auto table = longestPalin(str);

    cout << endl;

    for(auto & x: table){
        for(auto &y :x){
            cout << y << " ";
        }
        cout << endl;
    }
}
