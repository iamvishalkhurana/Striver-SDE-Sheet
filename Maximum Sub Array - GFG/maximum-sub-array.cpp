//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int arr[], int n) {
	    vector<int>curr;
	    
	    int maxSum=-1;
	    int sum=0;
	    vector<int>ans;
	    
	    for(int i=0;i<n;i++){
	        
	        if(arr[i]<0){
	            
	            if(sum > maxSum){
	                ans=curr;
	                maxSum=sum;
	            }
	            
	            else if(sum==maxSum){
	                if(curr.size()> ans.size()){
	                    ans=curr;
	                }
	            }
	            
	            sum=0;
	            curr.clear();
	            continue;
	        }
	        
	        sum+=arr[i];
	        curr.push_back(arr[i]);
	    }
	    
	    if(sum > maxSum){
	           ans=curr;
	           maxSum=sum;
	       }
	            
	    else if(sum==maxSum){
	       if(curr.size()> ans.size()){
	           ans=curr;
	       }
	    }
	   
	    
	    if(ans.size()==0){
	        ans.push_back(-1);
	        return ans;
	    }
	    return ans;
	    
	}
	
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends