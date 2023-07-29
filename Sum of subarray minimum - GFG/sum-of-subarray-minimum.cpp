//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int sumSubarrayMins(int N, vector<int> &arr) {
        stack<pair<int,int>>s1,s2;
        int left[N],right[N];
        for(int i=0;i<N;i++){
            int count=0;
            while(!s1.empty() && s1.top().first >= arr[i]){
                count+=s1.top().second+1;
                s1.pop();
                
            }
            s1.push({arr[i],count});
            left[i]=count;
        }
        
        for(int i=N-1;i>=0;i--){
            int count=0;
            while(!s2.empty() && s2.top().first > arr[i]){
                count+=s2.top().second+1;
                s2.pop();
            }
            s2.push({arr[i],count});
            right[i]=count;
        }
        
        long long ans=0;
        for(int i=0;i<N;i++){
            ans+= arr[i]*(left[i]+1)*(right[i]+1);
            ans%=(long long)1e9+7;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends