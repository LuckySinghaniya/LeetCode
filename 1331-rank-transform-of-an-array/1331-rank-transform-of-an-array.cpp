class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0) return {};
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        int count=1;
    unordered_map<int,int>mp;
    mp[temp[0]]=1;
    count++;
    for(int i=0;i<arr.size();i++){
        if(i>0 && temp[i]!=temp[i-1]) {
            mp[temp[i]]=count;
            count++;
        }
        else continue;
        
    }
    for(int i=0;i<arr.size();i++){
        arr[i]=mp[arr[i]];
    }
    return arr;
    }
    
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna