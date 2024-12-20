//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
         // code here 
        vector<int > v;
        int n = matrix.size();
        int m = matrix[0].size();
        int r = n;
        int c = m;
        int top=0;
        int left=0;
        int right=c-1;
        int bottom=r-1;
        int total= r*c;
        int count=0;
        while(left <= right && top <= bottom)
        {
            for(int index=left;index<=right;index++)
            {
                v.push_back(matrix[top][index]);
                count++;
            }
            top++;
            for(int index=top;index<=bottom;index++)
            {
                v.push_back(matrix[index][right]);
                count++;
            }
            right--;
            if ( top<= bottom ){
            for(int index = right;index>=left;index--)
            {
                v.push_back(matrix[bottom][index]);
                count++;
            }
            bottom--;}
            if (left <= right ){
            for(int index=bottom;index>=top;index--)
            {
                v.push_back(matrix[index][left]);
                count++;
            }
            left++;
            }
        }
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends