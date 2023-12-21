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
    string postToPre(string post) {
        int n=post.size();
        stack<string>st;
        
        for(char it:post){
            if(isOperator(it)){
                string op1=st.top();st.pop();
                string op2=st.top();st.pop();
                
                string ans="";
                ans+=it+op2+op1;
                st.push(ans);
                
            }
            else{
                st.push(string(1,it));
            }
        }
        
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
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
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends