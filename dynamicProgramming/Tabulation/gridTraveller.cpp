#include <bits/stdc++.h>

using namespace std;

int main(){

    cout << "Enter the dimension" << endl;
    int m,n;
    cin >> m;
    cin >> n;

    vector<vector<long int>> table(m+1, vector<long int>(n+1,0));
    
    table[1][1] =1;

    cout << endl;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            int current = table[i][j];
            if(j+1 <= n) table[i][j+1] = table[i][j+1]+ current;
            if(i+1 <= m) table[i+1][j] = table[i+1][j] + current;
        }
    }

    cout << "possibility : "<< table[m][n] << endl;
}