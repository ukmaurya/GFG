//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    
   

    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	     int mv[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}}; // movements 
	     int ax = KnightPos[0];
	     int ay = KnightPos[1];
	     int dx = TargetPos[0];
	     int dy = TargetPos[1];
	     int n = N;
	     vector<vector<int>>vis(n+1 , vector<int>(n+1 , 0));
	     vis[ax][ay]=1;
	     queue<pair<int, pair<int,int>>>q; // len , row , col
	     
	     q.push({0,{ax,ay}});
	     int ans = -1;
	     bool flag = false;
	     while(!q.empty()){
	         auto it = q.front();
	         int len = it.first;
	         int r = it.second.first;
	         int c = it.second.second;
	         q.pop();
	         if(r==dx && c==dy){
	            return len;
	             
	         }
	         for(int k=0;k<8;k++){
	             int row = r + mv[k][0];
	             int col = c + mv[k][1];
	             if(row>=1&&row<=n&&col>=1&&col<=n&&vis[row][col]==0){
	                 vis[row][col]=1;
	                 q.push({len+1 , {row , col }});
	             }
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
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends