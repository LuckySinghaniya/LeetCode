class Solution {
public:
    int distinctSubseqII(string s) {

        const int MOD = 1e9 + 7;

        long long dp = 1;

        vector<long long> last(26, 0);

        for(char c : s) {

            long long old = dp;

            dp = (2 * dp - last[c - 'a'] + MOD) % MOD;

            last[c - 'a'] = old;
        }

        // Remove empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};