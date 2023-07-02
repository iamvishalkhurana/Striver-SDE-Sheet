//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void dfs(vector<vector<char>> mat,int i,int j,vector<vector<bool>>&visited){
        visited[i][j]=1;
        
        int n=mat.size(),m=mat[0].size();
        
        vector<int>row={0,1,0,-1};
        vector<int>col={-1,0,1,0};
        
        for(int x=0;x<4;x++){
            int r=row[x]+i,c=col[x]+j;
            if(r>=0 && r<n && c>=0 && c<m && mat[r][c]=='O' && !visited[r][c]){
                dfs(mat,r,c,visited);
            }
        }
        
    }
    void boundary(vector<vector<char>> mat,vector<vector<bool>>&visited){
        
        int n=mat.size(),m=mat[0].size();
        
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O' && !visited[0][i]){
                dfs(mat,0,i,visited);
            }
        }
        for(int i=1;i<n;i++){
            if(mat[i][m-1]=='O' && !visited[i][m-1]){
                dfs(mat,i,m-1,visited);
            }
        }
        for(int i=m-2;i>=0;i--){
            if(mat[n-1][i]=='O' && !visited[n-1][i]){
                dfs(mat,n-1,i,visited);
            }
        }
        for(int i=n-2 ;i>=1;i--){
            if(mat[i][0]=='O' && !visited[i][0]){
                dfs(mat,i,0,visited);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        
        boundary(mat,visited);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && !visited[i][j]){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends