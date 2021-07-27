/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

 

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [0]
Output: 0
Example 3:

Input: nums = [2,4]
Output: 6
Example 4:

Input: nums = [8,10,2]
Output: 10
Example 5:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
 

Constraints:

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 231 - 1
*/

class Solution {
public:
    
    class trieNode {
      public:
        trieNode* left;
        trieNode* right;
    };
    
    void insert(trieNode* head, int n)
    {
        trieNode* curr = head;
        for(int i=31; i>=0; i--)
        {
            int bit = (n>>i)&1;
            if(bit==0)
            {
                if(!curr->left)
                {
                    curr->left = new trieNode();
                }
                curr=curr->left;
            }
            else
            {
                if(!curr->right)
                {
                    curr->right = new trieNode();
                }
                curr=curr->right;
            }
        }
    }
    
    int findMaxXor(trieNode* head, vector<int> &A)
    {
        int max_xor=0;
        for(auto num: A)
        {
            trieNode* curr=head;
            int curr_xor=0;
            for(int i=31; i>=0; i--)
            {
                int bit = (num>>i)&1;
                if(bit==0)
                {
                    if(curr->right)
                    {
                        curr_xor += (int)pow(2, i);
                        curr=curr->right;
                    }
                    else
                    {
                        curr=curr->left;
                    }
                }
                else
                {
                    if(curr->left)
                    {
                        curr_xor += (int)pow(2, i);
                        curr=curr->left;
                    }
                    else
                    {
                        curr=curr->right;
                    }
                }
            }
            max_xor = max(max_xor, curr_xor);
        }
        return max_xor;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        
        trieNode* head = new trieNode();
        for(auto num: nums)
        {
            insert(head, num);
        }
        
        return findMaxXor(head, nums);        
    }
};
