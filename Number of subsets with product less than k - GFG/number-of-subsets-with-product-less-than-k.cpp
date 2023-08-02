//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int f(int ind,int productsoFar,int arr[],vector<vector<int>>&dp,int k)
{
    if(productsoFar > k)
      return 0;
      
    if(ind < 0)
    {
        return (productsoFar <= k);
    }
    
    if(dp[ind][productsoFar]!=-1) return dp[ind][productsoFar];
    
    int nottake=f(ind-1,productsoFar,arr,dp,k);
    
    int take=0;
    
    if(arr[ind]<=k) take=f(ind-1,productsoFar*arr[ind],arr,dp,k);
    
    return dp[ind][productsoFar]=take+nottake;
}

    int numOfSubsets(int arr[], int n, int k) {
        
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return f(n-1,1,arr,dp,k)-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends