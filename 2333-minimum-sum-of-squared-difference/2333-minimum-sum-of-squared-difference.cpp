
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long K = 1LL * k1 + k2;
        vector<long long> d(n);

        long long total = 0, mx = 0;

        for (int i = 0; i < n; i++) {
            d[i] = abs(nums1[i] - nums2[i]);
            total += d[i];
            mx = max(mx, d[i]);
        }

        if (K >= total) return 0;

        long long lo = 0, hi = mx;

        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            long long need = 0;

            for (long long x : d) {
                if (x > mid) need += x - mid;
            }

            if (need <= K)
                hi = mid;
            else
                lo = mid + 1;
        }

        long long level = lo;
        long long used = 0, ans = 0;

        for (long long x : d) {
            if (x > level) {
                used += x - level;
                ans += level * level;
            } else {
                ans += x * x;
            }
        }

        long long remaining = K - used;

        // Reduce 'remaining' elements from level to level - 1.
        ans -= remaining * (2 * level - 1);

        return ans;
    }
};