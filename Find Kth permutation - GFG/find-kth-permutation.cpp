//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        vector<int>v(n);
        for(int i=0;i<n;i++){
            v[i]=(i+1);
        }
        
        for(int i=1;i<k;i++){
            next_permutation(v.begin(),v.end());
        }
        
        string s="";
        
        for(int i=0;i<n;i++){
            s+=to_string(v[i]);
        }
        
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends