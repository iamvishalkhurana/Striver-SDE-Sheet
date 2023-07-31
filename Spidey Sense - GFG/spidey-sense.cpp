//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

    public:
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
        queue< pair< pair<int,int>,int > >q;
        vector<vector<int>>visited(M,vector<int>(N,-1));
        
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(matrix[i][j]=='B'){
                    q.push({{i,j},0});
                    visited[i][j]=0;
                }
            }
        }
        
        vector<int>row={0,-1,0,1};
        vector<int>col={-1,0,1,0};
        
        while(!q.empty()){
            
            auto temp=q.front();q.pop();
            
            int dist=temp.second;
            
            int i=temp.first.first,j=temp.first.second;
            
            for(int x=0;x<4;x++){
                
                int r=i+row[x],c=j+col[x];
                
                if(r>=0 && c>=0 && r<M && c<N && matrix[r][c]=='O' && visited[r][c]==-1){
                    visited[r][c]=dist+1;
                    q.push({{r,c},dist+1});
                }
            }
            
        }
        return visited;
        
    } 
};

//{ Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}
// } Driver Code Ends