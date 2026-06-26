#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        for (int &x : nums)
            x = (x == target ? 1 : -1);

        ordered_set<pair<int,int>> os;

        os.insert({0, -1});

        int prefix = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            prefix += nums[i];

            ans += os.order_of_key({prefix, -1});

            os.insert({prefix, i});
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna