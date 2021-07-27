#include <bits/stdc++.h>

using namespace std;

int main(){

    string target;
    string pattern;

    cout << "Enter the Target" << endl;
    cin >>  target;
    cout << "Enter the pattern" <<endl;

    cin>> pattern;

    int n=target.length();
    int m=pattern.length();
    int i,j,k;
    int flag=0;
    for(i=0;i<=n-m;++i){
        k=i;
        for(j=0;j<m;++j){
            if(target[k]!=pattern[j]){
                break;
            }
            k++;
        }
        if(j==m){
            cout << "At index " << i <<  endl;
            flag=1;
        }
    }
    if(flag==0){
        cout << "No match" << endl;
    }
}