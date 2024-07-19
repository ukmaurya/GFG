//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // we will be using the elemination method 
        stack<int> st;
        //push every candidate in the stack 
        for(int i=0;i<n;i++){
            st.push(i);
        }
        // take out 2 candidate every time and check wether it is a celebrate or not 
        while(st.size()>1){
            int first = st.top();
            st.pop();
            int sec = st.top();
            st.pop();
            if(M[first][sec]==1){ // first knows second => first cannot be a celebratiy 
              st.push(sec); // push potential candidate 
            }
            else{
                st.push(first);
            }
            
        }
        int potential = st.top();
        // verify the potential candidate 
        for(int i=0;i<n;i++){ // potential knows anyone 
            if(M[potential][i]==1)
              return -1;
        }
        for(int i=0;i<n;i++){
            if(potential!=i&& M[i][potential]==0) // since diagonal will be always zero 
              return -1;
        }
        return potential;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends