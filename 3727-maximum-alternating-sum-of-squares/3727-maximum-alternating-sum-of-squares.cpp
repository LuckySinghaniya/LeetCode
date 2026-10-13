class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n);
        for(int i=0;i<n;i++){
            if(nums[i]>=0) temp[i]=nums[i];
            else temp[i]=-nums[i];
        }
        sort(temp.begin(),temp.end());
        long long sum1=0,sum2=0;
            for(int i=0;i<n/2;i++){
                sum1+=temp[i]*temp[i];
            }
            for(int i=n/2;i<n;i++){
                sum2+=temp[i]*temp[i];
            }
            return sum2-sum1;
        
    }
};