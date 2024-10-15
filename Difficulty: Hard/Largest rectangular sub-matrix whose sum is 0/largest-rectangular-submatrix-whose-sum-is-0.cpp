//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    // Helper function to find the longest subarray with zero sum
    pair<int, int> longestSubArraySum(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        mp[0] = -1; // Handle subarrays starting from index 0
        int preSum = 0;
        int maxLen = 0;
        int start = -1, end = -1;

        for (int i = 0; i < n; i++) {
            preSum += arr[i];

            if (mp.find(preSum) != mp.end()) {
                int length = i - mp[preSum];
                if (length > maxLen) {
                    maxLen = length;
                    start = mp[preSum] + 1; // Start of subarray
                    end = i;                // End of subarray
                }
            } else {
                mp[preSum] = i;
            }
        }
        return {start, end}; // Return starting and ending indices of subarray
    }

public:
    vector<vector<int>> sumZeroMatrix(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int startRow = -1, startCol = -1, endRow = -1, endCol = -1;
        int maxArea = 0;
        int minStartCol = m + 1; // Initialize to ensure the smallest column is prioritized
        int minWidth = m + 1;    // Initialize to find the smallest width

        for (int i = 0; i < n; i++) { // Iterate over all rows
            vector<int> arr(m, 0);    // Create an array to store column sums

            for (int s = i; s < n; s++) { // Iterate from row i to row s
                for (int j = 0; j < m; j++) {
                    arr[j] += a[s][j]; // Update column sums for submatrix
                }

                // Find the longest subarray with sum zero in 'arr'
                pair<int, int> p = longestSubArraySum(arr);
                if (p.first != -1 && p.second != -1) { // Valid subarray found
                    int width = p.second - p.first + 1; // Width of submatrix
                    int height = s - i + 1;             // Height of submatrix
                    int area = width * height;          // Area of submatrix

                    // Apply constraints to select the best submatrix
                    if (area > maxArea || 
                        (area == maxArea && p.first < minStartCol) || 
                        (area == maxArea && p.first == minStartCol && width < minWidth)) {

                        maxArea = area;
                        minStartCol = p.first;
                        minWidth = width;
                        startRow = i;
                        startCol = p.first;
                        endRow = s;
                        endCol = p.second;
                    }
                }
            }
        }

        // Return an empty matrix if no valid submatrix found
        vector<vector<int>> ans;
        if (startRow == -1 || startCol == -1 || endRow == -1 || endCol == -1)
            return ans;

        // Extract the submatrix from startRow, startCol to endRow, endCol
        for (int i = startRow; i <= endRow; i++) {
            vector<int> temp;
            for (int j = startCol; j <= endCol; j++) {
                temp.push_back(a[i][j]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};



//{ Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends