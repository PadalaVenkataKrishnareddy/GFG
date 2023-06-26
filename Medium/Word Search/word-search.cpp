//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void fun(int i,int j,int s,vector<vector<char>> &ma,string w,bool &f,int n,int m,vector<vector<int>> &vi)
    {
        
        if(i==n or j==m or i==-1 or j==-1 or vi[i][j]==1 or f==true or w[s]!=ma[i][j])
        {
            return;
        }
        if(s==w.size()-1)
        {
            //cout<<s<<" ";
            //if(s==w)f=true;
            f=true;
            return;
        }
        vi[i][j]=1;
        fun(i-1,j,s+1,ma,w,f,n,m,vi);
        fun(i+1,j,s+1,ma,w,f,n,m,vi);
        fun(i,j+1,s+1,ma,w,f,n,m,vi);
        fun(i,j-1,s+1,ma,w,f,n,m,vi);
        vi[i][j]=0;
        
    }
    bool wordSearch(vector<vector<char>>& ma, string w) {
        //code here
        int s=0;
        bool f=false;
        int n=ma.size();
        int m=ma[0].size();
        vector<vector<int>>vi(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ma[i][j]==w[0] and vi[i][j]==0)fun(i,j,s,ma,w,f,n,m,vi);
                if(f==true)return f;
            }
        }
        
        return f;
        
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
        vector<vector<char>> mat(n,vector<char>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>mat[i][j];
            }
        }
        string str; cin>>str;
        Solution ob;
        auto ans=ob.wordSearch(mat,str);
        cout<<ans<<"\n";
    }
    return 0;
}

// } Driver Code Ends