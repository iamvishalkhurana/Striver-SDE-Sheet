//{ Driver Code Starts
//Initial Template for C++
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
            parent.resize(n+1,0);
            size.resize(n+1,1);
            
            for(int i=0;i<=n;i++) parent[i]=i;
            
        }
        
        int UltimateParent(int i){
            if(parent[i]==i) return i;
            
            return parent[i]=UltimateParent(parent[i]);
        }
        
        void UnionBySize(int i,int j){
            int ui=UltimateParent(i);
            int uj=UltimateParent(j);
            
            if(ui==uj) return;
            
            if(size[ui] < size[uj]){
                parent[ui]=uj;
                size[uj]+=size[ui];
            }
            else{
                parent[uj]=ui;
                size[ui]+=size[uj];
            }
        }
        
        void UnionByRank(int i,int j){
            int ui=UltimateParent(i);
            int uj=UltimateParent(j);
            
            if(ui==uj) return;
            
            if(rank[ui] < rank[uj]){
                parent[ui]=uj;
            }
            else if(rank[ui] > rank[uj]){
                parent[uj]=ui;
            }
            else{
                parent[uj]=ui;
                rank[ui]++;
            }
        }
        
};

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        map<string,int>mapp;
        
        int V=accounts.size();
        
        DisjointSet ds(V);
        
        for(int i=0;i<V;i++){
            for(int j=1;j<accounts[i].size();j++){
                string it=accounts[i][j];
                if(mapp.find(it)==mapp.end()){
                    mapp[it]=i;
                }
                else{
                    ds.UnionBySize(i,mapp[it]);
                }
            }
        }
        vector<string>adj[V];
        for(auto it:mapp){
            int x=it.second;
            int t=ds.UltimateParent(x);
            adj[t].push_back(it.first);
            
        }
        
        vector<vector<string>>ans;
        
        for(int i=0;i<V;i++){
            
            if(adj[i].size()==0) continue;
            
            vector<string>temp;
            
            temp.push_back(accounts[i][0]);
            
            sort(adj[i].begin(),adj[i].end());
            
            temp.insert(temp.begin()+1,adj[i].begin(),adj[i].end());
            
            ans.push_back(temp);
            
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends