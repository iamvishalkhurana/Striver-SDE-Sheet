//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int CountAndMerge(vector<int>&arr,int l,int m,int h){
        int n1=m-l+1,n2=h-m;
        
        vector<int>L(n1),R(n2);
        
        for(int i=0;i<n1;i++) L[i]=arr[i+l];
        
        for(int i=0;i<n2;i++) R[i]=arr[m+i+1];
        
        int i=0,j=0,k=l,x=0;
        int res=0;
        while(i<n1 && j<n2){
            while(x<n2 && L[i] > (long)2*R[x]){
                x++;
                res+=n1-i;
            }
            
           if(L[i]<R[j]) arr[k++]=L[i++];
           
           else arr[k++]=R[j++];
        }
        
        while(i<n1) {
             while(x<n2 && L[i] > (long)2*R[x]){
                x++;
                res+=n1-i;
            }
            arr[k++]=L[i++];
        }
        
        while(j<n2) arr[k++]=R[j++];
        
        return res;
    }
    int CountReverse(vector<int>&arr,int l,int h){
        int res=0;
        if(h>l){
            int m=l+(h-l)/2;
            res+=CountReverse(arr,l,m);
            res+=CountReverse(arr,m+1,h);
            res+=CountAndMerge(arr,l,m,h);
        }
        return res;
    }
    int countRevPairs(int n, vector<int> arr) {
        return CountReverse(arr,0,n-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends