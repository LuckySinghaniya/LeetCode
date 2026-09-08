class Solution {
public:
    int countCommas(int n) {
        int len=0;
        int temp=n;
        while(temp>0){
            len++;
            temp/=10;
        }
        if(len<=3) return 0;
        else{
            if(len==4 || len==5){
                return n-999;
            }
            else return 99999-999+1;
        }
    }
};