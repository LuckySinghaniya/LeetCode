class Solution {
public:
    void solve(vector<int>& candidates,vector<vector<int>>& ans,vector<int>&temp,int index, int target,int sum){
        if(sum==target){
                ans.push_back(temp);
                return;
            }
        if(index==candidates.size() || sum>target){
            return;
        }
        temp.push_back(candidates[index]);
        solve(candidates,ans,temp,index,target,sum+candidates[index]);
        temp.pop_back();
        solve(candidates,ans,temp,index+1,target,sum);  
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>temp;
        int sum=0;
        solve(candidates,ans,temp,0,target,sum);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna