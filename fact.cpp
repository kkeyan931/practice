#include <bits/stdc++.h>
using namespace std;

vector<long long> factorial(vector<long long> &a, int n) {
        
        auto max = max_element(a.begin(),a.end());
        
        long long fact=1;
        unordered_map<int,long long> memo;
        memo[0]=0;
        for(int i=1;i<=*max;++i){
            fact *= i;
            memo[i]=fact;
        }
        
        vector<long long> ans;
        for(int i=0;i<n;++i){
            ans.push_back(memo[ans[i]]);
        }
        return ans;

}

int main(){

    vector<long long> a = {10,2,3,4,5};

    auto vec = factorial(a,5);

    for(auto &x : vec){
        cout << x << " ";
    }
    cout << endl;

}