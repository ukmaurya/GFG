//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends

class Node{
    Node * links[26];
    // flag is not required as we just want to count the substring 
    public: 
    bool containsKey(char ch){
        return links[ch-'a']!= NULL;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    void put(char ch , Node *node){
        links[ch-'a'] = node;
    }
}; 


/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    //Your code here
    
    // trie class is not needed 
    Node *root = new Node();
    int cnt =0;
    int n = s.size();
    for(int i=0;i<s.size();i++){ // iterate on each substring
      Node* node = root;
        for(int j=i;j<n;j++){
             if(!node->containsKey(s[j])){
                 cnt++;
                 node->put(s[j] , new Node());
             }
             node = node->get(s[j]); // moves to current char reference 
        }
    }
    return cnt+1; // +1 for empty substring 
}