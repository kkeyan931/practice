#include <bits/stdc++.h>

using namespace std;

int partition(int start,int end,vector<int> &arr){

    int pivot = arr[end];
    int pivotIndex = start;
    for(int i=start;i<end;++i){
        if(arr[i]<=pivot){
            swap(arr[i],arr[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(arr[pivotIndex],arr[end]);
    return pivotIndex;
}

int randomizedPartition(int start,int end,vector<int> &arr){

    int pivotIndex = rand()%end+1;
    if(pivotIndex<start){
        pivotIndex = start;
    }
    swap(arr[pivotIndex],arr[end]);
    return partition(start,end,arr);
}



void quickSort(int start,int end,vector<int> &arr){

    if(start<end){
        int pivotIndex = randomizedPartition(start,end,arr);
        quickSort(start,pivotIndex-1,arr);
        quickSort(pivotIndex+1,end,arr);
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

    quickSort(0,n-1,arr);

    for(int i=0;i<n;++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}