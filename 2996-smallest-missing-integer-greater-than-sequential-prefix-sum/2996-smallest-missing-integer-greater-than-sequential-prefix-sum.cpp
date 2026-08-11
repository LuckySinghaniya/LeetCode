class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int num=-1,count=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]+1){
                break;
            }
            else{
                count+=nums[i];
            }
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==count) count++;
        }
        return count;
    }
};