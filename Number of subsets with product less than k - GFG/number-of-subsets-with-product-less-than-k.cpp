//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int f(int ind,int productsoFar,int arr[],int n,int k)
    {
        
        if(productsoFar > k) return 0;
        
        if(ind==n ) {
            return productsoFar <=k ;
        }
        
        int nottake=f(ind+1,productsoFar,arr,n,k);
        
        int take=f(ind+1,productsoFar*arr[ind],arr,n,k);
        
        return take + nottake;
    }

    int numOfSubsets(int arr[], int n, int k) {
        
        return f(0,1,arr,n,k)-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends