//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
// 	int fun(int c[],int n,int s,vector<int> &vi)
// 	{
// 	    if(s==0)
// 	    {
// 	        return 0;
// 	    }
// 	    if(vi[s]!=-1)return vi[s];
// 	    int re=INT_MAX;
// 	    for(int i=0;i<n;i++)
// 	    {
// 	        if(c[i]<=s)
// 	        {
// 	            re=min(re,1+fun(c,n,s-c[i],vi));
// 	        }
// 	    }
// 	    return vi[s]=re;
// 	}
long long int fun(int v[],long long int s,vector<long long int> &re,long long int n)
{
    if(s==0)
    {
        return 0;
    }
    //cout<<"HI";
    if(re[s]!=-1)return re[s];
    long long int res=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(v[i]<=s)
        {
            res=min(res,1+fun(v,s-v[i],re,n));
        }
    }
    //cout<<re[s];
    return re[s]=res;
}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	   // vector<int> vi(V+1,-1);
	   // int k=fun(coins,M,V,vi);
	   // if(k==-1)return -1;
	   // return k;
	vector<long long int> re(V+1,-1);
    long long int t=fun(coins,V,re,M);
    if(t!=INT_MAX)return t;
    else return -1;
    return 0;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends