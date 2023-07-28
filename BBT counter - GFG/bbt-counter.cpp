//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int mod=1e9+7;
    long long Count(int h,vector<int>&dp){
        if(h==0 || h==1) return 1;
        
        if(dp[h]!=-1) return dp[h];
        
        return dp[h]=(Count(h-1,dp)*(((2*Count(h-2,dp))%mod + Count(h-1,dp)))%mod)%mod;
    }
    long long int countBT(int h) { 
        
        vector<int>dp(h+1,-1);
        return Count(h,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}

// } Driver Code Ends