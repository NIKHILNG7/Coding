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
     
        ListNode *temp1=headA;
        ListNode *temp2=headB;
        
        while(temp1!=temp2){
            
            if(temp1!=nullptr)temp1=temp1->next;
            else temp1=headA;
            
            if(temp2!=nullptr)temp2=temp2->next;
            else temp2=headB;
            
        }
        
        return temp1;
        
    }
};