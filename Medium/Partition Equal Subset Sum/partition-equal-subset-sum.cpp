//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int fun(int ind,int arr[],int n,int s,int fs,vector<vector<int>> &v)
    {
        if(ind==n)return 0;
        if(s==fs)return 1;
        if(v[ind][fs]!=-1)return v[ind][fs];
        int m=0;
        if(arr[ind]<=fs)m=fun(ind+1,arr,n,s+arr[ind],fs-arr[ind],v);
        int m1=fun(ind+1,arr,n,s,fs,v);
        return v[ind][fs]=max(m,m1);
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int fs=0;
        for(int i=0;i<n;i++)
        {
          fs+=arr[i];  
        }
        
        int s=0;
        vector<vector<int>> v(n+1,vector<int>(fs+1,-1));
        if(fs%2==1)return 0;
        return fun(0,arr,n,s,fs,v);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends