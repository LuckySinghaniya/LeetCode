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

    int sumSubarrayMins(vector<int>& arr) {
        long long sum=0;
        vector<int>nse=NSE(arr);
        vector<int>pse=PSE(arr);
        for(int i=0;i<arr.size();i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            sum=(sum+(right*left*1LL*arr[i])%MOD)%MOD;
        }
        return (int)sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna