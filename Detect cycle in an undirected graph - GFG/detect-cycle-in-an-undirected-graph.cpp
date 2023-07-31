//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(vector<int>adj[],int i,vector<int>&visited,int par){
        visited[i]=1;
        for(int t:adj[i]){
            if(!visited[t]){
                if(dfs(adj,t,visited,i)) return true;
            }
            else if(t!=par){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(adj,i,visited,-1)==true) return true;
            }
        }
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends