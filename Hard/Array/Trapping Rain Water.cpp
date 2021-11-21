/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int min_h;
        int n = height.size();
        vector<int> max_h(n);
        max_h[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--)
        {
            max_h[i] = max(max_h[i+1], height[i]);
        }
        int ans = 0;
        min_h=height[0];
        for(int i=1; i<n-1; i++)
        {
            if(height[i]>min_h)
            {
                min_h=height[i];
            }
            if(min_h<=max_h[i+1])
            {
                ans += min_h -  height[i];
            }
            else
            {
                min_h = max_h[i+1];
                ans += max(0, min_h - height[i]);
            }
        }
        return ans;
    }
};
