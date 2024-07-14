//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long 
class Solution {
    private:
    ll merge(int start , int mid , int end , ll arr[]){
        vector<ll>temp;
        int i=start;
        int j=mid+1;
        ll ans=0;
        while(i<= mid && j<=end){
            if(arr[i]<=arr[j]){
                
                temp.push_back(arr[i]);
                i++;
            }
            
            else{
                temp.push_back(arr[j]);
                ans += mid-i+1;
                j++;
            }
        }
        while(i<=mid){
             temp.push_back(arr[i]);
             i++;
        }
        while(j<=end){
              temp.push_back(arr[j]);
              j++;
        }
        for(int k=start;k<=end;k++){
            arr[k]=temp[k-start];
        }
        return ans;
    }
    ll mergeSort(int i, int j , ll arr[]){
        if(i>=j){
            return 0;
        }
        ll ans = 0;
        int mid = (i+j)/2;
        ans += mergeSort(i,mid,arr);
        ans += mergeSort(mid+1 ,j, arr);
        ans += merge(i,mid,j,arr);
        return ans;
    }
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], int n) {

           return mergeSort(0,n-1, arr);     
      }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends