/*
Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.
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
    ListNode* middleNode(ListNode* head) {
        
        int n=0;
        ListNode* tmp = head;
        
        while(tmp)
        {
            n++;
            tmp=tmp->next;
        }
        
        int cnt=1;
        tmp=head;
        
        while(cnt<=n/2)
        {
            cnt++;
            tmp=tmp->next;
        }
        
        return tmp;
        
    }
};
