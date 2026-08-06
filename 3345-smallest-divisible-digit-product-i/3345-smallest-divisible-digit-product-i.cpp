class Solution {
public:
    long long check(int x){
        long long prod=1;
        while(x>0){
            prod*=(x%10);
            x/=10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        int x=n;
        while(true){
            if(check(x)%t==0){
                return x;
            }
            x++;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna