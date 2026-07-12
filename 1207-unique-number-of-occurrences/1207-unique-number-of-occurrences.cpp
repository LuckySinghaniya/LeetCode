class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int count=0;
        vector<int>vec;
        for(int i=0;i<arr.size();i++){
            if(i==0) count++;
            else if(arr[i]==arr[i-1]) count++;
            else{
                if(find(vec.begin(), vec.end(), count)!=vec.end()){
                    return false;
                }
                vec.push_back(count);
                count=1;
            }
        }
        if(find(vec.begin(), vec.end(), count)!=vec.end()){
                    return false;
                }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna