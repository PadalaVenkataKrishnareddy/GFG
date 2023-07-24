//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string st)
    {
        // Your code here
        stack<int> s;
        int c=0;
        int c1=0;
        for(int i=0;i<st.size();i++)
        {
            if(st[i]=='*')
            {
                c=s.top();
                s.pop();
                c1=s.top();
                s.pop();
                s.push(c1*c);
            }
            else if(st[i]=='/')
            {
                c=s.top();
                s.pop();
                c1=s.top();
                s.pop();
                s.push(c1/c);
            }
            else if(st[i]=='+')
            {
                c=s.top();
                s.pop();
                c1=s.top();
                s.pop();
                s.push(c1+c);
            }
            else if(st[i]=='-')
            {
                c=s.top();
                s.pop();
                c1=s.top();
                s.pop();
                s.push(c1-c);
            }
            else
            {
               s.push(st[i]-'0'); 
            }
        }
        return s.top();
        
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends