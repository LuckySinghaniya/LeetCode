class Solution {
public:
    int trap(vector<int>& height) {
        int count=0;
        int n=height.size();
        vector<int>premax(n);
        vector<int>sufmax(n);
        premax[0]=height[0];
        sufmax[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            premax[i]=max(premax[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            sufmax[i]=max(sufmax[i+1],height[i]);
        }
        for(int i=0;i<n;i++){
            if(height[i]<premax[i] && height[i]<sufmax[i]){
                int diff=min(premax[i],sufmax[i]);
                count+=(diff-height[i]);
            }
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna