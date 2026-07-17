class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            while(!st.empty()&&  heights[st.top()]>heights[i]){
                int nse=i,index=st.top();
                st.pop();
                int pse=st.empty()?-1:st.top();
                area=max(area,heights[index]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse=n,index=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            area=max(area,heights[index]*(nse-pse-1));
        }
        return area;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna