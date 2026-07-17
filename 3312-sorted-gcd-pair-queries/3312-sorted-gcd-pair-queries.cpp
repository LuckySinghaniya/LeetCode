class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1);
        for (int x : nums)
            freq[x]++;

        vector<long long> exact(mx + 1);

        // Count pairs divisible by i
        for (int i = 1; i <= mx; i++) {
            long long cnt = 0;
            for (int j = i; j <= mx; j += i)
                cnt += freq[j];

            exact[i] = cnt * (cnt - 1) / 2;
        }

        // Inclusion-Exclusion
        for (int i = mx; i >= 1; i--) {
            for (int j = 2 * i; j <= mx; j += i)
                exact[i] -= exact[j];
        }

        vector<pair<long long,int>> pref;

        long long sum = 0;

        for (int i = 1; i <= mx; i++) {
            if (exact[i] == 0) continue;
            sum += exact[i];
            pref.push_back({sum, i});
        }

        vector<int> ans;

        for (long long q : queries) {
            long long need = q + 1;

            int l = 0, r = pref.size() - 1;

            while (l < r) {
                int mid = (l + r) / 2;

                if (pref[mid].first >= need)
                    r = mid;
                else
                    l = mid + 1;
            }

            ans.push_back(pref[l].second);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna