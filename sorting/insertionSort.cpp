#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector<int> &arr){
    for(int i=1;i<arr.size();++i){
        // int j=i;
        // while(j>0 && arr[j-1]>arr[j]){
        //     swap(arr[j-1],arr[j]);
        //     j--;
        // }
        int value=arr[i];
        int hole=i;
        while(hole>0 && arr[hole-1]>value){
            arr[hole]=arr[hole-1];
            hole--;
        }
        arr[hole]=value;

    }
}

int main(){

    cout << "Enter number of elements"<< endl;

    int n; 
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;++i){
        arr[i]=rand()%1000;
    }

    insertionSort(arr);

    for(int i=0;i<n;++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}
