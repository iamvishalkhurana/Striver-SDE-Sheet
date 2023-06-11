//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> addOne(int a[], int n) {
        vector<int>ans(n);
        
        for(int i=0;i<n;i++) ans[i]=a[i];
        
        int carry=1,sum;
        
        for(int i=n-1;i>=0;i--){
            sum=(ans[i]+carry)%10;
            carry=(ans[i]+carry)/10;
            
            ans[i]=sum;
            
            if(carry==0) break;
            
            
        } 
        
        if(carry==1) ans.insert(ans.begin(),1);
        
        return ans;
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.addOne(a, n);
        printAns(ans);
    }
    return 0;
}
// } Driver Code Ends