//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      set<int>s;
      
      for(int i=0;i<N;i++) s.insert(arr[i]);
      
      int prev=arr[0],maxCount=1;
      int count=1;
      for(auto it:s){
          if(it -1 ==prev){
              prev=it;
              count++;
          }
          else{
              maxCount=max(count,maxCount);
              count=1;
              prev=it;
          }
      }
      maxCount=max(count,maxCount);
      return maxCount;
      
      
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends