//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
       vector<pair<int,int>>adj[n];
       for(int i=0;i<roads.size();i++){
           adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
           adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
       }
       
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>, greater<pair<int, int>>> pq;

       vector<int>dist(n,INT_MAX),ways(n,0);
       pq.push({0,0});
       dist[0]=0;
       ways[0]=1;
       
       int mod=(int)1e9+7;
       
       while(!pq.empty()){
           auto temp=pq.top();pq.pop();
           
           long long curr_dist=temp.first,node=temp.second;
           
           for(auto x:adj[node]){
               long long adjNode=x.first,wt=x.second;
               
               if(wt+curr_dist < dist[adjNode]){
                   dist[adjNode]= wt+curr_dist;
                   pq.push({wt+curr_dist,adjNode}); 
                   ways[adjNode]=ways[node];
                   
                   
               }
               
               else if(wt+curr_dist==dist[adjNode]){
                   ways[adjNode]=(ways[adjNode] + ways[node])%mod;
               }
           }
       }
       
       return (ways[n-1]) % (mod);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends