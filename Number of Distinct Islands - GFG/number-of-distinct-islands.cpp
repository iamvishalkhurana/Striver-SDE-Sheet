//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(vector<vector<int>>& grid,int i,int j,vector<pair<int,int>>&v,pair<int,int>p){
        int n=grid.size();
        int m=grid[0].size();
        int x=i-p.first,y=j-p.second;
        v.push_back({x,y});
        grid[i][j]=0;

        if(i>0 && grid[i-1][j]==1){
            dfs(grid,i-1,j,v,p);
        }
        if(j>0 && grid[i][j-1]==1){
            dfs(grid,i,j-1,v,p);
        }
        if(i<n-1 && grid[i+1][j]==1){
            dfs(grid,i+1,j,v,p);
        }
        if(j<m-1 && grid[i][j+1]==1){
            dfs(grid,i,j+1,v,p);
        }
            
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>>s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){ 
                    vector<pair<int,int>>v;
                    dfs(grid,i,j,v,{i,j});
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends