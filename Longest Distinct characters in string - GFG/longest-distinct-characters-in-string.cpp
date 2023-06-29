//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    map<char,int>mapp;
        int start=0,max_len=0,n=s.length();
        int i=0;
        while(i<n && start<n){
            if(mapp.find(s[i])==mapp.end()){
                mapp[s[i]]++;
                i++;
            }
            else{
                max_len=max(max_len,i-start);
                mapp.erase(s[start]);
                start=start+1;
            }
        }
        max_len=max(max_len,i-start);
        return max_len;
}