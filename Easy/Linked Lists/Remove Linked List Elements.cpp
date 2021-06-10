/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head==NULL)
        {
            return head;
        }
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        
        while(curr)
        {
            if(curr->val==val)
            {
                if(prev==NULL)
                {
                    head=head->next;
                    curr=curr->next;
                }
                else
                {
                    prev->next=curr->next;
                    curr=curr->next;
                }
            }
            else
            {
                prev=curr;
                curr=curr->next;                
            }
        }
        
        return head;
        
    }
};
