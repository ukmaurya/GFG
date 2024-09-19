//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    void solve(int r, int c ,string s ,vector<vector<int>> &mat, vector<vector<int>> &vis ,vector<string> &ans){
       int n = mat.size();
        if(r==n-1&&c==n-1){
            ans.push_back(s);
        }
        vis[r][c]=1;
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        char dir[] ={'R','D','L','U'};
        
        for(int k=0;k<4;k++){
            int row = r+dx[k];
            int col = c+dy[k];
            char d = dir[k];
            if(row>=0 && row<n && col>=0 && col<n &&vis[row][col]==0 && mat[row][col]==1){
               s.push_back(d);
                solve(row,col,s,mat,vis,ans);
                s.pop_back();
            }
        }
        
        vis[r][c]=0;
        return;
        
        
        
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
         int n = mat.size();
          if(mat[0][0]==0 || mat[n-1][n-1]==0){
              return {};
          }
          vector<string> ans;
         
          vector<vector<int>> vis(n,vector<int>(n,0));
          solve(0,0 ,"", mat , vis , ans);
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends