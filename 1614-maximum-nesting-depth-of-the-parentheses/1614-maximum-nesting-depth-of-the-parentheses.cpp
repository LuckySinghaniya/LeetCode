class Solution {
public:
    int maxDepth(string s) {
        int count=0,maximum=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
                maximum=max(maximum,count);
            }
            else if(s[i]==')') count--;
        }
        return maximum;
    }
};