class Solution {
public:
    int solve(int index,int sum,vector<int>& nums, int target){
        if(index<0){
            if(sum==target) return 1;
            return 0;
        }
        int a=solve(index-1,sum+nums[index],nums,target);
        int b=solve(index-1,sum-nums[index],nums,target);
        return a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(n-1,0,nums,target);
    }
};