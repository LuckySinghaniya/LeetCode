class Solution {
public:
    bool solve(vector<int>& nums,int sum1,int sum2,int index,int n,int l,int r){
        if(l>r){
            return sum1>=sum2;
        }
            if(index%2==0){
                return 
                solve(nums,sum1+nums[l],sum2,index+1,n,l+1,r)||
                solve(nums,sum1+nums[r],sum2,index+1,n,l,r-1);
            }
            return
                solve(nums,sum1,sum2+nums[l],index+1,n,l+1,r)&&
                solve(nums,sum1,sum2+nums[r],index+1,n,l,r-1);
            
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int sum1=0,sum2=0;
        int l=0,r=n-1;
        return solve(nums,sum1,sum2,0,n,l,r);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna