//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int fun(int n)
    {
        int s=0;
        while(n!=0)
        {
            int p=n%10;
            s=s+(p*p);
            n=n/10;
        }
        return s;
    }
    int nextHappy(int N){
        // code here
        //N=N+1;
        while(N++)
        {
            int sq=N;
            int d=N;
            while(d>9)
            {
                d=fun(d);
            }
            //N=N+1;
            if(d==1 or d==7)return N;
            else continue;
            
        }
       
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends