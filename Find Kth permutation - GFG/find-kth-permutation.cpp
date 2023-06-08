//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    
    void next_perm(vector<int>&v){
        int k=-1;
        int n=v.size();
        for(int i=n-2;i>=0;i--){
            if(v[i]<v[i+1]){
                k=i;break;
            }
        }
        
        if(k==-1){
            reverse(v.begin(),v.end());
        }
        
        for(int i=n-1;i>k;i--){
            if(v[i]>v[k]){
                swap(v[i],v[k]);
                break;
            }
        }
        
        reverse(v.begin()+k+1,v.end());
    }
    
    string kthPermutation(int n, int k)
    {
        vector<int>v(n);
        for(int i=0;i<n;i++){
            v[i]=(i+1);
        }
        
        for(int i=1;i<k;i++){
            next_perm(v);
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