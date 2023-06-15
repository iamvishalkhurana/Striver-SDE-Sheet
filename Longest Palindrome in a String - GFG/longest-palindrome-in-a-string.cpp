//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution { 
  public:
    
    string longestPalin (string s) {
        int n=s.size();
        int start=0,len=1;
        int low,hi;
        for(int i=0;i<n;i++){
            low=i-1;hi=i;  //even sized substring
            
            while(low>=0 && hi<n && s[low]==s[hi]){
                
                if(hi-low+1>len){
                    len=hi-low+1;
                    start=low;
                }
                low--;hi++;
            }
            
            low=i-1;hi=i+1;
            while(low>=0 && hi<n && s[low]==s[hi]){
                
                if(hi-low+1>len){
                    len=hi-low+1;
                    start=low;
                }
                low--;hi++;
            }
        }
        return s.substr(start,len);
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends