#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int firstFit(int &n,vector<int> &object,int &c){

    int res=0;
    int bin_rem[n];

    for(int i=0;i<n;++i){

        int j;
        for(j=0;j<res;++j){
            if(bin_rem[j] >= object[i]){
                bin_rem[j] = bin_rem[j]-object[i];
                break;
            }
        }

        if(j==res){
            bin_rem[j]=c-object[i];
            res++;
        }
    }

    return res;
}

int firstFitDecreasing(int &n,vector<int> &object,int &c){

    sort(object.begin(),object.end(),greater<int>());

    return firstFit(n,object,c);
}
int main(){

    int n;
    cout << "Enter number of Objects" << endl;
    cin >> n;

    cout << "Enter the objects" << endl;

    vector<int> objects;
    int k;
    for(int i=0;i<n;++i){
        cin >> k;
        objects.push_back(k);
    }
    cout << "Enter Bin Capacity" << endl;
    int c;

    cin >> c;
    cout << "Minimum number of Bins : " << firstFitDecreasing(n,objects,c) << endl;


}