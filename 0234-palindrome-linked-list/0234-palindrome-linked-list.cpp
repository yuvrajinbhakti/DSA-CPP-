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
        if(head==NULL || head->next==NULL)return true;
        ListNode* slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
slow=slow->next;
fast=fast->next->next;
        }
        
ListNode *prev=NULL;
while(slow!=NULL){
    ListNode* NextNode=slow->next;
    slow->next=prev;
    prev=slow;
    slow=NextNode;
}
ListNode* curr=head;
while(prev!=NULL){
    if(prev->val!=curr->val)return false;
curr=curr->next;
    prev=prev->next;
}
return true;
    }
};