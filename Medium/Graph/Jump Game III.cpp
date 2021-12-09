/*
Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.
*/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size()+1, 0);
        bool ans=false;
        dfs(arr, start, vis, ans);
        return ans;
    }
    
    void dfs(vector<int> &arr, int curr, vector<int> &vis, bool &ans)
    {
        if(curr<0 || curr>=arr.size())
        {
            return;
        }
        if(arr[curr]==0)
        {
            ans=true;
            return;
        }
        
        vis[curr]=1;
        
        int left = curr-arr[curr];
        int right = curr+arr[curr];
        
        if(left>=0 && vis[left]==0)
        {
            dfs(arr, left, vis, ans);
        }
        
        if(right<arr.size() && vis[right]==0)
        {
            dfs(arr, right, vis, ans);
        }
        
        vis[curr] = 0;
    }
};
