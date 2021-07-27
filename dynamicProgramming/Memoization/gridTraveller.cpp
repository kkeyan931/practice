#include <bits/stdc++.h>

using namespace std;

long long int gridTraveller(vector<vector<long long int>> &grid,int m,int n){
    if(grid[m][n]!=0)
        return grid[m][n];
    else if(m==0 || n==0){
        return 0;
    }
    else if(n==1 && m==1){
        return 1;
    }
    grid[m][n] = gridTraveller(grid,m-1,n) + gridTraveller(grid,m,n-1);
    grid[n][m] = grid[m][n];
    return grid[m][n];
}

int main(){

    cout << "Enter two numbers " << endl;
    int m,n;

    cin >> m;
    cin >> n;

    vector<long long int> row(n+1);
    vector<vector<long long int>> grid;

    for(int i=0;i<=m;i++){
        grid.push_back(row);
    }

    cout << "Possibility : " << gridTraveller(grid,m,n) << endl;

    // for(auto &x : grid){
    //     for(auto &y : x){
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // } 
}