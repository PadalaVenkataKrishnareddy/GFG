//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    void fun(int a,int b,int top,int bot,int le,int ri,vector<vector<int>> &vi,int m[MAX][MAX],vector<int> &re)
    {
        //cout<<top<<" "<<bot<<" "<<le<<" "<<ri<<" "<<endl;
        if(top>bot or le>ri)return;
        if(vi[a][b]!=-1)return;
        for(int i=le;i<=ri;i++)
        {
            re.push_back(m[top][i]);
            vi[top][i]=1;
        }
        top++;
        for(int i=top;i<=bot;i++)
        {
            re.push_back(m[i][ri]);
            vi[i][ri]=1;
        }
        ri--;
        for(int i=ri;i>=le & top<=bot ;i--)
        {
            re.push_back(m[bot][i]);
            vi[bot][i]=1;
        }
        bot--;
        for(int i=bot;i>=top & le<=ri;i--)
        {
            re.push_back(m[i][le]);
            vi[i][le]=1;
        }
        le++;
        fun(top,le,top,bot,le,ri,vi,m,re);
        return;
    }
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		 vector<vector<int>>vi(n,vector<int>(m,-1));
        vector<int> re;
        fun(0,0,0,n-1,0,m-1,vi,a,re);
        return re[k-1];
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends