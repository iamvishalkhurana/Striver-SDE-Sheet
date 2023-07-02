//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	
	{
	    int n=grid.size(),m=grid[0].size();
	    
	    vector<vector<int>>ans(n,vector<int>(m,m*n));
	    
	    vector<int>r={0,1,0,-1};
	    vector<int>c={-1,0,1,0};
	    
	    queue<pair<int,int>>q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                ans[i][j]=0;
	                q.push({i,j});
	            }
	        }
	    }
	    int it=0;
	    while(!q.empty()){
	        int no=q.size();
	        it++;
	        for(int i=0;i<no;i++){
	            auto temp=q.front();q.pop();
	            int row=temp.first,col=temp.second;
	            
	            for(int j=0;j<4;j++){
	                int x=r[j]+row,y=c[j]+col;
	                
	                if(x>=0 && y>=0 && y<m && x<n && grid[x][y]==0){
	                    ans[x][y]=it;
	                    grid[x][y]=1;
	                    q.push({x,y});
	                }
	                
	                
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends