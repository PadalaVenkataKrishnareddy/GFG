//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool fun(int a,int b,int n,int m,vector<vector<int>> &g,vector<vector<bool>> &re,vector<vector<int>> &v)
    {
        if(a>=n or b>=m or a<0 or b<0 or g[a][b]==0 or v[a][b]==1)return false;
        if(re[a][b]==true or g[a][b]==2)return true;
        v[a][b]=1;
        bool t=fun(a,b+1,n,m,g,re,v) || fun(a,b-1,n,m,g,re,v) || fun(a-1,b,n,m,g,re,v) || fun(a+1,b,n,m,g,re,v);
        return re[a][b]=t;
      
    }
    bool is_Possible(vector<vector<int>>& g) 
    {
        //code here
        
        int n=g.size();
        int m=g[0].size();
        vector<vector<bool>> re(n+1,vector<bool>(m+1,false));
        vector<vector<int>> v(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(g[i][j]==1)
                {
                    return fun(i,j,n,m,g,re,v);
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends