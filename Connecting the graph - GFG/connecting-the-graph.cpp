//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet {
    vector<int> rank, parent, size; 
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
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        
        if(edge.size()<n-1) return -1;
        DisjointSet ds(n);
        for(int i=0;i<edge.size();i++){
            ds.unionBySize(edge[i][0],edge[i][1]);
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(ds.findU_parent(i)==i) comp++;
        }
        return comp-1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends