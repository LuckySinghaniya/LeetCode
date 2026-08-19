class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> mp;

        for (auto &x : reservedSeats) {
            int row = x[0];
            int seat = x[1];

            mp[row] |= (1 << (10 - seat));
        }

        int left   = 0b0111100000; // 2-5
        int middle = 0b0001111000; // 4-7
        int right  = 0b0000011110; // 6-9

        int ans = (n - mp.size()) * 2;

        for (auto &[row, reserved] : mp) {

            bool L = (reserved & left) == 0;
            bool M = (reserved & middle) == 0;
            bool R = (reserved & right) == 0;

            if (L && R) {
                // Put two groups: left and right
                ans += 2;
            }
            else if (L || M || R) {
                // At least one group can be placed
                ans += 1;
            }
        }

        return ans;
    }
};