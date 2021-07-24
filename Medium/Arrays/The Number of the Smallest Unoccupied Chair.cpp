/*
There is a party where n friends numbered from 0 to n - 1 are attending. There is an infinite number of chairs in this party that are numbered from 0 to infinity. When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.

For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.

You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], indicating the arrival and leaving times of the ith friend respectively, and an integer targetFriend. All arrival times are distinct.

Return the chair number that the friend numbered targetFriend will sit on
*/

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        int n = times.size();
        
        int frnd_arr = times[targetFriend][0];
        
        sort(times.begin(), times.end());
        
        int idx;
        
        for(int i=0; i<n; i++)
        {
            if(times[i][0]==frnd_arr)
            {
                idx=i;
                break;
            }
        }
        
        vector<int> dep(idx+1);
        
        for(int i=0; i<=idx; i++)
        {
            dep[i]=0;
        }
        
        
        for(int i=0; i<n; i++)
        {
            int currTime = times[i][0];
            int seat;
            for(int j=0; j<=idx; j++)
            {
                if(dep[j]<=currTime)
                {
                    seat=j;
                    break;
                }
            }
            if(currTime == frnd_arr)
            {
                return seat;
            }
            else
            {
                dep[seat] = times[i][1];
            }
        }
        
        return 0;
        
    }
};
