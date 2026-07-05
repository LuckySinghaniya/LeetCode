class Solution {
public:
    int merge(int low,int mid, int high,vector<int>& nums){
        int count=0;
        int j=mid+1;
        int left=low,right=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && (long long)nums[i]>2LL*nums[j]) j++;
            count+=(j-(mid+1));
        }
        vector<int>temp;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
        return count;
    }
    int mergesort(int low,int high,vector<int>& nums){
        if(low>=high) return 0;
        int count=0;
        int mid=low+(high-low)/2;
        
        count+=mergesort(low,mid,nums);
        count+=mergesort(mid+1,high,nums);
        count+=merge(low,mid,high,nums);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        return mergesort(low,high,nums);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna