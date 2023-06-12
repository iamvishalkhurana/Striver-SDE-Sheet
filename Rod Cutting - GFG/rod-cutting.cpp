//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int>dp(n+1,0);
        
        for(int i=0;i<=n;i++){
            dp[i]=price[0]*i;
        }
        
        for(int i=1;i<n;i++){
            vector<int>curr(n+1,0);
            for(int rod=0;rod<=n;rod++){
                int cut=-1e9;
                if(rod>=i+1) cut=price[i]+curr[rod-i-1];
                
                int notcut=dp[rod];
                
                curr[rod]=max(cut,notcut);
            }
            dp=curr;
        }
        
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends