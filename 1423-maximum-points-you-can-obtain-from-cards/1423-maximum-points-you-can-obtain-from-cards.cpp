class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int l=0,r=n-k,sum=0,ans=0;
        for(int i=n-k;i<n;i++){
            sum+=cardPoints[i];
        }
        ans=sum;
        while(r<n){
            ans-=cardPoints[r];
            ans+=cardPoints[l];
            sum=max(sum,ans);
            l++;
            r++;
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna