class Solution {
public:
    int trap(vector<int>& height) {
        int count=0;
        int n=height.size(),leftmax=0,rightmax=0;
        int left=0,right=n-1;
        while(left<right){
            if(height[left]<=height[right]){
                if(height[left]<leftmax){
                    count+=(leftmax-height[left]);
                }
                else leftmax=height[left];
                left++;
            }
            else{
                if(height[right]<rightmax){
                    count+=(rightmax-height[right]);
                }
                else rightmax=height[right];
                right--;
            }
        }
        
        return count;
    }
};