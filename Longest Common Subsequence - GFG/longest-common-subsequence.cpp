//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int lcs(int n, int m, string s1, string s2)
    {
        vector<int>dp(m+1,0);
        
        for(int i=n-1;i>=0;i--){
            vector<int>curr(m+1,0);
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    curr[j]=1+dp[j+1];
                }
                else{
                    curr[j]=max(dp[j],curr[j+1]);
                }
            }
            dp=curr;
        }
        
        
        return dp[0];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends