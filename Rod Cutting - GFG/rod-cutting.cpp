//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int rec(int prices[],int i,int rod,vector<vector<int>>&dp){
        if(i==0) return prices[0]*rod;
        
        if(dp[i][rod]!=-1) return dp[i][rod];
        
        int cut=-1e9;
        if(rod>=i+1) cut=prices[i]+rec(prices,i,rod-i-1,dp);
        
        int notcut=rec(prices,i-1,rod,dp);
        
        return dp[i][rod]=max(cut,notcut);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
        return rec(price,n-1,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends