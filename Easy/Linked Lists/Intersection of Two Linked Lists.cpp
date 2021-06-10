/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        
        map<ListNode*, int> mp;
        
        while(t1)
        {
            mp[t1]++;
            t1=t1->next;
        }
        
        while(t2)
        {
            if(mp[t2]!=0)
            {
                return t2;
            }
            t2=t2->next;
        }
        
        return NULL;
        
    }
};
