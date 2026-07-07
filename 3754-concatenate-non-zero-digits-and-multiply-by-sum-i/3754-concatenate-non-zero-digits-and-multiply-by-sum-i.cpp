class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans=0;
        int x=n;
        long long sum=0;
        while(x>0){
            int temp=x%10;
            sum+=temp;
            if(temp!=0) ans=(ans*10 + temp);
            x/=10;
        }
        x=ans;
        ans=0;
        while(x>0){
            int temp=x%10;
            ans=(ans*10 + temp);
            x/=10;
        }


        return ans*sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna