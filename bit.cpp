#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int div = i / 2;
            int rem = i % 2;
            a[i] = a[div] + rem;
        }

        return a;

        unordered_map<int,int> map;
        map.
        
    }
};