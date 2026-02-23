class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        set <int> uset;
        vector<int> v;
        for(int i=0;i<a.size();i++)
        {
            uset.insert(a[i]);
        }
        for(int i=0;i<b.size();i++)
        {
            uset.insert(b[i]);
        }
        for(int x : uset)
        {
            v.insert(v.begin(),x);
            
        }
        return v;
    }
};