//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int rec(int arr[],vector<vector<int>>&dp,int i,int j){
        if(i==j){
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int min_steps=INT_MAX;
        for(int k=i;k<j;k++){
            int steps=arr[i-1]*arr[k]*arr[j]+rec(arr,dp,i,k)+rec(arr,dp,k+1,j);
            min_steps=min(min_steps,steps);
        }
        return dp[i][j]=min_steps;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N,vector<int>(N,-1));
        return rec(arr,dp,1,N-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends