//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int fun(int a,int b,int n,int m,vector<vector<int>> &g,vector<vector<int>> &v)
    {
        if(a==n-1)return g[a][b];
        if(v[a][b]!=-1)return v[a][b];
        int ma=-1;
        if(b!=0)ma=max(ma,g[a][b]+fun(a+1,b-1,n,m,g,v));
        if(b!=m-1)ma=max(ma,g[a][b]+fun(a+1,b+1,n,m,g,v));
        ma=max(ma,g[a][b]+fun(a+1,b,n,m,g,v));
        return v[a][b]=ma;
    }
    int maximumPath(int N, vector<vector<int>> mat)
    {
        // code here
        // vector<vector<int>>v(n+1,vector<int>(m+1,-1));
        int n=mat.size();
        int m=mat[0].size();
        int ma=-1;
        vector<vector<int>>v(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++)
        {
            ma=max(ma,fun(0,i,n,m,mat,v));
        }
        return ma;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends