//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    
    bool Color(int i,int n,int m,bool graph[101][101], vector<int>&NodeColor){
        
        if(i==n) return true;
        
        for(int j=0;j<m;j++){
            
            bool flag=false;
            
            for(int t=0;t<n;t++){
                
                if(graph[i][t] && NodeColor[t]==j){
                    flag=true;
                    break;
                }
            }
            
            if(flag==false){
                
                NodeColor[i]=j;
                if(Color(i+1,n,m,graph,NodeColor)) return true;
                NodeColor[i]=-1;
            }
        }
        
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        if(n==1) return true;
        
        vector<int>CellColor(n,-1);
        
        return Color(0,n,m,graph,CellColor);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends