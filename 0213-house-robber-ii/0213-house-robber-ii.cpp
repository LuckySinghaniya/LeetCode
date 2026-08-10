class Solution {
public:
    int solve(vector<int>&a){
        int n=a.size();
        int prev2=0;
        int prev=a[0];
        for(int i=1;i<n;i++){
            int take=a[i];
            if(i>1) take+=prev2;
            int nottake=prev;
            int curr=max(take,nottake);
            prev2=prev;
            prev=curr;
        }
        return prev;
        // if(index==0) return nums[index];
        // if(index<0) return 0;
        // if(dp[index]!=-1) return dp[index];
        // int pick=solve(index,nums,dp)+solve(index-2,nums,dp);
        // int notpick=solve(index-1,nums,dp);
        // return dp[index]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(solve(temp1),solve(temp2));
    }
};