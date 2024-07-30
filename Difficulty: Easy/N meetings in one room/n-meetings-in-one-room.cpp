//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    bool static comp(pair<int, int>&p1 , pair<int, int >&p2){
        return p1.second<p2.second;
        
        
    }
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int >> vec;
        for(int i=0;i<n;i++){
            vec.push_back({start[i] , end[i]});
            
        }
        sort(vec.begin() , vec.end() , comp);
            int ans =1;
            int prev = vec[0].second;
            for(int i=1;i<n;i++){
               // cout<<vec[i].second;
                if(vec[i].first>prev){
                    ans++;
                    prev = vec[i].second;
                }
               
            }
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
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends