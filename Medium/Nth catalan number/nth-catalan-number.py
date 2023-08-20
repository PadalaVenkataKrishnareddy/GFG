import math
class Solution:
    def findCatalan(self, n : int) -> int:
        # code here
        m=1000000007
        n1=math.factorial(2*n)
        d=math.factorial(n)
        d2=math.factorial(n+1)
        d3=(d*d2)
        return (n1//d3)%m
        
        



#{ 
 # Driver Code Starts
if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        obj = Solution()
        res = obj.findCatalan(n)
        
        print(res)
        

# } Driver Code Ends