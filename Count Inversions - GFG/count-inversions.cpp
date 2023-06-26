//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long countAndMerge(long long arr[],long long l,long long m,long long h){
        long long n1=m-l+1,n2=h-m;
        vector<long long>left(n1),right(n2);
        
        for(long long i=0;i<n1;i++) left[i]=arr[i+l];
        
        for(long long i=0;i<n2;i++) right[i]=arr[m+i+1];
        
        long long cnt=0,i=0,j=0,k=l;
        
        while(i<n1 && j<n2){
            if(left[i] > right[j]){
                arr[k++]=right[j++];
                cnt+=(n1-i);
            }
            else {
                arr[k++]=left[i++];
            }
        }
        
        while(i<n1) arr[k++]=left[i++];
        
        while(j<n2) arr[k++]=right[j++];
        
        return cnt;
    }
    
    long long countInversion(long long arr[],long long l,long long h){
        long long cnt=0;
        if(h>l){
            long long m=l+(h-l)/2;
            cnt+=countInversion(arr,l,m);
            cnt+=countInversion(arr,m+1,h);
            cnt+=countAndMerge(arr,l,m,h);
        }
        return cnt;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return countInversion(arr,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends