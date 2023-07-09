//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    private:
        vector<int>rank,size,parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            size.resize(n+1,1);
            parent.resize(n+1);
            
            for(int i=0;i<=n;i++) parent[i]=i;
            
        }
        
        int findU_parent(int n){
            if(parent[n]==n){
                return n;
            }
            return parent[n]=findU_parent(parent[n]);
        }
        
        void unionByRank(int i,int j){
            int ult_i=findU_parent(i);
            int ult_j=findU_parent(j);
            
            if(ult_i == ult_j) return; 
            
            if(rank[ult_i] < rank[ult_j]){
                parent[ult_i]=ult_j;
            }
            else if(rank[ult_i]>rank[ult_j]){
                parent[ult_j]=ult_i;
            }
            
            else{
                parent[ult_j]=ult_i;
                rank[ult_i]++;
            }
            
        }
        
        void unionBySize(int i,int j){
            int ult_i=findU_parent(i);
            int ult_j=findU_parent(j);
            
            if(ult_i == ult_j) return;
            
            if(size[ult_i]<size[ult_j]){
                parent[ult_i]=ult_j;
                size[ult_j]+=size[ult_i];
            }
            else{
                parent[ult_j]=ult_i;
                size[ult_i]+=size[ult_j];
            }
        }
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                edges.push_back({j[1],{i,j[0]}});
            }
        }
        
        DisjointSet ds(V);
        
        int MST_WT=0;
        
        sort(edges.begin(),edges.end());
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i].second.first,v=edges[i].second.second;
            int wt=edges[i].first;
            if(ds.findU_parent(u)!=ds.findU_parent(v)){
                MST_WT+=wt;
                ds.unionBySize(u,v);
            }
        }
        return MST_WT;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends