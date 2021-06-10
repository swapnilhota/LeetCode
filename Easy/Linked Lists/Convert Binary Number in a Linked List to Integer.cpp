/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.
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
    int getDecimalValue(ListNode* head) {
        
        int ans=0;
        
        int n=0;
        
        ListNode* t = head;
        
        while(t)
        {
            n++;
            t=t->next;
        }
        
        n--;
        
        t=head;
        
        while(t)
        {
            ans += (1<<(n))*(t->val);
            n--;
            t=t->next;
        }
        
        return ans;
    }
};
