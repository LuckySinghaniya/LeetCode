class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr[0]!=1) arr[0]=1;
        for(int i=1;i<arr.size();i++){
            if(abs(arr[i]-arr[i-1])>1){
                arr[i]=arr[i-1]+1;
            }
        }
        return arr[arr.size()-1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna