//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,0});
        
        vector<bool>visited(V,0);
        
        int sum=0;
        
        
        while(!pq.empty()){
            auto temp=pq.top();pq.pop();
            int edge_wt=temp.first,node=temp.second;
            
            if(visited[node]) continue;
            
            sum+=edge_wt;
            
            visited[node]=1;
            
            
            for(auto x:adj[node]){
                int adjNode=x[0],wt=x[1];
                if(!visited[adjNode]){
                    pq.push({wt,adjNode});
                }
            }
        }
        return sum;
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