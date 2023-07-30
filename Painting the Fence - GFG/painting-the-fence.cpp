//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int mod=1e9+7;
    long long countWays(int n, int k){
        
        long long dp1=k;
        long long dp2=(k*k) % mod;
        
        for(int i=3;i<=n;i++){
            long long curr= ( (dp2*(k-1))%mod + ( dp1*(k-1) )%mod) %mod;
            dp1=dp2;
            dp2=curr;
        }
        return n==1 ? dp1 : dp2;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends