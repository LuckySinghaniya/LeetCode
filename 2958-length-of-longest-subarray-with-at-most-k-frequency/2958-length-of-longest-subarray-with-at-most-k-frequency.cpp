class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int l=0,i=0,ans=0;
        while(i<nums.size()){
                mp[nums[i]]++;
                while(mp[nums[i]]>k){
                    mp[nums[l]]--;
                    l++;
                }   
            
            ans=max(ans,i-l+1);
            i++;
        }
        return ans;
    }
};