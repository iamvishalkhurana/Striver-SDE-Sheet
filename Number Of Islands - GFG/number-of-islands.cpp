//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        int k=operators.size();
        int islands=0;
        vector<int>numIslands;
        vector<vector<bool>>mat(n,vector<bool>(m,0));
        vector<int>row={0,1,0,-1};
        vector<int>col={-1,0,1,0};
        
        for(int i=0;i<k;i++){
            int x=operators[i][0],y=operators[i][1];
            
            if(mat[x][y]) numIslands.push_back(islands);
            
            else{
                mat[x][y]=1;
                islands++;
                
                for(int t=0;t<4;t++){
                    
                    int r=row[t]+x,c=col[t]+y;
                    
                    if(r<n && c<m && c>=0 && r>=0 && mat[r][c]==1){
                        
                        int u=r*m+c,v=x*m+y;
                        
                        int up=ds.findU_parent(u),vp=ds.findU_parent(v);
                        
                        if(up==vp) continue;
                        
                        else{
                            ds.unionBySize(u,v);
                            islands--;
                        }
                        
                    }
                }
                numIslands.push_back(islands);
            }
        }
        return numIslands;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends