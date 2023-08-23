//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
    public:
    
        void computeLPS(string pat,vector<int>&lps){
            int i=1,len=0;
            
            int n=pat.size();
            
            while(i<n){
                if(pat[i]==pat[len]){
                    len++;
                    lps[i]=len;
                    i++;
                }
                else{
                    if(len!=0){
                        len=lps[len-1];
                    }
                    else{
                        lps[i]=0;
                        i++;
                    }
                }
            }
            
        }
        vector <int> search(string pat, string txt)
        {
            int n=txt.size(),m=pat.size();
            
            vector<int>ans;
            
            vector<int>lps(n,0);
            computeLPS(pat,lps);
            
            int i=0,j=0;
            
            while((n-i)>=(m-j)){
                if(txt[i]==pat[j]){
                    i++;j++;
                    
                    if(j==m){
                        ans.push_back(i-pat.size()+1);
                        j=lps[j-1];
                    }
                }
                else{
                    if(j!=0){
                        j=lps[j-1];
                    }
                    else i++;
                }
                
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
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends