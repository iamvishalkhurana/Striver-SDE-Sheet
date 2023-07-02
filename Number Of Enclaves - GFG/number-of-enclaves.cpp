//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        void dfs(vector<vector<int>>&mat,int i,int j,vector<vector<bool>>&visited){
        visited[i][j]=1;
        
        int n=mat.size(),m=mat[0].size();
        
        vector<int>row={0,1,0,-1};
        vector<int>col={-1,0,1,0};
        
        for(int x=0;x<4;x++){
            int r=row[x]+i,c=col[x]+j;
            if(r>=0 && r<n && c>=0 && c<m && mat[r][c]==1 && !visited[r][c]){
                dfs(mat,r,c,visited);
            }
        }
        
        }
        void boundary(vector<vector<int>>&mat,vector<vector<bool>>&visited){
            
            int n=mat.size(),m=mat[0].size();
            
            for(int i=0;i<m;i++){
                if(mat[0][i]==1 && !visited[0][i]){
                    dfs(mat,0,i,visited);
                }
            }
            for(int i=1;i<n;i++){
                if(mat[i][m-1]==1 && !visited[i][m-1]){
                    dfs(mat,i,m-1,visited);
                }
            }
            for(int i=m-2;i>=0;i--){
                if(mat[n-1][i]==1 && !visited[n-1][i]){
                    dfs(mat,n-1,i,visited);
                }
            }
            for(int i=n-2 ;i>=1;i--){
                if(mat[i][0]==1 && !visited[i][0]){
                    dfs(mat,i,0,visited);
                }
            }
        }
  public:
    int numberOfEnclaves(vector<vector<int>>&mat) {
        int n=mat.size(),m=mat[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        
        boundary(mat,visited);
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && !visited[i][j]){
                    count++;
                }
            }
        }
        return count;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends