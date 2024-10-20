//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
    int solve(int i , int prev , struct val p[] , int n,vector<vector<int>> &dp){
        if(i==n){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int take =0;
        if(prev==-1 || p[i].first > p[prev].second){
            take = 1+solve(i+1 , i ,p,n,dp);
        }
        int ntake = solve(i+1 , prev , p , n,dp);
        return dp[i][prev+1] = max(take , ntake);
    }
    bool static comp(struct val p1 , struct val p2){
        // if(p1.first==p2.first)
          return p1.second<p2.second;
    }
public:
    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n){
        //Your code here
        // sort(p,p+n, comp);
        // vector<vector<int>> dp(n+2 , vector<int>(n+2,-1));
        // return solve(0,-1 ,p , n,dp);
        
       int count=1;
       sort(p, p + n, comp);
        int s=p[0].first;
        int e=p[0].second;
        for(int i=1; i<n; i++){
            if(p[i].first>e){
                s=p[i].first;
                e=p[i].second;
                count++;
            }
        }
        
        return count;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends