#include <bits/stdc++.h>

using namespace std;

void selectionSort(vector<int> &arr){
    int imin;
    for(int i=0;i<arr.size();++i){
        imin=i;
        for(int j=i+1;j<arr.size();++j){
            if(arr[j]<arr[imin]){
                imin = j;

            }
        }
        swap(arr[i],arr[imin]);
    }
}

int main(){

    cout << "Enter number of elements"<< endl;

    int n; 
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;++i){
        arr[i]=rand()%100;
    }

    selectionSort(arr);

    for(int i=0;i<n;++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}
