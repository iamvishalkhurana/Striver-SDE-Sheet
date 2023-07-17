//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool jump(int A[],int i,int n){
        if(i>=n-1) return true;
        
        for(int j=1;j<=A[i];j++){
            if(jump(A,i+j,n)==true){
                return true;
            }
        }
        return false;
    }
    int canReach(int A[], int N) {
        return jump(A,0,N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends