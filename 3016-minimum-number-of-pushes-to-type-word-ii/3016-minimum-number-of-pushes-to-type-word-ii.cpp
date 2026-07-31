class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26);
        int n=word.size();
        for(int i=0;i<n;i++){
            freq[word[i]-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<>());
        int count=0;
        int sum8=0,sum16=0,sum24=0,sum26=0;
        for(int i=0;i<26;i++){
            if(freq[i]!=0) count++;
            else break;
        }
        for(int i=0;i<26;i++){
            if(i<8) sum8+=freq[i];
            else if(i<16) sum16+=freq[i];
            else if(i<24) sum24+=freq[i];
            else sum26+=freq[i];
        }
        return sum8+2*sum16+3*sum24+4*sum26;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna