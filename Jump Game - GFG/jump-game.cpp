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
        vector<int>dp(N,-1);
        return jump(A,0,N,dp);
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