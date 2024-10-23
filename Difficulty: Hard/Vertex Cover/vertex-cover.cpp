//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int vertexCover(int n, vector<pair<int, int>> &edges) {
                // code here
                 int ans = INT_MAX;

        for (int i = 1; i < (1 << n); i++) {
            int count = 0;
            vector<int> vis(n + 1, 0);

            for (int j = 0; j < n; j++) {
                if ((1 << j) & i) {
                    vis[j + 1] = 1;
                    count++;
                }
            }

            int isValid = 1;
            for (int k = 0; k < edges.size(); k++) {
                int x = edges[k].first;
                int y = edges[k].second;
                if (vis[x] || vis[y]) {
                    continue;
                } else {
                    isValid = 0;
                    break;
                }
            }

            if (isValid) {
                ans = min(ans, count);
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
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends