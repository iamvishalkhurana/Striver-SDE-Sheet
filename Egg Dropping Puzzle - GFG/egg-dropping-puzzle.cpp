//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int Drop(int n,int k,vector<vector<int>>&dp){
        if(n==1 || k==0 || k==1){
           return k;
       }
       
       if(dp[n][k]!=-1) return dp[n][k];
       
       int mini=INT_MAX;
       
       for(int i=1;i<=k;i++){
           int broke=Drop(n-1,i-1,dp);
           int notbreak=Drop(n,k-i,dp);
           
           int temp=1+max(broke,notbreak);
           
           mini=min(temp,mini);
       }
       return dp[n][k]=mini;
    }
    int eggDrop(int n, int k) 
    {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        
        return Drop(n,k,dp);
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends