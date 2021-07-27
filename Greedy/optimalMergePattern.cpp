#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main(){
    
    cout << "Enter the number of list" << endl;
    int n;
    cin >> n;

    priority_queue<int,vector<int>,greater<int>> q;
    
    cout << "Enter the sizes of list" << endl;
    register int k;
    for(int i=0;i<n;++i){
        cin >> k;
        q.push(k);
    }

    int solution=0;

    int j1,j2;
    while(q.size()!=1){
        j1 = q.top();
        q.pop();
        j2 = q.top();
        q.pop();
        solution += j1+j2;
        q.push(j1+j2);
    }

    cout << "Optimal Merge Pattern : " << solution << endl;
}