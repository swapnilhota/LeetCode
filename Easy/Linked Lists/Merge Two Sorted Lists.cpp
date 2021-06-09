/*
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
       if(l1==NULL || l2==NULL)
       {
           if(l1==NULL)
           {
               return l2;
           }
           else
           {
               return l1;
           }
       }
        
        ListNode* ans = new ListNode();
        ListNode* tmpAns = ans;
        
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        
        while(t1 && t2)
        {
            if(t1->val < t2->val)
            {
                tmpAns->next = new ListNode(t1->val);
                t1=t1->next;
            }
            else
            {
                tmpAns->next = new ListNode(t2->val);
                t2=t2->next;
            }
            tmpAns = tmpAns->next;
        }
        
        while(t1)
        {
            tmpAns->next = new ListNode(t1->val);
            t1=t1->next;
            tmpAns=tmpAns->next;
        }
        
        while(t2)
        {
            tmpAns->next = new ListNode(t2->val);
            t2=t2->next;
            tmpAns=tmpAns->next;
        }
        
        return ans->next;
    }
};
