//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minimumCoins(int coins[],int i,int M,int V,vector<vector<int>>&dp){
	    if(i==M-1){
	        
	        if(V%coins[i]==0) return V/coins[i];
	        
	        return 1e8;
	    }
	    
	    if(dp[i][V]!=-1) return dp[i][V];
	    
	    int nottake=minimumCoins(coins,i+1,M,V,dp);
	    
	    int take=1e8;
	    
	    if(V>=coins[i]) take=1+minimumCoins(coins,i,M,V-coins[i],dp);
	    
	    return dp[i][V]=min(take,nottake);
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>>dp(M,vector<int>(V+1,-1));
	    int ans=minimumCoins(coins,0,M,V,dp);
	    return ans==1e8?-1:ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends