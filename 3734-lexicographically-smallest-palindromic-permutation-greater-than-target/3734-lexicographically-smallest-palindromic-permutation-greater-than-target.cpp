class Solution {
public:

    string makePalindrome(string half, char middle) {

        string ans = half;

        if (middle != '#')
            ans += middle;

        string rev = half;
        reverse(rev.begin(), rev.end());

        ans += rev;

        return ans;
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // -----------------------------------
        // 1. Frequency of characters
        // -----------------------------------
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // -----------------------------------
        // 2. Check palindrome possibility
        // -----------------------------------
        int odd = 0;
        char middle = '#';

        for (int i = 0; i < 26; i++) {

            if (freq[i] % 2) {
                odd++;
                middle = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // -----------------------------------
        // 3. Frequency of characters in half
        // -----------------------------------
        vector<int> halfFreq(26);

        for (int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2;
        }

        int len = n / 2;

        // -----------------------------------
        // 4. Smallest possible palindrome
        // -----------------------------------
        string smallestHalf = "";

        for (int i = 0; i < 26; i++) {
            while (halfFreq[i] > 0) {
                smallestHalf += char('a' + i);
                halfFreq[i]--;
            }
        }

        string smallest = makePalindrome(smallestHalf, middle);

        if (smallest > target)
            return smallest;

        // Restore half frequencies
        for (int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2;
        }

        // -----------------------------------
        // 5. Target's first half
        // -----------------------------------
        string targetHalf = target.substr(0, len);

        // -----------------------------------
        // IMPORTANT CASE:
        // targetHalf itself can be formed
        // -----------------------------------
        vector<int> rem = halfFreq;

        bool possible = true;

        for (char c : targetHalf) {

            int x = c - 'a';

            if (rem[x] == 0) {
                possible = false;
                break;
            }

            rem[x]--;
        }

        if (possible) {

            string candidate = makePalindrome(targetHalf, middle);

            if (candidate > target)
                return candidate;
        }

        // -----------------------------------
        // 6. Find smallest half > targetHalf
        // -----------------------------------

        for (int pos = len - 1; pos >= 0; pos--) {

            vector<int> cnt = halfFreq;

            // Match target prefix [0 ... pos-1]
            bool ok = true;

            for (int i = 0; i < pos; i++) {

                int x = targetHalf[i] - 'a';

                if (cnt[x] == 0) {
                    ok = false;
                    break;
                }

                cnt[x]--;
            }

            if (!ok)
                continue;

            // Try smallest character greater
            // than targetHalf[pos]
            int cur = targetHalf[pos] - 'a';

            for (int c = cur + 1; c < 26; c++) {

                if (cnt[c] == 0)
                    continue;

                string newHalf = targetHalf.substr(0, pos);

                newHalf += char('a' + c);

                cnt[c]--;

                // Fill remaining characters
                // in smallest possible order
                for (int x = 0; x < 26; x++) {

                    while (cnt[x] > 0) {
                        newHalf += char('a' + x);
                        cnt[x]--;
                    }
                }

                string candidate = makePalindrome(newHalf, middle);

                if (candidate > target)
                    return candidate;
            }
        }

        return "";
    }
};