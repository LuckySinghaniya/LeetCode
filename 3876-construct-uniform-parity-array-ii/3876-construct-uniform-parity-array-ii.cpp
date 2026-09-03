class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool flag1=false,flag2=false;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==1) flag1=true;
            if(nums1[i]%2==0) flag2=true;
        }
        if(!flag1 && flag2 || flag1 && !flag2) return true;
        int miniodd=INT_MAX;
        int minieven=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==1) miniodd=min(miniodd,nums1[i]);
            else minieven=min(minieven,nums1[i]);
        }
        return minieven-miniodd>=1;
        
    }
};