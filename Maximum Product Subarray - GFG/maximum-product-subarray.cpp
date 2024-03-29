//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	long long max(long long a,long long b){
	    if(a>b){
	        return a;
	    }
	    return b;
	}
	long long min(long long a,long long b){
	    if(a<b){
	        return a;
	    }
	    return b;
	}
	
	
	long long maxProduct(vector<int> arr, int n) {
	    long long ans=arr[0],maxi=arr[0],mini=arr[0];
	    for(int i=1;i<n;i++){
	        if(arr[i]<0){
	            swap(maxi,mini);
	        }
	        maxi=max(arr[i],arr[i]*maxi);
	        mini=min(arr[i],arr[i]*mini);
	        ans=max(ans,maxi);
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends