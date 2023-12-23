//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isOperator(char x){
        return (x=='+' || x=='-' || x=='*' || x=='/');
    }
    int checkRedundancy(string s) {
        stack<char>st;
        for(char it:s){
            if(isOperator(it) || it=='(') st.push(it);
            
            else if(it==')'){
                int flag=1;
                while(!st.empty() && st.top()!='('){
                    
                    if(isOperator(st.top())) flag=0;
                    
                    st.pop();
                }
                st.pop();
                
                if(flag==1) return 1;
                
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends