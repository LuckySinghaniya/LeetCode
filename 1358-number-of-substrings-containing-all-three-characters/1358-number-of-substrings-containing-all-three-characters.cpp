class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(),count=0,left=0,ans=0;
        vector<int>freq(3);
        for(int right=0;right<n;right++){
            char ch=s[right];
            freq[ch-'a']++;
            if(freq[ch-'a']==1){
                count++;
            }
            while(count==3){ 
                ans+=n-right;
                char c=s[left];
                freq[c-'a']--;
                if(freq[c-'a']==0)count--;
                left++;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna