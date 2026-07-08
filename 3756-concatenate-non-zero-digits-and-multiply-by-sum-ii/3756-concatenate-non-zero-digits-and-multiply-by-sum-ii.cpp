class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> pw(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pw[i] = pw[i - 1] * 10 % MOD;

        vector<int> cnt(n + 1, 0);
        vector<long long> prefSum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i];
            prefSum[i + 1] = prefSum[i];
            if (s[i] != '0') {
                cnt[i + 1]++;
                prefSum[i + 1] += s[i] - '0';
            }
        }

        vector<long long> prefNum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefNum[i + 1] = prefNum[i];
            if (s[i] != '0') {
                prefNum[i + 1] =
                    (prefNum[i + 1] * 10 + (s[i] - '0')) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            long long digitSum =
                (prefSum[r + 1] - prefSum[l] + MOD) % MOD;

            int k = cnt[r + 1] - cnt[l];

            long long left = prefNum[l];
            long long right = prefNum[r + 1];

            long long number =
                (right - left * pw[k] % MOD + MOD) % MOD;

            ans.push_back(number * digitSum % MOD);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna