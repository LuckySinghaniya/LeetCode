class Solution {
public:
    set<string> st;

    void solve(string &s, int i, int balance,
               int leftRemove, int rightRemove,
               string curr) {

        if(balance < 0)
            return;

        if(i == s.size()) {
            if(balance == 0 && leftRemove == 0 && rightRemove == 0) {
                st.insert(curr);
            }
            return;
        }

        // Case 1: current character is '('
        if(s[i] == '(') {

            // Remove '('
            if(leftRemove > 0) {
                solve(s, i + 1, balance,
                      leftRemove - 1, rightRemove, curr);
            }

            // Keep '('
            solve(s, i + 1, balance + 1,
                  leftRemove, rightRemove, curr + '(');
        }

        // Case 2: current character is ')'
        else if(s[i] == ')') {

            // Remove ')'
            if(rightRemove > 0) {
                solve(s, i + 1, balance,
                      leftRemove, rightRemove - 1, curr);
            }

            // Keep ')' only if balance > 0
            if(balance > 0) {
                solve(s, i + 1, balance - 1,
                      leftRemove, rightRemove, curr + ')');
            }
        }

        // Case 3: letter
        else {
            solve(s, i + 1, balance,
                  leftRemove, rightRemove, curr + s[i]);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum number of '(' and ')' to remove
        for(char c : s) {

            if(c == '(') {
                leftRemove++;
            }
            else if(c == ')') {

                if(leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        string curr = "";

        solve(s, 0, 0, leftRemove, rightRemove, curr);

        return vector<string>(st.begin(), st.end());
    }
};