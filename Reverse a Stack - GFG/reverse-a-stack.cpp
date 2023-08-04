//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void reverse_stack(stack<int>&st,vector<int>&x){
        if(st.empty()){
            for(int i=0;i<x.size();i++){
                st.push(x[i]);
            }
            return;
        }
        
        int temp=st.top();st.pop();
        x.push_back(temp);
        reverse_stack(st,x);
    }
    void Reverse(stack<int> &St){
        vector<int>x;
        reverse_stack(St,x);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends