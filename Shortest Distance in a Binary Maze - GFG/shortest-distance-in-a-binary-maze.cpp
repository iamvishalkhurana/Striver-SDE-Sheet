//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
        
        queue<pair<int,pair<int,int>>>q;
        int sr=source.first,sc=source.second,dr=destination.first,dc=destination.second;
        distance[sr][sc]=0;
        q.push({0,{sr,sc}});
        vector<int>row={0,1,0,-1};
        vector<int>col={-1,0,1,0};
        while(!q.empty()){
            auto temp=q.front();q.pop();
            int curr_dist=temp.first;
            int x=temp.second.first;
            int y=temp.second.second;
            
            if(x==dr && y==dc) return curr_dist;
            
            for(int i=0;i<4;i++){
                int r=x+row[i],c=y+col[i];
                if(r<n && c<m && c>=0 & r>=0 && grid[r][c]==1 && curr_dist+1<distance[r][c]){
                    distance[r][c]=curr_dist+1;
                    q.push({distance[r][c],{r,c}});
                }
            }
            
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends