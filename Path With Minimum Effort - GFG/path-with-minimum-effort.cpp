//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        vector<int>row={0,1,0,-1};
        vector<int>col={-1,0,1,0};
        
          while(!q.empty()){
            auto temp=q.top();q.pop();
            int curr_dist=temp.first;
            int x=temp.second.first;
            int y=temp.second.second;
            
            for(int i=0;i<4;i++){
                int r=x+row[i],c=y+col[i];
                if(r<n && c<m && c>=0 & r>=0){
                    int curr_max=abs(grid[x][y]-grid[r][c]);
                    
                    int temp_max=max(curr_max,curr_dist);
                    if(temp_max < distance[r][c]){
                        distance[r][c]=temp_max;
                        q.push({distance[r][c],{r,c}});
                    }
                    
                }
            }
        }
        return distance[n-1][m-1]==INT_MAX? 0 : distance[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends