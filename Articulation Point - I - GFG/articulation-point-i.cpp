//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int timer=1; 
    set<int>bridges;
    void dfs(int node,int parent,vector<int>&visited,vector<int>adj[],int tin[],int low[]){
        visited[node]=1;
        tin[node]=low[node]=timer++;
        int child=0;
        for(auto it:adj[node]){
            if(it==parent ) continue;
            
            if(!visited[it]){
                dfs(it,node,visited,adj,tin,low);
                low[node]=min(low[node],low[it]);
                if(low[it] >= tin[node] && parent!=-1){
                    bridges.insert({node});
                }
                child++;
            }
            else{
                low[node]=min(low[node],tin[it]);
            }
        }
        
        if(parent==-1 && child>1){
            bridges.insert({node});
        }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int>visited(V,0);
        int tin[V];
        int low[V];
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,-1,visited,adj,tin,low);
            }
        }
        if(bridges.size()==0) return {-1};
        vector<int>pts(bridges.begin(),bridges.end());
        return pts;
    }
    
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends