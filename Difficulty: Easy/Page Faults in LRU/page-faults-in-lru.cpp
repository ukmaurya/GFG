//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
public:
    int pageFaults(int n, int C, int pages[]){
        // code here
        int timer = 0;
        unordered_map<int, int> mp1; // page -> time
        set<pair<int, int>> s; // {time, page} to maintain order of access
        int pagefaults = 0;

        for (int i = 0; i < n; i++) {
            int page = pages[i];
            
            // If the page is already in cache, update its time
            if (mp1.find(page) != mp1.end()) {
                s.erase({mp1[page], page}); // Remove the old time entry
            } else {
                // Page fault occurs
                pagefaults++;
                
                // If cache is full, remove the least recently used page
                if (mp1.size() == C) {
                    auto lru = s.begin(); // Get the least recently used page
                    mp1.erase(lru->second); // Remove it from the cache
                    s.erase(lru); // Remove it from the set
                }
            }
            
            // Insert the page with the new time
            mp1[page] = timer;
            s.insert({timer, page});
            timer++;
        }
        
        return pagefaults;
        
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