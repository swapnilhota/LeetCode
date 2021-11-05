/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        stack<vector<int>> stk;
        sort(intervals.begin(), intervals.end());
        stk.push(intervals[0]);
        int ans=0;
        for(int i=1; i<intervals.size(); i++)
        {
            int prev_start = stk.top()[0];
            int prev_end = stk.top()[1];
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];
            
            if(prev_end>curr_start)
            {
                ans++;
                stk.pop();
                vector<int> temp;
                if(prev_end<=curr_end)
                {
                    temp = {prev_start, prev_end};
                }
                else
                {
                    temp = {curr_start, curr_end};
                }
                stk.push(temp);
            }
            else
            {
                stk.push(intervals[i]);
            }
        }
        return ans;
    }
};
