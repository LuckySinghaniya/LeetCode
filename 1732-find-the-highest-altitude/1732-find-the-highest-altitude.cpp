class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0;
        int temp=0;
        for(int i=0;i<gain.size();i++){
            temp+=gain[i];
            sum=max(sum,temp);
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna