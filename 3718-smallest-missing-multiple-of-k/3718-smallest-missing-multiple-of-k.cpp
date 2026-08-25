class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=1;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            if(nums[i]%k==0){
                if(nums[i]/k==ans) ans++;
                else break;
            }
        }
        return ans*k;
    }
};