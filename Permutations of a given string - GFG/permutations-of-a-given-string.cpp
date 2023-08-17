//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    bool next_perm(string &s){
	        int n=s.size();
	        
	        int k=-1;
	        
	        for(int i=n-2;i>=0;i--){
	            
	            if(s[i+1] > s[i]){
	                k=i;
	                break;
	            }
	            
	        }
	        
	        if(k==-1) return false;
	        
	        for(int i=n-1 ; i > k ; i--){
	            
	            if(s[i] > s[k]){
	                
	                swap(s[i],s[k]);
	                
	                break;
	            }
	        }
	        
	        reverse(s.begin()+k+1,s.end());
	        
	        return true;
	        
	    }
		vector<string>find_permutation(string S)
		{
		    sort(S.begin(),S.end());
		    
		    vector<string>v;
		    
		    do{
		        v.push_back(S);
		        
		    }while(next_perm(S));
		    
		    return v;
		    
		    
		    
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends