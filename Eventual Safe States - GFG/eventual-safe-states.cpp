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
            
        vector<int>newgraph[V];

        for(int i=0;i<V;i++){
            for(int j:adj[i]){
                newgraph[j].push_back(i);
            }
        }
        
        vector<int>indegree(V,0);
        
        for(int i=0;i<V;i++){
            for(int j:newgraph[i]) indegree[j]++;
        }
        
        queue<int>q;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int>ans;
        
        while(!q.empty()){
            int t=q.front();q.pop();
            ans.push_back(t);
            
            for(int x:newgraph[t]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
        
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