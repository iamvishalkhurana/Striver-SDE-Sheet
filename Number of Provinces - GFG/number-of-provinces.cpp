//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs (vector<vector<int>>& adj,int i,vector<bool>&visited,int V){
        if(visited[i]) return;
        
        visited[i]=1;
        
        for(int j=0;j<V;j++){
            if(adj[i][j] && !visited[j]){
                dfs(adj,j,visited,V);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        int provinces=0;
        vector<bool>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                provinces++;
                dfs(adj,i,visited,V);
            }
        }
        return provinces;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends