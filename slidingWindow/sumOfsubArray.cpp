#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout << "Enter N" << endl;
    cin >> n;
    
    vector<int> vec;

    cout << "Enter N elements" << endl;
    int j;
    for(int i=0;i<n;++i){
        cin >> j;
        vec.push_back(j);
    }

    cout << "Enter K" << endl;

    int k;
    cin >> k;

    int maxSum=0;
    for(int i=0;i<k;++i){
        maxSum+=vec[i];
    }

    int windowSum;
    cout << maxSum << " ";
    for(int i=1;i<=n-k;++i){
        windowSum=maxSum + vec[i+k-1]-vec[i-1];
        maxSum=windowSum;
        cout << windowSum << " ";
    }
    cout << endl;
}