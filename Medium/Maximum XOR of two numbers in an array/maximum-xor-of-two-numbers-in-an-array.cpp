//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
struct Node{
    Node *links[2];
    
    bool containsKey(int bit){
          return links[bit]!=NULL;
    }
    void put(int bit , Node* node){
        links[bit]= node;
    }
    Node* get(int bit){
        return links[bit];
    }

};
class Trie{
    Node *root;
    public :
    Trie(){
        root = new Node();
    }
    void insert(int num){

        Node* node = root;
        for(int i=31 ;i>=0;i--){
           // int bit = num&(1<<i); // why it is not working ? 
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)){
                 node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num){
        Node *node = root;
        int maxi=0;

        for(int i=31;i>=0;i--){
            //int bit = num&(1<<i);
            int bit = (num>>i)&1;
            int req = 1-bit;
            if(node->containsKey(req)){
                
                maxi = maxi|(1<<i);
                node = node->get(req);
              }
            else{
                 node = node->get(bit);
            }
        }
        return maxi;
    }
};

class Solution
{
    public:
    int max_xor(int arr[] , int n)
    {
        //code here
      
    Trie trie;
    for(int i=0;i<n;i++){
        trie.insert(arr[i]);
    } 
    int maxi = 0;
    for(int i=0;i<n;i++){
        maxi = max(maxi , trie.getMax(arr[i]));
    }
    return maxi;
    }
    
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}



// } Driver Code Ends