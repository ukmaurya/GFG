//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    bool isValid(int x , int y)
    {
        return !(x < 0 || x > 3 || y < 0 || y > 2 || (x == 3 && (y == 0 || y == 2)));
    }
    long long solveMem(vector<vector<int>>& keypad, int n, int i, int j ,
        vector<vector<vector<long long>>>&dp)
    {
        if(n == 1) return 1;
        
        if(dp[n][i][j] != -1)
        {
            return dp[n][i][j];
        }
        
        int dr[] = {-1 , 0 , 1 , 0};
        int dc[] = {0 , 1 , 0 , -1};
        
        long long count = 0;
        
        for(int k = 0 ; k < 4 ; k++)
        {
            int ni = i + dr[k];
            int nj = j + dc[k];
            
            if(isValid(ni, nj)) 
            {
                count += solveMem(keypad, n - 1, ni, nj , dp);
            }
        }
        
        count += solveMem(keypad, n - 1, i, j , dp);
        
        return dp[n][i][j] = count;
    }

  public:
    long long getCount(int n) {
        // Your code goes here
         vector<vector<int>> keypad = 
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {-1, 0, -1} 
        };
        
        long long totalCount = 0;
        vector<vector<vector<long long>>>dp(n + 1, vector<vector<long long>>(4, vector<long long>(3, -1)));
        for(int i = 0 ; i < 4 ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                if(keypad[i][j] != -1)
                {
                    totalCount += solveMem(keypad , n , i , j , dp);
                }
            }
        }
        
        return totalCount;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends