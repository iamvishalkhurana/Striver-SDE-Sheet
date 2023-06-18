//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        
        deque<int>dq;
        
        for(int i=1;i<=N;i++) dq.push_front(i);
        
        while(dq.size()!=1){
            
            for(int i=0;i<K;i++){
                if(dq.size()==1) break;
                dq.pop_back();
            } 
            
            for(int i=0;i<K;i++) {
                if(dq.size()==1) break;
                dq.pop_front();
            }
        }
        return dq.front();
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends