//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int fun(int s,int ind,vector<int> &a,vector<vector<int>> &vi)
    {
        if(s==0)return 1;
        if(ind==-1)return 0;
        if(vi[s][ind]!=-1)return vi[s][ind];
        if(a[ind]<=s)return vi[s][ind]=fun(s-a[ind],ind-1,a,vi) || fun(s,ind-1,a,vi);
        if(a[ind]>s)return vi[s][ind]=fun(s,ind-1,a,vi);

    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>> vi(sum+1,vector<int>(n+1,-1));
        return fun(sum,n-1,arr,vi);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends