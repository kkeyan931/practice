#include <bits/stdc++.h>

using namespace std;

void computeLPS(vector<int> &lps, const string &pattern, int m)
{

    int i = 1;
    int len = 0;

    lps[0] = 0;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {

            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> kmpAlgo(const string target,
                    const string pattern, vector<int> &lps, int n, int m)
{
    computeLPS(lps,pattern,m);

    int i=0;
    int j=0;
    vector<int> indexes;
    while(i<n){
        if(target[i]==pattern[j]){
            i++;
            j++;
        }
        if(j==m){
            indexes.push_back(i-m);
            j=lps[j-1];
        }
        else if(i<n && target[i]!=pattern[j]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i=i+1;
            }
        }
    }

    return indexes;
}

int main()
{

    string target;
    string pattern;

    cout << "Enter the Target" << endl;
    cin >> target;
    cout << "Enter the pattern" << endl;

    cin >> pattern;

    int n = target.length();
    int m = pattern.length();

    vector<int> lps(m);

    auto indexes = kmpAlgo(target,pattern,lps,n,m); 

    if(indexes.empty()){
        cout << "No matching" << endl;
    }

    else{
        cout << "found at Indexes" << endl;
        for(auto &x : indexes){
            cout << x << " ";
        }
        cout << endl;
    }
    // for(auto &x: lps){
    //     cout << x << " ";
    // }
    // cout << endl;
}