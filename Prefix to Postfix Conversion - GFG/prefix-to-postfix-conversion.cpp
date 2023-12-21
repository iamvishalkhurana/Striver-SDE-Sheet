//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isOperator(char x){
        if(x=='+' || x=='-' || x=='*' || x=='/') return true;
        
        return false;
        
    }
    string preToPost(string pre) {
        int n=pre.size();
        stack<string>st;
        for(int i=n-1;i>=0;i--){
            if(isOperator(pre[i])){
                string op1=st.top();st.pop();
                string op2=st.top();st.pop();
                
                string ans=op1+op2+pre[i];
                st.push(ans);
            }
            else st.push(string(1,pre[i]));
        }
        
        string ans="";
        while(!st.empty()){
            ans+=st.top();st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends