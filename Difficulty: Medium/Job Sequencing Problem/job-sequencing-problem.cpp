//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class disjointset{
      vector<int> parent , size;
      public: 
      disjointset(int n ){
          parent.resize(n+1);
          for(int i=0;i<=n;i++){
              parent[i]=i;
          }
          size.resize(n+1);
          
      }
      
      int ultiPar(int node){
          if(parent[node]==node){
              return node;
          }
          return parent[node] = ultiPar(parent[node]);
      }
      
      void unionSize(int u , int v){
          parent[v]=u;
      }
};


class Solution 
{
    bool static comp(Job arr1 , Job arr2){
        return arr1.profit > arr2.profit;
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
          sort(arr, arr+n , comp);
          int maxi =0;
          for(int i=0;i<n;i++){
              maxi = max(maxi , arr[i].dead);
          }
          disjointset ds(maxi);
          
          int ans =0;
          int count=0;
          for(int i=0;i<n;i++){
              int deadline = arr[i].dead;
              int faiyda = arr[i].profit;
              int par = ds.ultiPar(deadline);
              if(par>0){
                  ds.unionSize(par-1,par);
                  ans+= faiyda;
                  count++;
              }
          }
          
          return {count ,ans};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends