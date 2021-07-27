// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        
        vector<int> right(n,0);
        vector<int> left(n,0);
        int rightMax = -1;
        for(int i=0;i<n;++i){
            if(rightMax < arr[i]){
                rightMax = arr[i];
            }
            if(arr[i]>0){
                right[i]=rightMax-arr[i];
            }
            else{
                right[i]=rightMax;
            }
        }
        int leftMax = -1;
        for(int i=n-1;i>=0;--i){
            if(leftMax < arr[i]){
                leftMax=arr[i];
            }
            if(arr[i]>0){
                left[i] = leftMax-arr[i];
            }
            else{
                left[i]=leftMax;
            }
        }
        
        int sum=0;
       for(int i=0;i<n;++i){
            sum+=min(left[i],right[i]);
        }
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends