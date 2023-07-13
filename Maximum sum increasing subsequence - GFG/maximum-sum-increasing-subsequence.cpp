//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
    
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
	    
	    for(int i=n-1;i>=0;i--){
	        
	        for(int prev=i-1;prev >=-1 ;prev--){
	            int take=0;
	    
        	    if(prev==-1 || arr[i]>arr[prev]){
        	        take=arr[i]+dp[i+1][i+1];
        	    }
        	    
        	    int nottake=dp[i+1][prev+1];
        	    
        	    dp[i][prev+1]=max(take,nottake);
	        }
	    }
	    return dp[0][0];
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends