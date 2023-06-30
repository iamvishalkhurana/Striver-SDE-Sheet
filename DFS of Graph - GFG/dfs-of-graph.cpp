//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    void dfs (vector<int> adj[],int i,vector<bool>&visited,vector<int>&DFS){
        if(visited[i]) return;
        
        DFS.push_back(i);
        visited[i]=1;
        for(auto t:adj[i]){
            if(!visited[t]){
                dfs(adj,t,visited,DFS);
            }
        }
    }
        
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool>visited(V,0);
        vector<int>DFS;
        
        if(!visited[0]) dfs(adj,0,visited,DFS);
        
        return DFS;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends