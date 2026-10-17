class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<tuple<int, int, int>> mp;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            int x = nums[i];

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            mp.push_back({sum, nums[i], i});
        }

        sort(mp.begin(), mp.end());

        vector<bool> vis(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || get<2>(mp[i]) == i)
                continue;

            int cycleSize = 0;
            int j = i;

            while (!vis[j]) {
                vis[j] = true;
                j = get<2>(mp[j]);
                cycleSize++;
            }

            if (cycleSize > 1)
                swaps += cycleSize - 1;
        }

        return swaps;
    }
};