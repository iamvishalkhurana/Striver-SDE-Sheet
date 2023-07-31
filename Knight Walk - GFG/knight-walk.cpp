//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n){
	    
	    queue< pair< int,pair<int,int> > >q;
	    vector<vector<int>>visited(n+1,vector<int>(n+1,0));
	    
	    int x=KnightPos[0],y=KnightPos[1];
	    
	    q.push({0,{x,y}});
	    
	    visited[x][y]=1;
	    
	    int del_row[] = {2,2,1,1,-1,-1,-2,-2};
	    int del_col[] = {1,-1,2,-2,2,-2,1,-1};
	    
	    while(!q.empty())
	    {
	        int row = q.front().second.first;
	        int col = q.front().second.second;
	        int steps=q.front().first;
	        q.pop();
	        
	        if(row ==TargetPos[0] && col==TargetPos[1])
	            return steps;
	            
	        for(int k=0;k<8;k++)
	        {
	            int n_row = row + del_row[k];
	            int n_col = col + del_col[k];
	            
	            if(n_row>0 && n_row<=n && n_col>0 && n_col<=n && visited[n_row][n_col]==0)
	            {
	                visited[n_row][n_col]=1;
	                q.push({steps+1,{n_row,n_col}});
	            }
	            

	        }
	    }
	   return -1;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends