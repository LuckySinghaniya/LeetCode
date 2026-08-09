class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int i=0;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        while(i<n){
            int j=i;
            int lower=intervals[j][0];
            int higher=intervals[j][1];
            while(j+1<n && higher>=intervals[j+1][0]){
                higher=max(higher,intervals[j+1][1]);
                j++;
            }
            ans.push_back({lower,higher});
            i=j+1;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna