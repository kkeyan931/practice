#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){

    set<int,greater<int>> s;
    vector<int> vec{1,2,3,4};
    int k;
    for(int i=0;i<10;++i)
    {
        cin >> k;
        s.insert(k);
    }

    for(auto p=vec.begin();p!=vec.end();p++){
        *p=5;
    }

    for(auto &k : s){
        cout << k << " ";
    }
}