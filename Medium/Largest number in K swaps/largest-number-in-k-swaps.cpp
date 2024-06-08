//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    private:
    void solve(int index, string &s , int k , string &res ){ // take string by reference since we are using backracking not recursion 
          int n = s.size();
          // base case
          if(k==0 || index==n){
              return ;
          }
          
          char  lar = *max_element(s.begin()+index , s.end());
          for(int i = index+1;i< s.size() ; i++){ // from index+1 since no need to swap from itself
               if(s[i]==lar && s[index]<lar){
                   swap(s[i] , s[index]);
                   if(s.compare(res)>0){ // compare with new string formed since atmost k swap allowed
                       res = s;          // and largest string can accur in any level of any branch 
                   }
                   solve(index+1,s,k-1,res);
                   swap(s[i],s[index]); // revert the changes ie backtrack
               }
              
          }
          // if no choices of match the condition then no branch will be taken 
          solve(index+1,s,k,res); // to make horizontal drifting ,workout on ex 721
        
    }
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
         // using backtracking method , since we have to check every combination 
         // greedy fails if two char of string are same
         string res = str;
         solve(0,str,k,res);
         return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends