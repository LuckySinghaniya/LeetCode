class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>temp(n);
        temp[0]=1;
        int count=1;
        for(int i=1;i<n;i++){
            
            if(ratings[i]<=ratings[i-1]){
                temp[i]=1;
                count=1;
            }
            else{
                count++;
                temp[i]=count;
            }
        }
        int sum=temp[n-1];
        count=1;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                count++;
                sum+=max(count,temp[i]);
            }
            else{
                count=1;
                sum+=max(count,temp[i]);
            }
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna