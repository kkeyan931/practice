#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main(){

        unordered_map<int,int> counter;

        for(int i;cin >> i;){
            counter[i]++;
        }
        for(auto &m : counter){
            cout << m.first << ":" << m.second << endl;
        }

}