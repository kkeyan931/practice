#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<vector<int>> mat;

    int k;
    for(int i=0;i<2;++i){
        vector<int> row;
        for(int j=0;j<4;++j){
            cin >> k;
            row.push_back(k);
        }
        mat.push_back(row);
    }

    for(int i=0;i<mat.size();++i){
        for(int j=0;j<mat[0].size();++j){
            cout << mat[i][j]<<" ";
        }
        cout << endl;
    }
}