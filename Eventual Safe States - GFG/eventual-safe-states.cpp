//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     
    bool detect(vector<int>adj[],int i,vector<int>&visited){
            visited[i]=1;
            for(int x:adj[i]){
                if(!visited[x]){
                    if(detect(adj,x,visited)==true) return true;
                    
                }
                else if(visited[x]==1) return true;
            }
            
            visited[i]=2;
            return false;
            
        }
        
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
            vector<int>visited(V,0);
            for(int i=0;i<V;i++){
                if(!visited[i]){
                    detect(adj,i,visited);
                }
            }
            
            vector<int>x;
            for(int i=0;i<V;i++){
                if(visited[i]==2){
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