//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        if(arr[0]==0) return -1;
        
        int jumps=0;
        
        int l=0,r=0;
        
        while( r < n-1 ){
            
            int maxJump=0;
            
            for(int i=l;i<=r;i++){
                maxJump=max(maxJump,i+arr[i]);
            }
            
            if(maxJump==0) return -1;
            
            l=r+1;
            r=maxJump;
            jumps++;
            
        }
        return jumps;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends