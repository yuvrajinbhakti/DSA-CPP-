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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL)return NULL;
        ListNode* curr=head,*ahead=head;
        while(n>0){
            n--;
            ahead=ahead->next;
        }
        if(ahead == NULL) return head->next;        // delete head, as when n==length of linked list
        while(ahead!=NULL && ahead->next!=NULL){
            curr=curr->next;
            ahead=ahead->next;
        }
        if(curr->next!=NULL)curr->next=curr->next->next;
        return head;
    }
};