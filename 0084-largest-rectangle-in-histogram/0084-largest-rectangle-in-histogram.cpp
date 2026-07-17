class Solution {
public:
    vector<int>NSE(vector<int>& heights){
        int n=heights.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>PSE(vector<int>& heights){
        int n=heights.size();
        vector<int>pse(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nse=NSE(heights);
        vector<int>pse=PSE(heights);
        int area=INT_MIN;
        int n=heights.size();
        for(int i=0;i<n;i++){
            area=max(area,heights[i]*(nse[i]-pse[i]-1));
        }
        return area;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna