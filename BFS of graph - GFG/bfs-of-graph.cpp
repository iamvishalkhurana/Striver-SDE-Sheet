//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool>visited(V,0);
        vector<int>BFS;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int t=q.front();q.pop();
            int n=adj[t].size();
            BFS.push_back(t);
            for(int j=0;j<n;j++){
                if(!visited[adj[t][j]]){
                    q.push(adj[t][j]);
                    visited[adj[t][j]]=true;
                } 
            }
        }
        return BFS;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends