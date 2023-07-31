//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void traversal(vector<vector<int>>m,int i,int j,int n,vector<string>&ans,string s,vector<vector<int>>&path){
        
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        
        vector<int>row={0,-1,0,1};
        vector<int>col={-1,0,1,0};
        
        for(int x=0;x<4;x++){
            
            int r=i+row[x],c=j+col[x];
            
            if(r >=0 && c >=0 && c < n && r < n && m[r][c]==1 && path[r][c]==0){
                path[r][c]=1;
                string sub="";
                
                if(x==0) sub="L";
                else if(x==1) sub="U";
                else if(x==2) sub="R";
                else sub="D";
                
                traversal(m,r,c,n,ans,s+sub,path);
                
                path[r][c]=0;
            }
        }
       
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        if(m[0][0]==0) return {"-1"};
        
        vector<string>ans;
        
        vector<vector<int>>path(n,vector<int>(n,0));
        path[0][0]=1;
        traversal(m,0,0,n,ans,"",path);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends