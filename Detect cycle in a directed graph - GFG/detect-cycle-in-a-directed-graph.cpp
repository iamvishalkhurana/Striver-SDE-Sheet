//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        bool detect(vector<int>adj[],int i,vector<bool>&visited,vector<bool>&path){
            visited[i]=1;
            path[i]=true;
            for(int x:adj[i]){
                if(!visited[x]){
                    if(detect(adj,x,visited,path)==true) return true;
                    
                }
                else if(path[x]) return true;
            }
            
            path[i]=false;
            
            return false;
            
        }
        
    public:
      
    
        bool isCyclic(int V, vector<int> adj[]) {
            
            vector<bool>visited(V,0);
            vector<bool>path(V,0);
            for(int i=0;i<V;i++){
                if(!visited[i]){
                    if(detect(adj,i,visited,path)==true) return true;
                }
            }
            return false;
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