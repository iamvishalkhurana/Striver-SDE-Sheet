//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(vector<int>adj[],int i,vector<bool>&visited,vector<bool>&topo){
        visited[i]=1;
        topo[i]=1;
        for(int x:adj[i]){
            if(!visited[x]){
                if(dfs(adj,x,visited,topo)==true) return true;
            }
            else if(topo[x]) return true;
        }
        topo[i]=0;
        return false;
        
    }
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    vector<int>adj[N];
	    int x=pre.size();
	    for(int i=0;i<x;i++){
	        adj[pre[i].second].push_back(pre[i].first);
	    }
	    
	    vector<bool>path(N,0);
	    vector<bool>visited(N,0);
	    
	    for(int i=0;i<N;i++){
	        if(!visited[i]){
	            if(dfs(adj,i,visited,path)==true) return false;
	        }
	    }
	    
	    return true;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends