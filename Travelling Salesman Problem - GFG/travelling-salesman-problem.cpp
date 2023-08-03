//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int tsp(int mask,int i,int all,vector<vector<int>>&cost,vector<vector<int>>&dp){
    if(mask==all){
        return cost[i][0];
    }
    
    int total=INT_MAX;
    if(dp[mask][i]!=-1) return dp[mask][i];
    
    for(int city=0; city< cost.size();city++){
        if((mask & (1<<city))==0){
            int curr=cost[i][city]+ tsp( mask | (1<<city) , city, all ,cost,dp);
            total=min(total,curr);
        }
    }
    return dp[mask][i]=total;
}
int total_cost(vector<vector<int>>cost){
    
    int n=cost.size();
    
    int all=(1<<n)-1;
    vector<vector<int>>dp(all+1,vector<int>(n+1,-1));
    return tsp(1,0,all,cost,dp);
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends