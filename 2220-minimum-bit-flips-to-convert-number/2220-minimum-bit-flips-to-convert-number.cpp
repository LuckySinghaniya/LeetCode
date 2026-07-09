class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num=start^goal;
        int count=0;
        while((num & (num-1))!=0){
            count++;
            num=num&(num-1);
        }
        if(num>0) count++;
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna