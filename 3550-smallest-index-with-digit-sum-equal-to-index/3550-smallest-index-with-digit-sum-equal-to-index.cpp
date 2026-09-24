class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int temp=nums[i],count=0;
            while(temp>0){
                count+=(temp%10);
                temp/=10;
            }
            if(count==i) return i;
        }
        return -1;
    }
};