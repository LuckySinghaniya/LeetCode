class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minindex=-1,maxindex=-1,minimum=INT_MAX,maximum=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++){
            if(minimum>nums[i]){
                minimum=nums[i];
                minindex=i;
            }
            if(maximum<nums[i]){
                maximum=nums[i];
                maxindex=i;
            }
        }
        int a=max(minindex+1,maxindex+1);
        int b=max(n-minindex,n-maxindex);
        int c=INT_MAX;
        if(maxindex<minindex){
            c=maxindex+1+n-minindex;
        }
        else c=n-maxindex+minindex+1;
        return min({a,b,c});
    }
};