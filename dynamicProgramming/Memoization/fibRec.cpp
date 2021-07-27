#include <iostream>
#include <vector>

using namespace std;

long int fib(vector<long int> &vec,int n){
    if(vec[n]!=0){
        return vec[n];
    }
    else if(n==0){
        return 0;
    }
    else if(n==1 || n==2){
        return 1;
    }
    vec[n] = fib(vec,n-1)+fib(vec,n-2);
    return vec[n];
    
}

int main(){
    int n;
    cin >> n;

    vector<long int> vec(n+1,0);

    cout << "Fib : " << fib(vec,n) << endl;
    
}