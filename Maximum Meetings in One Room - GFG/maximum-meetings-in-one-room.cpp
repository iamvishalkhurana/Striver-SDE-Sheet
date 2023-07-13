//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    static bool comp(pair<int,pair<int,int>>a,pair<int,pair<int,int>>b){
        return a.second.second < b.second.second;
    }
    
    vector<int> maxMeetings(int N,vector<int> &start,vector<int> &end){
       vector<pair<int,pair<int,int>>>v;
       
       for(int i=0;i<N;i++){
           v.push_back({i+1,{start[i],end[i]}});
       }
       
       sort(v.begin(),v.end(),comp);
       
       vector<int>meets;
       
       meets.push_back(v[0].first);
       
       int endtime=v[0].second.second;
       
       for(int i=1;i<N;i++){
           if(v[i].second.first>endtime){
               meets.push_back(v[i].first);
               endtime=v[i].second.second;
           }
       }
       sort(meets.begin(),meets.end());
       return meets;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends