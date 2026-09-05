class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int maximum=INT_MIN;
        int minimum=INT_MAX;
        vector<int>mini(n);
        for(int i=n-1;i>=0;i--){
            minimum=min(minimum,nums[i]);
            mini[i]=minimum;
        }
        bool flag=false;
        int i=0;
        while(i<n){
            maximum=max(maximum,nums[i]);
            if(maximum-mini[i]<=k){
                flag=true;
                break;
            }
            i++;
        }
        if(flag) return i;
        return -1;
    }
};