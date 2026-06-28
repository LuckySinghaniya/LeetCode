class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Handle 1 separately
        if (freq.count(1)) {
            int cnt = freq[1];
            if (cnt % 2 == 0) cnt--;
            ans = max(ans, cnt);
        }

        for (auto &[x, c] : freq) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (true) {
                auto it = freq.find(cur);
                if (it == freq.end() || it->second < 2)
                    break;

                len += 2;

                // No larger square can exist in nums (nums[i] <= 1e9)
                if (cur > 31622) {
                    cur = -1;
                    break;
                }

                cur *= cur;
            }

            if (cur != -1) {
                auto it = freq.find(cur);
                if (it != freq.end() && it->second >= 1)
                    len++;
                else if (len > 0)
                    len--;
            } else {
                if (len > 0)
                    len--;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna