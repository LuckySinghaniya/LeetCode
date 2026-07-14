class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<int>ans(n);
        unordered_map<int,int>mp;
        stack<int>st;
        for(int i=m-1;i>=0;i--){
            if(st.empty()){
                mp[nums2[i]]=-1;
            }
            else{
                while(!st.empty() && st.top()<nums2[i]){
                    st.pop();
                }
                if(st.empty()){
                    mp[nums2[i]]=-1;
                }
                else{
                    mp[nums2[i]]=st.top();
                }
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<n;i++){
            ans[i]=mp[nums1[i]];
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna