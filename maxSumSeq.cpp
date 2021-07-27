#include <iostream>

#include <vector>

using namespace std;

int main(){

    int n;

    cin >> n;

    vector<int> vec;

    int k;
    
    for(int i=0;i<n;++i){
        cin >>k;
        vec.push_back(k);
    }

    int maxSum=0,thisSum=0;
    for(int i=0;i<n;++i){

            thisSum+=vec[i];
            if(thisSum>maxSum){
                maxSum=thisSum;
            }
            else if(thisSum<0){
                thisSum=0;
            }         
    }

    cout << maxSum << endl;
}