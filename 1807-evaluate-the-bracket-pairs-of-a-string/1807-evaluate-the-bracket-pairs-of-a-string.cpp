class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        string ans="";
        bool flag=false;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(flag){
                if(s[i]==')'){
                    if(mp.find(temp)!=mp.end()){
                        ans+=mp[temp];
                        temp="";
                        flag=false;
                    }
                    else{
                        ans+='?';
                        temp="";
                        flag=false;
                    }
                }
                else{
                    temp+=s[i];
                }
            }
            else{
                if(s[i]=='('){
                flag=true;
                }
                else{
                    ans+=s[i];
                }
            }
        }
        return ans;
    }
};