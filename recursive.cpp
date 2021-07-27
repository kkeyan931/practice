#include<iostream>

using namespace std;

int fun(int num){

    if(num == 0 ){
        return num;
    }
    return 2*fun(num-1) + (num*num);
}

int main(){

    int num;
    cin >> num;

    cout << fun(num) << endl;
}