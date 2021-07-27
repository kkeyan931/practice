#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter a number" << endl;
    cin >> n;

    vector<long int> table(n+1);

    table[1]=1;
    for(int i=0;i<=n;++i){
        table[i+1] += table[i];
        table[i+2] += table[i];
    }

    cout << "Fib : " << table[n] << endl;

    // vector<int>  vec;
    // vec.push_back(10);

    // cout << vec[1] << endl;
}