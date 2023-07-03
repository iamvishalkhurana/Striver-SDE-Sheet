//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
        
    public:
      
    
        bool isCyclic(int V, vector<int> adj[]) {
            
            vector<int>indegree(V,0),topo;
            for(int i=0;i<V;i++){
                for(auto x:adj[i]) indegree[x]++;
            }
            queue<int>q;
            for(int i=0;i<V;i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }
            
            while(!q.empty()){
                int x=q.front();q.pop();
                topo.push_back(x);
                for(int t:adj[x]){
                    indegree[t]--;
                    if(indegree[t]==0) q.push(t);
                }
            }
            
            return topo.size()==V?false:true;
        }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends