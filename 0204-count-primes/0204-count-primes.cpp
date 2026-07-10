class Solution {
public:
    void check(vector<int>& primes, int n) {
        for (int i = 2; i * i < n; i++) {
            if (primes[i]) {
                for (int j = i * i; j < n; j += i) {
                    primes[j] = 0;
                }
            }
        }
    }

    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<int> primes(n, 1);
        primes[0] = primes[1] = 0;

        check(primes, n);

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (primes[i]) count++;
        }

        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna