//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        int n=wordList.size();
        set<string>s;
        for(int i=0;i<n;i++){
            s.insert(wordList[i]);
        }
        s.insert(startWord);
        queue<pair<string,int>>q;
        q.push({startWord,1});
        s.erase(startWord);
        while(!q.empty()){
            auto temp=q.front();q.pop();
            
            string x=temp.first;
            int steps=temp.second;
            if(x==targetWord) return steps ;
            string t=x;
            for(int i=0;i<x.size();i++){
                x=t;
                for(int j=0;j<26;j++){
                    x[i]=char('a'+j);
                    
                    if(s.find(x)!=s.end()){
                        q.push({x,steps+1});
                        s.erase(x);
                    }
                }
            }
            
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends