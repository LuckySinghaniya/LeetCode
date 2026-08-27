class Solution {
public:
    string ans="";
    bool solve(string &target,string &curr,vector<int>count,int i,bool greater){
        if(i==target.size()){
            if(greater){
                ans=curr;
                return true;
            }
            return false;
        }
        for(char c='a';c<='z';c++){
            if(count[c-'a']<=0) continue;
            if(greater==false && c<target[i]) continue;
            curr.push_back(c);
            count[c-'a']--;
            bool is_greater=greater||c>target[i];
            if(solve(target,curr,count,i+1,is_greater)) return true;
            curr.pop_back();
            count[c-'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
            vector<int>count(26);
            for(int i=0;i<s.size();i++){
                count[s[i]-'a']++;
            }
            string curr="";
            solve(target,curr,count,0,false);
            return ans;
    }
};