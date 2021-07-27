#include <iostream>

using namespace std;

void printOut(long long int num){

    if(num >= 10){
        printOut(num/10);
    }

    cout << num%10;
}

long long int fact(long long int num){

    if(num==1 || num==0){
        return num;
    }

    return num * fact(num-1);
}

int main(){

    long long int num = 1324553535353532424;

    printOut(num);

    cout << endl;

    cout << fact(30);
}