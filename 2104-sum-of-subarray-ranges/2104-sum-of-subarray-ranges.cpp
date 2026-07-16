class Solution {
public:
    const int MOD=1e9+7;
    vector<int> NSE(vector<int>& arr){
        int n=arr.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> PSE(vector<int>& arr){
        int n=arr.size();
        vector<int>pse(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int> NGE(vector<int>& arr){
        int n=arr.size();
        vector<int>nge(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            nge[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> PGE(vector<int>& arr){
        int n=arr.size();
        vector<int>pge(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            pge[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pge;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long smallest=0,greatest=0;
        vector<int>nse=NSE(nums);
        vector<int>pse=PSE(nums);
        vector<int>nge=NGE(nums);
        vector<int>pge=PGE(nums);
        for(int i=0;i<nums.size();i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            smallest=(smallest+(right*left*1LL*nums[i]));
        }
        for(int i=0;i<nums.size();i++){
            int left=i-pge[i];
            int right=nge[i]-i;
            greatest=(greatest+(right*left*1LL*nums[i]));
        }
        return greatest-smallest;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna