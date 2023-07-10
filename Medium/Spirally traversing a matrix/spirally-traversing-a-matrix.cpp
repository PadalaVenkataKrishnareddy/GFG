//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    void fun(int a,int b,int top,int bot,int le,int ri,vector<vector<int>> &vi,vector<vector<int>> &m,vector<int> &re)
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
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<vector<int>>vi(r,vector<int>(c,-1));
        vector<int> re;
        fun(0,0,0,r-1,0,c-1,vi,matrix,re);
        return re;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends