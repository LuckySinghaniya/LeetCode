class Solution {
public:
    double helper(double x,long long p){
        if(p==0) return 1.0;
        double half=helper(x,p/2);
        if(p%2==0){
            return half*half;
        }
        else{
            return half*half*x;
        }
    }
    double myPow(double x, int n) {
        long long p=n;
        if(p<0){
            p=-p;
            x=1/x;
        }
        return helper(x,p);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna