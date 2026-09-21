class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for(int x : nums) {

            vector<long long> ndp(k, 0);

            // Start a new subarray [x]
            ndp[x % k]++;

            // Extend previous subarrays
            for(int r = 0; r < k; r++) {

                int newR = (1LL * r * x) % k;

                ndp[newR] += dp[r];
            }

            // Add all subarrays ending at current index
            for(int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }

            dp = ndp;
        }

        return ans;
    }
};