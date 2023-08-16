//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        
        sort(arr,arr+n);
        
        int minimum_max=arr[n-1]-arr[0];
        
        for(int i=0;i<n;i++){
            
            int maxi=max(arr[i]+k,arr[n-1]-k);
            
            int mini=min(arr[i+1]-k,arr[0]+k);
            
            minimum_max=min(maxi-mini,minimum_max);
            
        }
        
        return minimum_max;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends