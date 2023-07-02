//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bi_bfs(vector<int>adj[],int i,vector<int>&colored){
       queue<int>q;
	   q.push(i);
	   colored[i]=0;
	   while(!q.empty()){
	       int n=q.size();
	       for(int i=0;i<n;i++){
	           int x=q.front();q.pop();
	           for(auto t:adj[x]){
	               if(colored[t]==-1){
	                   colored[t]=!colored[x];
	                   q.push(t);
	               }
	               else if(colored[t]==colored[x]){
	                   return false;
	               }
	           }
	       }
	   }
	   return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	   vector<int>colored(V,-1);
	   for(int i=0;i<V;i++){
	       if(colored[i]==-1){
	           if(bi_bfs(adj,i,colored)==false) return false;
	       }
	   }
	   return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends