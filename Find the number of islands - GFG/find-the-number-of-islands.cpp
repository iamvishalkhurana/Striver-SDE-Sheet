//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    void bfs(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>&visited){
        visited[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        
        int n=grid.size(),m=grid[0].size();
        
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            
            int r=temp.first,c=temp.second;
            
            for(int x=-1;x<=1;x++){
                for(int y=-1;y<=1;y++){
                    
                    int row=r+x,col=c+y;
                    
                    if( row >=0 && row <n && col >=0 && col < m && grid[row][col]=='1' && visited[row][col]==0){
                       visited[row][col]=1;
                       q.push({row,col});
                        
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        int islands=0;
        
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j] ){
                    bfs(grid,i,j,visited);
                    islands++;
                    }
                }
        }
        return islands;
            
        }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends