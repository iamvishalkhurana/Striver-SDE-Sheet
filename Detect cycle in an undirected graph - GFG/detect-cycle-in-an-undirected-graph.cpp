//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        bool detect(vector<int>adj[],int i,vector<bool>&visited,int par){
            visited[i]=1;
            
            for(auto x:adj[i]){
                if(!visited[x]){
                    if(detect(adj,x,visited,i)==true) return true;
                }
                else if(par!=x){
                    return true;
                }
            }
            return false;
        }
    
    
    public:
    
        bool isCycle(int V, vector<int> adj[]) {
            
            vector<bool>visited(V,0);
            
            for(int i=0;i<V;i++){
                if(!visited[i]){
                    if(detect(adj,i,visited,-1)==true){
                        return true;
                    }
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