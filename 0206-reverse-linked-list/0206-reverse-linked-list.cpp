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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return NULL;
        ListNode * prev=NULL,*curr=head;
        ListNode* currNext=NULL;
while(curr->next!=NULL){
    currNext=curr->next;
    curr->next=prev;
    prev=curr;
    curr=currNext;
}
curr->next=prev;
prev=curr;
return prev;
    }
};