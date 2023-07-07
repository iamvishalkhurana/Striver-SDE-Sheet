//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& f, int src, int dst, int K)  {
        vector<int>fare(n,INT_MAX);
        set<int>final_fares;
        vector<pair<int,int>>adj[n];
        
        for(int i=0;i<f.size();i++) adj[f[i][0]].push_back({f[i][1],f[i][2]});
        fare[src]=0;
        queue<pair<int,pair<int,int>>>pq;
        
        pq.push({0,{src,0}});
        
        while(!pq.empty()){
            
            auto temp=pq.front();pq.pop();
            
            int curr_fare=temp.first,city=temp.second.first,curr_k=temp.second.second;
            
            if(curr_k>K) continue;
            
            for(auto x:adj[city]){
                int wt=x.second,adjNode=x.first;
                if(fare[adjNode]>curr_fare+wt && curr_k <=K){
                    fare[adjNode]=curr_fare+wt;
                    pq.push({fare[adjNode],{adjNode,curr_k+1}});
                }
            }
        }
        
        return fare[dst]==INT_MAX ? -1 : fare[dst];
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends