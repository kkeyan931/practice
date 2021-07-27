#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> *vec1 = new vector<int>;

    vec1->push_back(10);
    vec1->push_back(15);
    vec1->push_back(20);

    vector<int> *vec2 = new vector<int>(*vec1);

    vector<int> vec3 = move(*vec1);

    for(auto p=vec2->begin();p!=vec2->end();++p){
        cout << *p <<  " ";
    }
    
    cout << endl;

    for(auto p=vec1->begin();p!=vec1->end();++p){
        cout << *p <<  " ";
    }

    cout <<endl ;

    for(auto &x : vec3){
        cout << x << " ";
    }
    cout << endl;


    vector<int> vec4;

    copy(vec3.begin(),vec3.end(),back_inserter(vec4));

    for(auto &x : vec4){
        cout << x << " ";
    }
    cout << endl;

}