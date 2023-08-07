//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int fun(int ind,int w,int a[],int pr[],int n,vector<vector<int>> &v)
    {
        if(ind<0)return 0;
        if(v[ind][w]!=-1)return v[ind][w];
        int ma1=INT_MIN,ma2;
        if(a[ind]<=w)
        {
            ma1=pr[ind]+fun(ind-1,w-a[ind],a,pr,n,v);
        }
        ma2=fun(ind-1,w,a,pr,n,v);
    
        return v[ind][w]=max(ma1,ma2);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> v(n+1,vector<int>(W+1,-1));
       return fun(n-1,W,wt,val,n,v);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends