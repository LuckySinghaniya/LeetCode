class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        vector<int>freq(26);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        string left="",mid="",right="";
        for (int i=0;i<26;i++) {
            left+=string(freq[i]/2,char('a'+i));
            if(freq[i]%2){
                mid=char('a'+i);
            }    
    }
    right=left;
    reverse(right.begin(),right.end());
    return left+mid+right;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna