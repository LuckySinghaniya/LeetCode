class Solution {
public:
    static const long long MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();

        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                long long a = A[i][k];

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] + a * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
            res[i][i] = 1;

        while (exp) {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int S = 2 * m;

        Matrix T(S, vector<long long>(S, 0));

        for (int x = 0; x < m; x++) {

            // down[y] -> up[x]
            for (int y = 0; y < x; y++)
                T[x][m + y] = 1;

            // up[y] -> down[x]
            for (int y = x + 1; y < m; y++)
                T[m + x][y] = 1;
        }

        vector<long long> V(S, 0);

        for (int x = 0; x < m; x++) {
            V[x] = x;
            V[m + x] = m - 1 - x;
        }

        Matrix P = power(T, n - 2);

        vector<long long> ansVec(S, 0);

        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                ansVec[i] =
                    (ansVec[i] + P[i][j] * V[j]) % MOD;
            }
        }

        long long ans = 0;

        for (long long x : ansVec)
            ans = (ans + x) % MOD;

        return (int)ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna