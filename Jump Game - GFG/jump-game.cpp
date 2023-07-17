//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool jump(int A[],int i,int n,vector<int>&dp){
        if(i==n-1) return true;
        
        if(dp[i]!=-1) return dp[i];
        for(int j=1;j<=A[i];j++){
            if(jump(A,i+j,n,dp)==true){
                return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    int canReach(int A[], int N) {
        vector<int>dp(N,0);
        dp[N-1]=1;
        for(int i=N-2;i>=0;i--){
            
            for(int j=1;j<=A[i];j++){
                if(i+j<N && dp[i+j]==1){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends