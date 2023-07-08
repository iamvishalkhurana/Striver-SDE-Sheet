//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int mod=1e5;
        queue<pair<int,int>>q;
        q.push({0,start%mod});
        vector<int>dist(100000,INT_MAX);
        dist[start]=0;
        while(!q.empty()){
            auto temp=q.front();q.pop();
            int mul=temp.first,node=temp.second;
            
            if(node==end) return mul;
            for(int i=0;i<arr.size();i++){
                int curr=(arr[i]*node)%mod;
                if(dist[curr]>mul+1){
                    dist[curr]=mul+1;
                    q.push({mul+1,curr});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends