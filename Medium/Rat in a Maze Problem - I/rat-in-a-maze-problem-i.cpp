//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    void solve(int i, int j , string &str , vector<vector<int>>&m,vector<string>&ans , vector<vector<int>>&vis){
        int n = m.size();
        if(i==n-1 && j==n-1){
            ans.push_back(str);
            return ;
        }
        int dx[] = {0, 1, 0, -1}; // Right, Down, Left, Up
        int dy[] = {1, 0, -1, 0};
        char directions[] = {'R', 'D', 'L', 'U'};
        for(int k=0;k<4;k++){
            int row = i+dx[k];
            int col = j+dy[k];
            if(row>=0 && row<n && col>=0 && col<n &&!vis[row][col]  && m[row][col]==1){
                vis[row][col]=1;
               
                if(row==i+1 && col == j)
                  str.push_back('D');
                else if(row==i-1 && col == j)
                  str = str+'U';  
                else if(row==i && col == j+1)
                  str = str+'R';  
                else if(row==i && col == j-1)
                  str = str+'L';    
               // str.push_back(directions[k]);  
                solve(row,col,str,m,ans,vis);
                vis[row][col]=0;
                str.pop_back();
            }
        }
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
          vector<string> ans;
         if (m[0][0] == 0 || m[n - 1][n - 1] == 0) // Check if start or end is blocked
            return {"-1"};
          vector<vector<int>>vis(n,vector<int>(n,0));    
          vis[0][0]=1;
          string str="";
          solve(0,0,str,m,ans,vis);
          if(ans.empty())
            return {"-1"};
          
          return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends