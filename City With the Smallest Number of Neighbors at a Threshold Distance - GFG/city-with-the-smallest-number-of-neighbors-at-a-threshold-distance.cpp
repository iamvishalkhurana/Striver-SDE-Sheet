//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
        
        vector<vector<int>>adj(n,vector<int>(n,INT_MAX));
        
        for(int i=0;i<m;i++){
            adj[edges[i][0]][edges[i][1]]=edges[i][2];
            adj[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        
        for(int i=0;i<n;i++) adj[i][i]=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    
                    if(adj[j][i]==INT_MAX || adj[i][k]==INT_MAX) continue;
                    
                    adj[j][k]=min(adj[j][k],adj[j][i]+adj[i][k]);
                }
            }
        }
        
        int max_count=INT_MAX,ind=0;
        
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                
                if(adj[i][j]<=distanceThreshold) count++;
            }
            if(count <= max_count){
                ind=i;
                max_count=count;
            }
            
        }
        return ind;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends