/*
You are given a sorted unique integer array nums.

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
 

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
Example 3:

Input: nums = []
Output: []
Example 4:

Input: nums = [-1]
Output: ["-1"]
Example 5:

Input: nums = [0]
Output: ["0"]
 

Constraints:

0 <= nums.length <= 20
-231 <= nums[i] <= 231 - 1
All the values of nums are unique.
nums is sorted in ascending order.
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        if(nums.size()==0)
        {
            vector<string> ans;
            return ans;
        }
        
        vector<string> ans;
        
        int start=0;
        int last=0;
        
        int i=1;
        
        while(i<nums.size())
        {
            if(nums[i-1]+1 != nums[i])
            {
                if(start==last)
                {
                    ans.push_back(to_string(nums[start]));
                }
                else
                {
                    string tmp="";
                    tmp += to_string(nums[start]);
                    tmp += "->";
                    tmp += to_string(nums[last]);
                    ans.push_back(tmp);
                }
                start=i;
                last=i;
            }
            else
            {
                last=i;
            }
            i++;
        }
        
        if(start==last)
        {
            ans.push_back(to_string(nums[start]));
        }
        else
        {
            string tmp="";
            tmp += to_string(nums[start]);
            tmp += "->";
            tmp += to_string(nums[last]);
            ans.push_back(tmp);
        }
        
        return ans;
        
    }
};
