//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node{
    public:
    
        Node*left;
        Node*right;
        int val;
        
        Node(int x){
            val=x;
            left=NULL;
            right=NULL;
        }
};

class cmp{
    public:
        bool operator()(Node* a, Node *b){
	        return a->val > b->val;
	    }
};
class Solution
{
	public:
	    
	    bool isLeaf(Node *root){
	        return !root->left && !root->right;
	    }
	    
	    void preorder(Node* root,vector<string>&v,string temp){
	        
	        if(isLeaf(root)){
	            v.push_back(temp);
	            return;
	        }
	        
	        preorder(root->left,v,temp+'0');
	        
	        preorder(root->right,v,temp+'1');
	        
	        
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*,vector<Node*>,cmp>pq;
		    
		    for(int i=0;i<N;i++){
		        Node *temp=new Node(f[i]);
		        pq.push(temp);
		    }
		    
		    while(pq.size() > 1){
		        Node*left=pq.top();pq.pop();
		        
		        Node*right=pq.top();pq.pop();
		        
		        Node* newNode=new Node(left->val + right->val);
		        
		        newNode->left=left;
		        
		        newNode->right=right;
		        
		        pq.push(newNode);
		        
		    }
		    vector<string>ans;
		    string temp="";
		    
		    preorder(pq.top(),ans,temp);
		    
		    return ans;
		    
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends