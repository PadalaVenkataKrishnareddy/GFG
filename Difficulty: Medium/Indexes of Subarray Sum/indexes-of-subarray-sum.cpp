class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int i=0,j=0;
        int n=arr.size();
        int s=0;
        while(i<=j and j<=n)
        {
            if(s==target)return{i+1,j};
            else if(s<target){
                s+=arr[j];
                j++;
            }
            else{
                s-=arr[i];
                i++;
            }
            
        }
        return {-1};
        
    }
};