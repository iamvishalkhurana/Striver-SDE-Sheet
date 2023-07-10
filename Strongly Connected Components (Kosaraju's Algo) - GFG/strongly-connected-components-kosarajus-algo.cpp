//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(vector<vector<int>>& adj,int i, vector<int>&visited,stack<int>&st){
	    visited[i]=1;
	    for(auto x:adj[i]){
	        if(!visited[x]){
	            dfs(adj,x,visited,st);
	        }
	    }
	    st.push(i);
	}
	void dfs1(vector<int>adj[],int i, vector<int>&visited){
	    visited[i]=1;
	    for(auto x:adj[i]){
	        if(!visited[x]){
	            dfs1(adj,x,visited);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int>st;
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj,i,visited,st);
            }
        }
        
        vector<int>graph[V];
        for(int i=0;i<V;i++){
            visited[i]=0;
            for(auto x:adj[i]){
                graph[x].push_back(i);
            }
        }
        
        int i=0;
        
        while(!st.empty()){
            int t=st.top();st.pop();
            
            if(!visited[t]){
                i++;
                dfs1(graph,t,visited);
            }
            
        }
        return i;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends