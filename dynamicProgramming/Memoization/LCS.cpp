#include <bits/stdc++.h>

using namespace std;

int LCS(string str1,string str2){

    if(str1.empty() || str2.empty()){
        return 1;
    }
    int count = 0;
    int max = 0;
    for(int i=0;i<str2.size();++i){
        int index = str1.find(str2[i]);
        if(index!=string::npos){

            count = count + LCS(str1.substr(index+1),str2.substr(i+1));
            if(count > max){
                max = count;
            }
        }
    }
    return max;
}

int main(){
    string str1,str2;
    cout << "Enter the first string" << endl;
    cin >> str1;
    cout << "Enter the second String" << endl;

    cin >> str2;

    cout << "LCS : "<< LCS(str1,str2) << endl;

}