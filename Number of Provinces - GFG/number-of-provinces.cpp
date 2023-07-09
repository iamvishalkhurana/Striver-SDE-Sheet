//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DisjointSet{
    private:
        vector<int>rank,size,parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            size.resize(n+1,1);
            parent.resize(n+1);
            
            for(int i=0;i<=n;i++) parent[i]=i;
            
        }
        
        int findU_parent(int n){
            if(parent[n]==n){
                return n;
            }
            return parent[n]=findU_parent(parent[n]);
        }
        
        void unionByRank(int i,int j){
            int ult_i=findU_parent(i);
            int ult_j=findU_parent(j);
            
            if(ult_i == ult_j) return; 
            
            if(rank[ult_i] < rank[ult_j]){
                parent[ult_i]=ult_j;
            }
            else if(rank[ult_i]>rank[ult_j]){
                parent[ult_j]=ult_i;
            }
            
            else{
                parent[ult_j]=ult_i;
                rank[ult_i]++;
            }
            
        }
        
        void unionBySize(int i,int j){
            int ult_i=findU_parent(i);
            int ult_j=findU_parent(j);
            
            if(ult_i == ult_j) return;
            
            if(size[ult_i]<size[ult_j]){
                parent[ult_i]=ult_j;
                size[ult_j]+=size[ult_i];
            }
            else{
                parent[ult_j]=ult_i;
                size[ult_i]+=size[ult_j];
            }
        }
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1){
                    ds.unionBySize(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<V;i++){
            if(ds.findU_parent(i)==i) cnt++;
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends