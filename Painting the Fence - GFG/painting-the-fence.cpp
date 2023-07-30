//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int mod=1e9+7;
    long long countways(int n,int k,vector<int>&dp){
        if(n==1) return k;
        
        if(n==2) return k*k % mod;
        
        if(dp[n]!=-1) return dp[n];
        
        long long ans=((countways(n-2,k,dp)*(k-1))%mod + (countways(n-1,k,dp)*(k-1))%mod)%mod;
        
        return dp[n]=ans;
    }
    long long countWays(int n, int k){
        vector<int>dp(n+1,-1);
        return countways(n,k,dp);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends