class Solution {
public:
    // void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int>& temp,int index){
    //     if(index==nums.size()){
    //     ans.push_back(temp);
    //         return;
    //     } 
    //         temp.push_back(nums[index]);
    //         solve(nums,ans,temp,index+1);
    //         temp.pop_back();
    //         solve(nums,ans,temp,index+1);
    // }
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int>>ans;
    //     vector<int>temp;
    //     solve(nums,ans,temp,0);
    //     return ans;
    // }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n=(1<<nums.size());
        vector<vector<int>>ans;
        for(int num=0;num<n;num++){
            vector<int>temp;
            for(int i=0;i<nums.size();i++){
                if(num &(1<<i)){
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna