class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push(freq[i]);
            }
        }
        queue<pair<int,int>>q;
        int time=0;

        while(!q.empty()||!pq.empty()){
            time++;
            if(!pq.empty()){
                int val=pq.top();
            pq.pop();
            if(val-1!=0){
                q.push({val-1,time+n});
            }
            }
            if(!q.empty() && time==q.front().second){
                pq.push(q.front().first);
                q.pop();
            }
            
        }
        return time;
    }   
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna