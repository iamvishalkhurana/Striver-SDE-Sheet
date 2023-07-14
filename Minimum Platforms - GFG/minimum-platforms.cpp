//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    int findPlatform(int arr[], int dep[], int n)
    {
        set<int>newplatforms;
        
        vector<pair<int,int>>trains;
        
        for(int i=0;i<n;i++) trains.push_back({arr[i],dep[i]});
        
        sort(trains.begin(),trains.end());
        
        int platforms=0;
        
        newplatforms.insert(0);
        
        for(int i=1;i<n;i++){
            for(auto it:newplatforms){
                if(trains[it].second < trains[i].first){
                    newplatforms.erase(it);
                }
            }
            newplatforms.insert(i);
            int x=newplatforms.size();
            platforms=max(platforms,x);
        }
        return platforms;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends