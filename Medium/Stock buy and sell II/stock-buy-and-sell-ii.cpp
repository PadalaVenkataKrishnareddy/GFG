//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &p) {
        // code here
        int pro=0;
        int li=0;
        int gi=0;
        int f=1;
        int e=p[0];
        for(int i=1;i<n;i++)
        {
            if(p[i]<=e)
            {
                pro+=p[gi]-p[li];
                li=i;
                gi=i;
                e=p[i];
            }
            else
            {
                gi=i;
                e=p[i];
            }
        }
        if(li!=gi)pro+=p[gi]-p[li];
        return pro;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends