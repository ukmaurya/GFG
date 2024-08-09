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
    public: 
    vector<int> size , parent;
    
    disjointset(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    
    int findulp(int u){
         if(parent[u]==u){
             return u;
         }
         
       return parent[u] = findulp(parent[u]);
    }
    
    void unionSize(int u , int v){
        
        //litle change
    
        
       int x = findulp(u);
        int y = findulp(v);
        if(x<y){
            parent[y]=x;  // connect to smaller slot =>smaller slot will be available
        }
        else{
            parent[x]=y;
        }
     
        /*if(x!=y){
           if(size[x] <= size[y]){
               parent[x]=parent[y];
               size[y] += size[x];
           }
           else{
               parent[y]=parent[x];
               size[x] += size[y];
           }
        } */
        return; 
       
       
    }
};

class Solution 
{
    bool static comp(Job j1 , Job j2){
        return j1.profit > j2.profit;
        
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        /*    sort(arr, arr+n,comp);   taking o(n^2) time in worst case
            int profit = 0;
            int count= 0;
            vector<int> sch(n,-1); // initially no jobs are scheduled
            for(int i=0;i<n;i++){
                int j = arr[i].dead-1;// 0 based indexing
                while(j>=0 && sch[j] != -1){
                    j--;
                }
                if(j>=0){
                    profit += arr[i].profit;
                    count++;
                    sch[j]=i;
                }
               
            }
            
            
            return {count , profit}; */
            
          // we will use disjointset o(nlogn) time
          
          sort(arr, arr+n,comp);
          
        
          int maxDeadline = 0;
          for(int i=0;i<n;i++){
             maxDeadline = max(maxDeadline , arr[i].dead);
          }
          
          disjointset ds(maxDeadline);
          int count=0;
          int prof =0;
          for(int i=0;i<n;i++){
              int slot = ds.findulp(arr[i].dead);
              if(slot!=0){
                  count++;
                  prof+=arr[i].profit;
                  ds.unionSize(slot, slot-1);
              }
          }
            
          return {count , prof};   
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