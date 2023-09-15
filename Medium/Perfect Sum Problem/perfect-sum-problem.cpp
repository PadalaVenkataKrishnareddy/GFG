//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long m=1e9+7;
	int fun(int ind,int arr[],int s,int n,vector<vector<int>> &v)
	{
	    if(ind>=n)
	    {
	        if(s==0)return 1;
	        else return 0;
	    }
	    if(v[ind][s]!=-1)return v[ind][s];
	    int ma=0;
	    int nm=0;
	   // if(arr[ind]==s)ma+=1;
	    if(arr[ind]<=s)ma=fun(ind+1,arr,s-arr[ind],n,v);
	    nm=fun(ind+1,arr,s,n,v);
	   // cout<<nm+ma<<" ";
	    return v[ind][s]=(ma+nm)%m;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> v(n+1,vector<int>(sum+1,-1));
        return fun(0,arr,sum,n,v);
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends