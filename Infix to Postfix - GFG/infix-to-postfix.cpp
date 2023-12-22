//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int precedence(char x){
        switch(x){
            case '^':return 3;
            case '*':
            case '/':return 2;
            case '+':
            case '-': return 1;
        }
        return 0;
    }
    
    string infixToPostfix(string s) {
        int n=s.size();
        stack<char>st;
        string postfix="";
        
        for(int i=0;i<n;i++){
            
            if(precedence(s[i])==0 && s[i]!='(' && s[i]!=')') postfix+=string(1,s[i]);
            
            else{
                if(st.empty() || s[i]=='(' || precedence(st.top())<precedence(s[i])) st.push(s[i]);
                
                else if(s[i]==')'){
                    while(!st.empty() && st.top()!='('){
                        postfix+=st.top();st.pop();
                    }
                    if(!st.empty()) st.pop();
                }
                
                else if(precedence(st.top())==precedence(s[i])){
                    postfix+=st.top();st.pop();
                    st.push(s[i]);
                }
                
                else if(precedence(st.top())>precedence(s[i])){
                    while(!st.empty() && precedence(st.top())>=precedence(s[i])){
                        postfix+=st.top();st.pop();
                    }
                    st.push(s[i]);
                }
                
                
            }
            
        }
        
        while(!st.empty()){
            postfix+=st.top();st.pop();
        }
        
        return postfix;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends