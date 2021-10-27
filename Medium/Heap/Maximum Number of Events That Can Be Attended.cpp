/*
Given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. Notice that you can only attend one event at any time d.

Return the maximum number of events you can attend.
*/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans=0;
        int i=0;
        int n = events.size();
        
        for(int d=1; d<=1e5; d++)
        {
            while(!pq.empty() && pq.top()<d)
            {
                pq.pop();
            }
            
            while(i<n && events[i][0]==d)
            {
                pq.push(events[i][1]);
                i++;
            }
            
            if(!pq.empty())
            {
                pq.pop();
                ans++;
            }
        }
        
        return ans;
    }
};
