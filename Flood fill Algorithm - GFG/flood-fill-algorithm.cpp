//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor,int prev){
        image[sr][sc]=newColor;
        
        int n=image.size(),m=image[0].size();
        
        if(sr-1>=0 && image[sr-1][sc]==prev && image[sr-1][sc]!=newColor){
            dfs(image,sr-1,sc,newColor,prev);
        }
        if(sc-1>=0 && image[sr][sc-1]==prev && image[sr][sc-1]!=newColor){
            dfs(image,sr,sc-1,newColor,prev);
        }
        if(sc<m-1 && image[sr][sc+1]==prev && image[sr][sc+1]!=newColor){
            dfs(image,sr,sc+1,newColor,prev);
        }
        if(sr<n-1 && image[sr+1][sc]==prev && image[sr+1][sc]!=newColor){
            dfs(image,sr+1,sc,newColor,prev);
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int n=image.size(),m=image[0].size();
        
        int prev=image[sr][sc];
        
        dfs(image,sr,sc,newColor,prev);
        
        return image;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends