//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    int loot(int arr[],int i,vector<int>&dp){
        if(i < 0) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int looted=arr[i]+loot(arr,i-2,dp);
        
        int left=loot(arr,i-1,dp);
        
        return dp[i]=max(looted,left);
        
    }
    int FindMaxSum(int arr[], int n)
    {
        vector<int>dp(n,0);
        
        dp[0]=arr[0];
        
        for(int i=1;i<n;i++){
            int looted=arr[i];
            if(i>1) looted+=dp[i-2];
            
            int left=dp[i-1];
            dp[i]=max(left,looted);
        }
        
        return dp[n-1];
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends