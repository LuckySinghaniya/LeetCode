class Solution {
public:
    int climbStairs(int n) {
        int prev2=1;
        int prev1=1;
        for(int i=1;i<n;i++){
            int curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }   
        return prev1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna