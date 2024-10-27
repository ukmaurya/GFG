//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
           unordered_map<int, int>mp1, mp2;
        for(int i = 0 ; i < 2* N ; i+=2)
        {
            if(arr[i] < arr[i+1])
            {
                mp1[arr[i]] = arr[i+1];
            }
            else
            {
                mp2[arr[i]] = arr[i+1];
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, 1});
        int ans = 0;
        while(!pq.empty())
        {
            int move = pq.top().first;
            int position = pq.top().second;
            pq.pop();
            if(position >= 30){ans = move;break;}
            for(int i = 1 ; i <= 6 ; i++)
            {
                int nextPosition = position+i;
                if(mp1.find(nextPosition) != mp1.end())
                {
                    auto it = mp1.find(nextPosition);
                    int nextLocation = it->second;
                    pq.push({move+1, nextLocation});
                }
                else if(mp2.find(nextPosition) != mp2.end())
                {
                    auto it = mp2.find(nextPosition);
                    int nextLocation = it->second;
                    pq.push({move+1, nextLocation});
                }
                else
                {
                    pq.push({move+1, nextPosition});
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends