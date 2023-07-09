//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet {
public: 
    vector<int> rank, parent, size;
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
    int MaxConnection(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>row={0,1,0,-1};
        vector<int>col={-1,0,1,0};
        
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    for(int t=0;t<4;t++){
                        int r=row[t]+i,c=col[t]+j;
                        if(r>=0 && c>=0 && c<n && r<n && grid[r][c]==1){
                            int u=r*n+c,v=i*n+j;
                            ds.unionBySize(u,v);
                        }
                    }
                }
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int curr=0;
                if(grid[i][j]==0){
                    curr++;
                    set<int>s;
                    for(int t=0;t<4;t++){
                        int r=row[t]+i,c=col[t]+j;
                        if(r>=0 && c>=0 && c<n && r<n && grid[r][c]==1){
                            int u=r*n+c;
                            int up=ds.findU_parent(u);
                            s.insert(up);
                        }
                    }
                    for(auto x:s){
                        curr+=ds.size[x];
                    }
                    
                }
                maxi=max(maxi,curr);
            }
            
        }
        return maxi==0 ? n*n : maxi;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends