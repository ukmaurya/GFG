//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
    private:
    int solve(vector<vector<int>>&matrix , int mid){
        // use the property that every row is sorted 
        int r = matrix.size();
        int c = matrix[0].size();
        int count=0;
        for(int i=0;i<r;i++){
            count+= upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
        }
        return count;
    }
public:
    int median(vector<vector<int>> &matrix, int R, int C){
           // we know from analysis that first element which have number <= n/2 elements will be the median
           
           int start = 1;
           int end = 2000;// since max element that can be in matrix;
           int ans =-1;
           int n = R*C; // number of elements in the matrix 
           while(start<= end){
               int mid = start+(end-start)/2;
               int count = solve(matrix , mid); // it will calculate numbers of numbers which is less than mid
         
                if(count > n/2){
                    ans = mid;
                    end= mid-1;
                }
                else{
                    start = mid+1;
                }
           }
          return ans;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends