class Solution {
public:
const int INT_MIN_VAL = -2147483648;
const int INT_MAX_VAL = 2147483647;
    int helper(string s,int i,long long num,int sign){
        if(i>=s.size() || !isdigit(s[i])) return (int)(sign*num);
        num=num*10 + (s[i]-'0');
        if(sign*num<=INT_MIN_VAL) return INT_MIN_VAL;
        if(sign*num>=INT_MAX_VAL) return INT_MAX_VAL;
        return helper(s,i+1,num,sign);
    }
    int myAtoi(string s) {
        int n=s.size();
        int i=0,sign=1;
        while(i<n && (s[i]==' '|| s[i]=='_')){
            i++;
        }
        if(s[i]=='+'){
            sign=1;
            i++;
        }
        else if(s[i]=='-'){
            sign=-1;
            i++;
    }
    return helper(s,i,0,sign);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna