//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int minLen=1e9,currSum=0;
          int s=0;
          for(int i=0;i<n;i++){
              currSum+=arr[i];
              if(currSum > x){
                  while(currSum > x){
                      currSum-=arr[s];
                      s++;
                  }
                  minLen=min(minLen,i-s+1);
              }
          }
          return minLen==1e9 ? 0 :minLen+1;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends