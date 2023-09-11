//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        
        int XOR=0;
        for(int i=0;i<n;i++){
            XOR=XOR^arr[i];
            XOR=XOR^(i+1);
        } 
        
        
        int t=(XOR & ~(XOR-1));
        
        
        int x1=0,x2=0;
        
        for(int i=0;i<n;i++){
            if(arr[i] & t) x2=x2^arr[i];
            else x1=x1^arr[i];
        }
        
        for(int i=1;i<=n;i++){
            if(i & t) x2=x2^i;
            else x1=x1^i;
        }
        
        for(int i=0;i<n;i++){
            if(arr[i]==x1){
                return {x1,x2};
            }
        }
        
        return {x2,x1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends