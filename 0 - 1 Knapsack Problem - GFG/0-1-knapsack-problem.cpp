//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int recursive_knapsack(int rem_wt,int wt[],int val[],int n,int i,vector<vector<int>>&dp){
        if(i==n){
            return 0;
        }
        
        if(dp[i][rem_wt]!=-1) return dp[i][rem_wt];
        
        int nottake=recursive_knapsack(rem_wt,wt,val,n,i+1,dp);
        
        int take=0;
        
        if(rem_wt>=wt[i]) take=val[i]+recursive_knapsack(rem_wt-wt[i],wt,val,n,i+1,dp);
        
        return dp[i][rem_wt]=max(take,nottake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<int>dp(W+1,0);
       
       for(int i=n-1;i>=0;i--){
           vector<int>curr(W+1,0);
           for(int rem_wt=0;rem_wt<=W;rem_wt++){
               int nottake=dp[rem_wt];
               
               int take=0;
               
               if(rem_wt>=wt[i]) take=val[i]+dp[rem_wt-wt[i]];
               
               curr[rem_wt]=max(take,nottake);
           }
           dp=curr;
       }
       
       return dp[W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends