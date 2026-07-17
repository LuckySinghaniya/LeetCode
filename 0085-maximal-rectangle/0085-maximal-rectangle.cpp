class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix[0].size(), m=matrix.size();
        vector<vector<int>>height(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    if(matrix[i][j]=='1'){
                    height[i][j]=1;
                }
                else height[i][j]=0;
                }
                else{
                    if(matrix[i][j]=='1'){
                    height[i][j]=height[i-1][j]+1;
                }
                else height[i][j]=0;
                }
                
            }
        }
        stack<int>st;
        int area=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                while(!st.empty() && height[i][st.top()]>height[i][j]){
                int nse=j,index=st.top();
                st.pop();
                int pse=st.empty()?-1:st.top();
                area=max(area,height[i][index]*(nse-pse-1));
                }
                st.push(j
                );
            }
            while(!st.empty()){
            int nse=n,index=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            area=max(area,height[i][index]*(nse-pse-1));
        }
        }
        return area;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna