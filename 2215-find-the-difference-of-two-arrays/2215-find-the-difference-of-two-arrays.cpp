class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp1;
        vector<vector<int>> ans(2);
        int n=nums1.size(),m=nums2.size();
        for(int i=0;i<n;i++){
            mp1[nums1[i]]=1;
        }

        for(int j=0;j<m;j++){
            if(mp1[nums2[j]]==0){
                mp1[nums2[j]]=2;
            }
            else if(mp1[nums2[j]]==1){
                mp1[nums2[j]]=-1;
            }
        }
        for(const auto& pair:mp1){
            if(pair.second==1){
                ans[0].push_back(pair.first);
            }
            else if(pair.second==2){
                ans[1].push_back(pair.first);
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna