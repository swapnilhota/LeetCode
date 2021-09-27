/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
 

Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int pivot=-1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>=0)
            {
                pivot=i;
                break;
            }
        }
        if(pivot==-1) pivot=nums.size()-1;
        int i=pivot-1;
        int j=pivot;
        //cout<<pivot<<endl;
        for(int k=0; k<nums.size(); k++)
        {
            nums[k] = abs(nums[k]);
        }
        vector<int> ans;
        while(i>=0 && j<nums.size())
        {
            if(abs(nums[i])<abs(nums[j]))
            {
                ans.push_back(abs(nums[i])*abs(nums[i]));
                i--;
            }
            else
            {
                ans.push_back(abs(nums[j])*abs(nums[j]));
                j++;
            }
        }
        while(i>=0)
        {
            ans.push_back(abs(nums[i])*abs(nums[i]));
            i--;
        }
        while(j<nums.size())
        {
            ans.push_back(abs(nums[j])*abs(nums[j]));
            j++;
        }
        return ans;
    }
};
