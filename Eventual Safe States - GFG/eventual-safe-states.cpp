//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     bool detect(vector<int>adj[],int i,vector<bool>&visited,vector<bool>&path,vector<bool>&check){
            visited[i]=1;
            path[i]=true;
            check[i]=true;
            for(int x:adj[i]){
                if(!visited[x]){
                    if(detect(adj,x,visited,path,check)==true) return true;
                    
                }
                else if(path[x]) return true;
            }
            
            check[i]=false;
            path[i]=false;
            
            return false;
            
        }
        
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<bool>visited(V,0);
            vector<bool>path(V,0),check(V,0);
            for(int i=0;i<V;i++){
                if(!visited[i]){
                    detect(adj,i,visited,path,check);
                }
            }
            
            vector<int>x;
            for(int i=0;i<V;i++){
                if(check[i]==0){
                    x.push_back(i);
                }
            }
            return x;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends