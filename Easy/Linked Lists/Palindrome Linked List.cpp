/*
Given the head of a singly linked list, return true if it is a palindrome.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        vector<int> v;
        ListNode* tmp = head;
        
        while(tmp)
        {
            v.push_back(tmp->val);
            tmp=tmp->next;
        }
        
        if(v.size()==0)
        {
            return true;
        }
        
        int start=0;
        int end = v.size()-1;
        
        while(start<end)
        {
            if(v[start]!=v[end])
            {
                return false;
            }
            start++;
            end--;
        }
        
        return true;
        
    }
};
