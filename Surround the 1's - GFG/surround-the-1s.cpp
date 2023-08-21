//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    
    int Count(vector<vector<int> >& matrix) {
        vector<int>row={0,-1,-1,-1,0,1,1,1};
        vector<int>col={-1,-1,0,1,1,1,0,-1};
        
        int n=matrix.size(),m=matrix[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(matrix[i][j]==1){
                    int curr=0;
                
                    for(int k=0;k<8;k++){
                        int r=i+row[k],c=j+col[k];
                        
                        if(r>=0 && c>=0 && r<n && c<m && matrix[r][c]==0) curr++;
                    }
                    if(curr%2==0 && curr!=0) count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends