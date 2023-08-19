//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        
        for(int i=1;i<n;i++) arr[i]+=arr[i-1];
        
        int st=0;
        
        long long val=0;
        
        for(int i=0;i<n;i++){
            
            if(arr[i]-val < s) continue;
            
            else{
                while( st < i && arr[i]-val > s){
                    
                    st++;
                    val=arr[st-1];
                }
                
                if((arr[i]-val) == s) return {st+1,i+1};
            }
            
        }
        return {-1};
        
       
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends