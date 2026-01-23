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
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         if(head==NULL || head->next==NULL)return NULL;
//         ListNode* curr=head,*ahead=head;
//         while(n>0){
//             n--;
//             ahead=ahead->next;
//         }
//         if(ahead == NULL) return head->next;        // delete head, as when n==length of linked list
//         while(ahead!=NULL && ahead->next!=NULL){
//             curr=curr->next;
//             ahead=ahead->next;
//         }
//         if(curr->next!=NULL)curr->next=curr->next->next;
//         return head;
//     }
// };


// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int len=0;
//         ListNode* curr=head;
//         while(curr!=NULL){
//             curr=curr->next;
//             len++;
//         }
//         ListNode* NewCurr=head;
//         int fromStart=len-n;
//         if(fromStart==0)return head->next;
//         for(int i=1;i<fromStart;i++){
//             NewCurr=NewCurr->next;
//         }
//         if(NewCurr->next==NULL)NewCurr=NULL;
//         else NewCurr->next=NewCurr->next->next;
//         return head;
//     }
// };


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start=new ListNode();
        start->next=head;
        ListNode* slow=start,*fast=start;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return start->next;
    }
};