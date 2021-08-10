
// NUMBER OF SUBARRAS WITH EXACTLY K distinct integers
// its number of subarrays with atmost k dist integers - number of subarrays with k-1 distinct integers
class Solution {
public:
    
    
    int Atmost(int k,vector<int>& arr)
    {
        int ans=0;
        int n=arr.size();
        int l=0,r=0;
        map<int,int> mp;
        while(r<n)
        {
            if(mp.count(arr[r])==0)
                mp[arr[r]]=0;
            mp[arr[r]]++;
            while(mp.size()>k)
            {
                mp[arr[l]]--;
                if(mp[arr[l]]==0) mp.erase(arr[l]);
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        return Atmost(k,arr)-Atmost(k-1,arr);
    }
};