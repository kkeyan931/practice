#include <bits/stdc++.h>

using namespace std;

void merge(int l,int mid,int h,vector<int> &arr){

    int nl=mid-l+1;
    int nr=h-mid;
    vector<int> left(nl);
    vector<int> right(nr);

    for(int i=0;i<nl;++i){
        left[i]=arr[l+i];
    }
    for(int i=0;i<nr;++i){
        right[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<nl && j<nr){
        if(left[i]<=right[j]){
            arr[k++]=left[i++];
        }
        else{
            arr[k++]=right[j++];
        }
    }
    while(i<nl){
        arr[k++]=left[i++];
    }
    while(j<nr){
        arr[k++]=right[j++];
    }
}

void mergeSort(int l,int h,vector<int> &arr){

    if(l<h){
        int mid =l+(h-l)/2;
        mergeSort(l,mid,arr);
        mergeSort(mid+1,h,arr);
        merge(l,mid,h,arr);
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

    mergeSort(0,n-1,arr);

    for(int i=0;i<n;++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}
