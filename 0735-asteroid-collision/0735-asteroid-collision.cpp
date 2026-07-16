class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int>st;
        for(int i=0;i<n;i++){
            if(st.empty()) st.push_back(asteroids[i]);
            else{
                if(asteroids[i]>0){
                    st.push_back(asteroids[i]);
                }
                else{
                    while(!st.empty() && st.back()>0 && st.back()<abs(asteroids[i])){
                        st.pop_back();
                    }
                    if(!st.empty() && st.back()==abs(asteroids[i])){
                        st.pop_back();
                    }
                    else if(st.empty()||st.back()<0){
                        st.push_back(asteroids[i]);
                    }
                }
            }
        }
        return st;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna