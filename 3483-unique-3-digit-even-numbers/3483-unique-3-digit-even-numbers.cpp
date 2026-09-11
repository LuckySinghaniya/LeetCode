class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        vector<int>freq(10);
        for(int i=0;i<n;i++){
            freq[digits[i]]++;
        }
        int ans=0;
        for(int num=100;num<=999;num++){
            if(num%2==1) continue;
            int temp=num;
            int a=temp%10;
            temp/=10;
            int b=temp%10;
            temp/=10;
            int c=temp%10;
            vector<int>count(10);
            count[a]++;
            count[b]++;
            count[c]++;
            if(freq[a]>=count[a] &&freq[b]>=count[b] &&freq[c]>=count[c]) ans++;
        }
        return ans;
    }
};