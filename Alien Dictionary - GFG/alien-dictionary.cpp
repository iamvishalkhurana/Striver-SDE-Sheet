//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void topological(vector<int>adj[],int i,vector<bool>&visited,vector<int>&topo){
	    visited[i]=1;
	    for(auto x:adj[i]){
	        if(!visited[x]){
	            topological(adj,x,visited,topo);
	        }
	    }
	    topo.push_back(i);
	}

    string findOrder(string dict[], int N, int K) {
        map<char,int>alpha;
        for(int i=0;i<K;i++){
            alpha[(char) 97+i]=i;
        }
        
        vector<int>adj[K];
        
        for(int i=0;i<N-1;i++){
            string x=dict[i],y=dict[i+1];
            int j=0;
            while(x[j]==y[j]){
                j++;
            }
            adj[alpha[x[j]]].push_back(alpha[y[j]]);
        }
        vector<bool>visited(K,0);
        vector<int>topo;
        for(int i=0;i<K;i++){
            if(!visited[i]){
                topological(adj,i,visited,topo);
            }
        }
        
        reverse(topo.begin(),topo.end());
        string ans="";
        for(int i=0;i<topo.size();i++){
            ans.append(1,(char) 97+topo[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends