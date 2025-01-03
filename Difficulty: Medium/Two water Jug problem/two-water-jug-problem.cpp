//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int minSteps(int m, int n, int d)
	{
	       // BFS method , just like multiplcation to get to a number 
    //   if(x+y < target){
    //     return -1;
    //   }
    //     int maxi = x+y;
    //     int poss[] = {-x,+x,-y,+y}; // various possibilities
    //     vector<bool> vis(maxi, false);// to avoid redundant calulation
    //     queue<pair<int,int>> q; // len , number
    //     q.push({0,0});
    //     vis[0]=true;
    //     while(!q.empty()){
    //         int node = q.front().second;
    //         int step = q.front().first;
    //         q.pop();
    //         if(node==target)
    //           return step;
    //         for(int k=0;k<4;k++){
    //             int newNode = node+poss[k];
    //             if(newNode<0 || newNode > x+y ||vis[newNode]==true){
    //               continue;
    //             }
    //             vis[newNode] = true;
    //             q.push({step+1,newNode});
    //         }  
    //     }
    //   return -1;
    
    // above solution is failing 
    //  note :ques says  Determine the minimum no of operations to be performed to 
    // obtain d litres of water in one of the jugs.
     vector<vector<int>> vis(m+1,vector<int>(n+1,0));
	    queue<vector<int>> q;
	    q.push({0,0,0});
	    vis[0][0]=true;
	    while(q.empty()==false){
	       vector<int> v=q.front();
	       int a=v[0];
	       int b=v[1];
	       q.pop();
	       if(v[0]==d||v[1]==d) 
	          return v[2];
	       
	       //empty jugs
	       if(vis[0][b]==false){
	           q.push({0,b,v[2]+1});
	           vis[0][b]=true;
	       }
	       if(vis[a][0]==false){
	           q.push({a,0,v[2]+1});
	           vis[a][0]=true;
	       }
	       
	       //fill jugs if empty
	       if(v[0]==0&&vis[m][b]==false){
	           q.push({m,b,v[2]+1});
	           vis[m][b]=true;
	       }
	       if(v[1]==0&&vis[a][n]==false){
	           q.push({a,n,v[2]+1});
	           vis[a][n]=true;
	       }
	       
	       //pour from a to b
	       if(vis[a-min(a,n-b)][b+min(a,n-b)]==false){
	           q.push({a-min(a,n-b),b+min(a,n-b),v[2]+1});
	           vis[a-min(a,n-b)][b+min(a,n-b)]=true;
	       }
	       //pour from b to a
	       if(vis[a+min(b,m-a)][b-min(b,m-a)]==false){
	           q.push({a+min(b,m-a),b-min(b,m-a),v[2]+1});
	           vis[a+min(b,m-a)][b-min(b,m-a)]=true;
	       }
	       
	       
	        
	    }
	    return -1;

	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends