class Solution {
public:
    bool sortedNRotated(vector<int>& nums, int s, int e) {
        int count = 0;
        int size = e - s + 1;
        for(int i = s;  i < e; i++) {
            if(nums[i] > nums[i+1]) count++;
        }
        if(nums[e] > nums[s]) count++;
        return count <= 1;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
       vector<int> div;
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                div.push_back(i);
                if(i != n/i) div.push_back(n/i);
            }
            
        }

        int m = div.size();
        for(int i = 0; i < m; i++) {
           
            int k = div[i];
            int s = 0;
            int e = k - 1;
            bool flag = true;
            while(e < n) {
                if(!sortedNRotated(nums, s, e)) {
                    flag = false;
                    break;
                }
                else {
                    s += k; e += k;
                }
            }
            if(!flag) continue;
            else {
                int f1 = 0, l1 = k - 1;
                int f2 = k, l2 = 2*k - 1;
                bool sf = true;
                while(l2 < n) {
                    int maxi = *max_element(nums.begin() + f1, nums.begin() + l1 + 1);
                    int mini = *min_element(nums.begin() + f2, nums.begin() + l2 + 1);
                    if(maxi > mini) {
                        sf = false;
                        break;
                    }
                    else {
                        f1 += k; l1 += k; f2 += k; l2 += k;
                    }
                }
                if(sf) res+=k;
            }
        }
        return res;
    }
};