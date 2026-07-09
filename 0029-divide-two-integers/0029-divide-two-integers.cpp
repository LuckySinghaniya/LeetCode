class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool sign = ((dividend < 0) ^ (divisor < 0));

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long ans = 0;

        while (n >= d) {
            int cnt = 0;

            while (n >= (d << (cnt + 1)))
                cnt++;

            ans += (1LL << cnt);
            n -= (d << cnt);
        }

        if (sign)
            ans = -ans;

        return (int)ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna