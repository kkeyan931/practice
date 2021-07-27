#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(){

    queue<int> q;
    stack<int> s;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << q.front() << endl;
    cout << q.back() << endl << endl;
    stack<int> st;
    int k;

    while(!q.empty()){

        k=q.front();
        cout << k << endl;
        q.pop();
    }

    
}