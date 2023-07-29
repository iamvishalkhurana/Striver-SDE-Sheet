//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int PathFinder(int i,int j,int N,vector<vector<int>> &matrix,vector<vector<int>>&dp){
        if(i==N-1) return matrix[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        int down=0,rightD=0,leftD=0;
        
        if(i+1<N) down=PathFinder(i+1,j,N,matrix,dp);
        if(i+1<N && j+1 < N) rightD=PathFinder(i+1,j+1,N,matrix,dp);
        if(i+1<N && j-1 >=0 ) leftD=PathFinder(i+1,j-1,N,matrix,dp);
        
        return dp[i][j]= matrix[i][j]+max(down,max(rightD,leftD));
        
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int maxi=INT_MIN;
        vector<vector<int>>dp(N,vector<int>(N,-1));
        for(int i=0;i<N;i++){
            int temp=PathFinder(0,i,N,Matrix,dp);
            maxi=max(maxi,temp);
        }
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends