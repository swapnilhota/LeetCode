/*
Given an array of digit strings nums and a digit string target, return the number of pairs of indices (i, j) (where i != j) such that the concatenation of nums[i] + nums[j] equals target.
*/

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int cnt=0;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=0; j<nums.size(); j++)
            {
                if(i==j) continue;
                string temp = "";
                temp += nums[i];
                temp += nums[j];
                if(temp==target)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
