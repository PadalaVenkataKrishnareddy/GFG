#User function Template for python3

class Solution:
    def findLargest(self, n, s):
        # code here
        if(n==1 and s>9 or s==0 and n>1):
            return -1
        st=""
        l=n
        while(s>9 and n!=0):
            st+='9'
            n-=1
            s=s-9
        if(len(st)==l and s==0):
            return int(st)
        elif(len(st)==l and s!=0):
            return -1
        else:
            while(n):
                st+=str(s)
                s=0
                n-=1
        return int(st)
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N, S = [int(x) for x in input().split()]
        
        ob = Solution()
        print(ob.findLargest(N, S))
# } Driver Code Ends