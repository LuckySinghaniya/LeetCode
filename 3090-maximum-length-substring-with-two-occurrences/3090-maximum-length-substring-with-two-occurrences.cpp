class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int count=0,l=0,n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
                while(mp[s[i]]>2){
                    mp[s[l]]--;
                    l++;
                    
                }
            
            count=max(count,i-l+1);
        }
        return count;
    }
};