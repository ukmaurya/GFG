//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        int timer=1;
        unordered_map<int, int> mp; // pageno , timer;
        set<pair<int, int>>st; // timer , page ;
        int size = 0;
        int ans =0;
        for(int i=0;i<N;i++){
            if(mp.find(pages[i]) != mp.end()){
                 int oldTime = mp[pages[i]];
                 mp[pages[i]]=timer;
                 st.erase({oldTime, pages[i]});
                 st.insert({timer , pages[i]});
                 timer++;
            }
            else{
               if(size<C){
                   mp[pages[i]]=timer;
                   st.insert({timer , pages[i]});
                   size++;
               }
               else{
                   auto lru = st.begin();
                   mp.erase(lru->second);
                   st.erase({lru->first , lru->second});
                   st.insert({timer,pages[i]});
                   mp[pages[i]]=timer;
               }
               timer++;
               ans++;
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
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends