//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
    
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int>dp(n+1,0);
	    
	    for(int i=n-1;i>=0;i--){
	        vector<int>curr(n+1,0);
	        for(int prev=i-1;prev >=-1 ;prev--){
	            int take=0;
	    
        	    if(prev==-1 || arr[i]>arr[prev]){
        	        take=arr[i]+dp[i+1];
        	    }
        	    
        	    int nottake=dp[prev+1];
        	    
        	    curr[prev+1]=max(take,nottake);
	        }
	        dp=curr;
	    }
	    return dp[0];
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