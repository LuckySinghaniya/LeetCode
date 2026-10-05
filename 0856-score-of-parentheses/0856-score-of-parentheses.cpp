class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(0);
            }
            else{
                int temp=st.top();
                st.pop();
                int score=(temp==0)?1:2*temp;
                st.top()+=score;
            }   
        }
        return st.top();
    }
};