class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=intervals.size();
        int i=0,j=1;
        while(j<intervals.size()){
            if(intervals[i][0]<=intervals[j][0] && intervals[i][1]>=intervals[j][1]){
                count--;
            }
            else if(intervals[i][0]==intervals[j][0] && intervals[i][1]<intervals[j][1]){
                i=j;
                count--;
            }
            else i=j;
            j++;
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna