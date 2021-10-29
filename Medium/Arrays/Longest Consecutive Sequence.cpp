/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i: nums)
        {
            mp[i]++;
        }
        
        int ans = 0;
        
        for(auto i: nums)
        {
            if(mp[i-1]==0)
            {
                int j=i;
                int cnt=0;
                while(mp[j]>0)
                {
                    cnt++;
                    j++;
                }
                ans=max(ans, cnt);
            }
        }
        
        return ans;
    }
};
