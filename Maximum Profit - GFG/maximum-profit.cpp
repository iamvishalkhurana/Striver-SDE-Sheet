//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int LimitedTransactions(int i,int canBuy,int K,int N,int A[],vector<vector<vector<int>>>&dp){
        if(i==N || K==0) return 0;
        
        if(dp[i][canBuy][K]!=-1) return dp[i][canBuy][K];
        
        if(canBuy){
            int buy=LimitedTransactions(i+1,0,K,N,A,dp)-A[i];
            int notBuy=LimitedTransactions(i+1,1,K,N,A,dp);
            
            return dp[i][canBuy][K]=max(buy,notBuy);
            
        }
        else{
            int sell=LimitedTransactions(i+1,1,K-1,N,A,dp)+A[i];
            int notSell=LimitedTransactions(i+1,0,K,N,A,dp);
            return dp[i][canBuy][K]=max(sell,notSell);
        }
        
    }
    int maxProfit(int K, int N, int A[]) {
        vector<vector<vector<int>>>dp(N,vector<vector<int>>(2,vector<int>(K+1,-1)));
        return LimitedTransactions(0,1,K,N,A,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends