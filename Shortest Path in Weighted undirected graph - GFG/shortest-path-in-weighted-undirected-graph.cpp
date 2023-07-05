//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<m;i++){ 
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        vector<int>dist(n+1,INT_MAX);
        dist[1]=0;
        vector<int>parent(n+1);
        
        for(int i=1;i<=n;i++) parent[i]=i;
        
        while(!pq.empty()){
            auto temp=pq.top();pq.pop();
            int distance=temp.first,node=temp.second;
            for(auto x:adj[node]){
                if(dist[x.first] > x.second + distance){
                    dist[x.first]=x.second+distance;
                    pq.push({dist[x.first],x.first});
                    parent[x.first]=node;
                }
            }
        }
        vector<int>ans;
        
        do{
            ans.insert(ans.begin(),n);
            n=parent[n];
        }while(parent[n]!=n);
        
        if(n!=1) return {-1};
        ans.insert(ans.begin(),1);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends