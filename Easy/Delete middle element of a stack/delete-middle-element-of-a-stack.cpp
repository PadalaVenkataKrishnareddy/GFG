//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sz)
    {
        // code here.. 
        //cout<<s.top();
        if(sz%2!=0)
        {
            int m=sz/2;
            stack<int> n;
            int i=0;
            while(i!=m)
            {
                n.push(s.top());
                s.pop();
                i++;
            }
            s.pop();
            while(!n.empty())
            {
                s.push(n.top());
                n.pop();
            }
        }
        else
        {
           int m=sz/2;
            stack<int> n;
            int i=0;
            while(i!=m)
            {
                n.push(s.top());
                s.pop();
                i++;
            }
            s.pop();
            while(!n.empty())
            {
                s.push(n.top());
                n.pop();
            } 
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends