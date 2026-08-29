// class Solution {
// public:
//     vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
//         int n = nums.size();

//         vector<int> temp = nums;
//         sort(temp.begin(), temp.end());

//         vector<queue<int>> groups;
//         unordered_map<int, int> mp;

//         int index = 0;

//         groups.push_back(queue<int>());

//         groups[index].push(temp[0]);
//         mp[temp[0]] = index;   // IMPORTANT

//         for (int i = 1; i < n; i++) {

//             if (temp[i] - temp[i - 1] <= limit) {
//                 groups[index].push(temp[i]);
//                 mp[temp[i]] = index;
//             }
//             else {
//                 index++;

//                 groups.push_back(queue<int>());

//                 groups[index].push(temp[i]);
//                 mp[temp[i]] = index;
//             }
//         }

//         vector<int> ans(n);

//         for (int i = 0; i < n; i++) {
//             int group = mp[nums[i]];

//             ans[i] = groups[group].front();
//             groups[group].pop();
//         }

//         return ans;
//     }
// };
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<pair<int,int>> v(n);

        for (int i = 0; i < n; i++) {
            v[i] = {nums[i], i};
        }

        sort(v.begin(), v.end());

        vector<int> ans(n);

        int l = 0;

        while (l < n) {

            int r = l;

            while (r + 1 < n &&
                   v[r + 1].first - v[r].first <= limit) {
                r++;
            }

            vector<int> idx;

            for (int i = l; i <= r; i++) {
                idx.push_back(v[i].second);
            }

            sort(idx.begin(), idx.end());

            for (int i = 0; i < (int)idx.size(); i++) {
                ans[idx[i]] = v[l + i].first;
            }

            l = r + 1;
        }

        return ans;
    }
};