class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        vector<queue<int>>groups;
        unordered_map<int,int>mp;
        int index=0;
         groups.push_back(queue<int>());
        groups[index].push(temp[0]);
        for(int i=1;i<n;i++){
            if(temp[i]-temp[i-1]<=limit){
                groups[index].push(temp[i]);
                mp[temp[i]]=index;
            }
            else{
                groups.push_back(queue<int>());
                 index++;
                groups[index].push(temp[i]);
               
                mp[temp[i]]=index;
            }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=groups[mp[nums[i]]].front();
            groups[mp[nums[i]]].pop();
        }
        return ans;
    }
};