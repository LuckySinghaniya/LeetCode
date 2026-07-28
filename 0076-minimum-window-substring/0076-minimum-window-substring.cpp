class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        for (char c : t)
            mp[c]++;

        int l = 0;
        int count = 0;
        int minimum = INT_MAX;
        int start = -1;

        for (int r = 0; r < s.size(); r++) {

            mp[s[r]]--;

            if (mp[s[r]] >= 0)
                count++;

            while (count == t.size()) {

                if (r - l + 1 < minimum) {
                    minimum = r - l + 1;
                    start = l;
                }

                mp[s[l]]++;

                if (mp[s[l]] > 0)
                    count--;

                l++;
            }
        }

        return start == -1 ? "" : s.substr(start, minimum);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna