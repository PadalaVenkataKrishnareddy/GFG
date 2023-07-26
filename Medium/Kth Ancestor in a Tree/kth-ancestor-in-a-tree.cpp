//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
// void fun(Node *r,unordered_map<int,int> &v,int node)
// {
//     if(r==NULL)return;
//     queue<Node *> q;
//     Node *root=r;
//     q.push(r);
//     while(!q.empty())
//     {
//         int s=q.size();
        
//         for(int i=0;i<s;i++)
//         {
//           r=q.front();
//           q.pop();
//           if(r->left)
//           {
//               q.push(r->left);
//               v[r->left->data]=r->data;
//               if(r->left->data==node)return;
//           }
//           if(r->right)
//           {
//               q.push(r->right);
//               v[r->right->data]=r->data;
//               if(r->right->data==node)return;
//           }
          
//         }
//     }
// }
// void fun(Node *r,unordered_map<int,int> &m,int node)
// {
//     if(r==NULL)return;
//     if(r->left)
//     {
//         m[r->left->data]=r->data;
//         if(r->left->data==node)return;
//         fun(r->left,m,node);
//     }
//     if(r->right)
//     {
//         m[r->right->data]=r->data;
//         if(r->right->data==node)return;
//         fun(r->right,m,node);
//     }
    
// }
// int ite(unordered_map<int,int> m,int k,int d,int rd)
// {
//   if(m[d]==0 and k!=0 and m[d]!=rd)return -1;
//   if(k==0)return d;
//   else if(d!=rd) return ite(m,k-1,m[d],rd);
// }
void fun(Node *r,int no,vector<int> &v,int &fl)
{
    if(r==NULL)return;
    if(r->data==no)
    {
        fl=0;
    }
    if(fl==1)v.push_back(r->data);
    if(fl==1)fun(r->left,no,v,fl);
    if(fl==1)fun(r->right,no,v,fl);
    if(fl==1)v.pop_back();
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
//     unordered_map<int,int> v;
//     fun(root,v,node);
//     // for(auto it:v)
//     // {
        
//     //     cout<<it.first<<" "<<it.second<<endl;
        
//     // }
//   return ite(v,k,node,root->data);r
      vector<int> v;
      int fl=1;
      fun(root,node,v,fl);
      reverse(v.begin(),v.end());
      if(fl==1 or k>v.size())return -1;
      return v[k-1];
    
    
    
    
    
}
