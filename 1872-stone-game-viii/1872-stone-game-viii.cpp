class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int>presum(n-1);
        int temp=stones[0];
        for(int i=1;i<n;i++){
            temp+=stones[i];
            presum[i-1]=temp;
        }
        int ans=presum[n-2];
        for(int i=n-3;i>=0;i--){
            ans=max(ans,presum[i]-ans);
        }
        return ans;
    }
};