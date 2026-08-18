class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==k) return *max_element(nums.begin(),nums.end());
        if(k==1){
            vector<int>freq(51,0);
            for(int i=0;i<n;i++){
                freq[nums[i]]++;
            }
            for(int i=50;i>0;i--){
                if(freq[i]==1) return i;
            }
            return -1;
        }
        // if(nums.size()==2){
        //     if(nums[0]==nums[1]) return -1;
        //     else return max(nums[0],nums[1]);
        // }
        int a=nums[0],b=nums[nums.size()-1];
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]==a) a=-1;
            if(nums[i]==b) b=-1;
        }
        if(a==-1) return b;
        else if(b==-1) return a;
        else if(a==b) return -1;
        else return max(a,b);
    }
};